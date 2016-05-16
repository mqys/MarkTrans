
//
// Created by pengnan on 16/5/13.
//


#include "Scanner.h"
#include "Elements.h"


TYPE Element::getType() {
    return TYPE::TEXT;
}

Header::Header(Scanner &scan, std::ostream &out): Element(scan, out), m_level(0) {
    auto& s = m_scan.getLine();
    int i;
    for (i = 0; i < s.size() && s[i] == '#'; ++i, ++m_level);
    m_headerName = s.substr(i + 1);
    m_scan.consume();
}

void Header::write() {
    m_out << "<h" << m_level;
    m_out << '>' << m_headerName;
    m_out << "</h" << m_level << '>';
}


Blockquote::Blockquote(Scanner &scan, std::ostream &out) : Element(scan, out){
    do {
        m_quote += m_scan.getLine().substr(2) + '\n';
        m_scan.consume();
    } while(!m_scan.isEnd() && m_scan.getOuterType() == TYPE::BLOCKQUOTE);

}
void Blockquote::write() {
    m_out << "<blockquote><p>" << m_quote << "</p></blockquote>";
}


Code::Code(Scanner &scan, std::ostream &out) : Element(scan, out){
    m_scan.consume();
    while (!m_scan.isEnd() &&  m_scan.getOuterType() != TYPE::CODE) {
        m_code += m_scan.getLine() + '\n';
        m_scan.consume();
    }
    scan.consume();
}
void Code::write() {
    // TODO: need to transfer symbols
    m_out << "<pre><code>\n";
    m_out << m_code;
    m_out << "</code></pre>\n";
}

Table::Table(Scanner &scan, std::ostream &out) : Element(scan, out){
    while (!m_scan.isEnd() && m_scan.getOuterType() == TYPE::TABLE) {
        auto& s = m_scan.getLine();

        std::regex split("(\\|\\s*-+\\s*)+\\|");
        if (std::regex_match(m_scan.getLine(), split)) {
            m_scan.consume();
            continue;
        }
        std::vector<std::string> line;
        std::string word;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '|') {
                line.push_back(word);
                word = "";
                continue;
            }
            if (s[i] == ' ' || s[i] == '\t')
                continue;
            word.push_back(s[i]);
        }
        m_rows.push_back(line);
        m_scan.consume();
    }
}
void Table::write() {
    m_out << "<table border=\"1\">\n<thead>\n<tr>";
    auto& thead = m_rows[0];
    for (std::string& s : thead) {
        m_out << "<th>";
        m_out << s;
        m_out << "</th>";
    }
    m_out << "</tr></thead>\n<tbody>";
    for (int i = 1; i < m_rows.size(); ++i) {
        m_out << "<tr>";
        auto& row = m_rows[i];
        for (auto& s : row) {
            m_out << "<td>";
            m_out << s;
            m_out << "</td>";
        }
        m_out << "</tr>";
    }
    m_out << "</tbody></table>\n";
}


Outer_link::Outer_link(Scanner &scan, std::ostream &out) : Element(scan, out){
    auto& s = m_scan.getLine();
    auto nl = s.find('[');
    auto nr = s.find(']');
    m_name = s.substr(nl+1, nr-nl-1);
    auto al = s.find('(');
    auto ar = s.find(')');
    m_addr = s.substr(al+1, ar-al-1);
    m_scan.consume();
}

void Outer_link::write() {
    m_out << "<p><a href='" << m_addr << "'>";
    m_out << m_name << "</a></p>";
}

Outer_barelink::Outer_barelink(Scanner &scan, std::ostream &out) : Element(scan, out){
    auto& s = m_scan.getLine();
    m_link = s.substr(1, s.size()-2);
    m_scan.consume();
}
void Outer_barelink::write() {
    m_out << "<p><a href='" << m_link << "'>";
    m_out << m_link << "</a></p>";
}


Outer_image::Outer_image(Scanner &scan, std::ostream &out) : Element(scan, out) {
    auto& s = m_scan.getLine();
    auto nl = s.find('[');
    auto nr = s.find(']');
    m_name = s.substr(nl+1, nr-nl-1);
    auto al = s.find('(');
    auto ar = s.find(')');
    m_addr = s.substr(al+1, ar-al-1);
    m_scan.consume();
}

void Outer_image::write() {
    m_out << "<p><img src='" << m_addr << "' alt='";
    m_out << m_name << "' /></p>";
}

void Text::write() {
    // TODO: add element trans, rich text
    m_out << m_text;
}


Paragraph::Paragraph(Scanner &scan, std::ostream &out) : Element(scan, out) {
    while (!m_scan.isEnd() && m_scan.getOuterType() == TYPE::TEXT) {
        m_arr.push_back(std::make_shared<Text>(m_scan, m_out, m_scan.getLine()));
        m_scan.consume();
    }
}

void Paragraph::write() {
    m_out << "<p>";
    for (auto& t : m_arr) {
        t->write();
        m_out << std::endl;
    }
    m_out << "</p>";
}

Unordered_list::Unordered_list(Scanner& scan, std::ostream& out, int indent) : Element(scan, out) {
    while (!m_scan.isEnd() && (m_scan.getOuterType() == TYPE::UNORDERED_LIST || m_scan.getOuterType() == TYPE::ORDERED_LIST)) {

        auto& str = m_scan.getLine();
        int thisIndent = 0;
        while(thisIndent < str.size() && (str[thisIndent] == ' ' || str[thisIndent] == '\t'))
            ++thisIndent;
        m_indent = thisIndent;

        // go back, this object remain empty in the child list
        if (m_indent < indent)
            return;
        // find child list
        if (m_indent > indent) {
            // unordered child list
            if (m_scan.getOuterType() == TYPE::UNORDERED_LIST)
                m_list.push_back(std::make_shared<Unordered_list>(m_scan, m_out, m_indent));
            else // ordered child list
                m_list.push_back(std::make_shared<Ordered_list>(m_scan, m_out, m_indent));

            continue;
        }

        m_list.push_back(std::make_shared<Text>(m_scan, m_out, str.substr(m_indent+2, str.size()-m_indent-2)));
        m_scan.consume();
    }
}
void Unordered_list::write() {
    m_out << "<p><ul>";
    for (auto& i : m_list) {
        if (i->getType() == TYPE::TEXT)
            m_out << "<li>";
        i->write();
        if (i->getType() == TYPE::TEXT)
            m_out << "</li>";
    }
    m_out << "</ul></p>";
}
TYPE Unordered_list::getType() {
    return TYPE::UNORDERED_LIST;
}


Ordered_list::Ordered_list(Scanner& scan, std::ostream& out, int indent) : Element(scan, out) {
    while (!m_scan.isEnd() && (m_scan.getOuterType() == TYPE::UNORDERED_LIST || m_scan.getOuterType() == TYPE::ORDERED_LIST)) {

        auto& str = m_scan.getLine();
        int thisIndent = 0;
        while(thisIndent < str.size() && (str[thisIndent] == ' ' || str[thisIndent] == '\t'))
            ++thisIndent;
        m_indent = thisIndent;

        // go back, this object remain empty in the child list
        if (m_indent < indent)
            return;
        // find child list
        if (m_indent > indent) {
            // unordered child list
            if (m_scan.getOuterType() == TYPE::UNORDERED_LIST)
                m_list.push_back(std::make_shared<Unordered_list>(m_scan, m_out, m_indent));
            else // ordered child list
                m_list.push_back(std::make_shared<Ordered_list>(m_scan, m_out, m_indent));

            continue;
        }

        m_list.push_back(std::make_shared<Text>(m_scan, m_out, str.substr(m_indent+2, str.size()-m_indent-2)));
        m_scan.consume();
    }
}
void Ordered_list::write() {
    m_out << "<p><ol>";
    for (auto& i : m_list) {
        if (i->getType() == TYPE::TEXT)
            m_out << "<li>";
        i->write();
        if (i->getType() == TYPE::TEXT)
            m_out << "</li>";
    }
    m_out << "</ol></p>";
}
TYPE Ordered_list::getType() {
    return TYPE::ORDERED_LIST;
}
