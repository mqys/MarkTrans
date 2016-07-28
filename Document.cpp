//
// Created by pengnan on 16/5/5.
//

#include "Document.h"

const std::string Document::HTML_START = "<html>\n<head><meta charset=\"UTF-8\"><title>";
const std::string Document::HTML_TITLE = "</title></head>\n<body>";
const std::string Document::HTML_END = "\n</body></html>";
const std::string Document::HTML_AD = "<hr /><footer><p>Translated by MarkTrans (mqys)</p><p><a href=\"https://github.com/mqys\">mqys Github</a></p></footer>";

Document::Document(std::string filename) : m_out(""), m_scan(filename), m_isTransed(false), m_isOutToString(false), m_isGood(false) {

    m_isGood = m_scan.good();
    auto pos = filename.rfind('.');
    m_barename = filename.substr(0, pos);
}


bool Document::good() {
    return m_isGood;
}

void Document::outToString() {
    m_out += HTML_START + m_barename + HTML_TITLE;

    // write body here
    for (auto& t: m_list)
        t->write();

    m_out += HTML_AD + HTML_END;
}


void Document::writeToFile(std::string anothername) {

    if (!m_isGood)
        return;

    std::ofstream outfile;

    if (!anothername.empty())
        outfile.open(anothername);
    else {
        std::string outname = m_barename + ".html";
        outfile.open(outname);
    }
    if (!m_isTransed)
        trans();
    if (!m_isOutToString)
        outToString();

    outfile << m_out.c_str();
}


void Document::writeToStdout() {

    if (!m_isGood)
        return;
    if (!m_isTransed)
        trans();
    if (!m_isOutToString)
        outToString();

    std::cout << m_out << std::endl;
}


void Document::trans() {
    while (!m_scan.isEnd()) {
        auto linetype = m_scan.getOuterType();
        switch (linetype) {
            // outer type
            case TYPE::EMPTY:
                m_scan.consume();
                break;
            case TYPE::HEADER:
                m_list.push_back(std::make_shared<Header>(m_scan, m_out));
                break;
            case TYPE::HORIZONTAL:
                m_list.push_back(std::make_shared<Horizontal>(m_scan, m_out));
                break;
            case TYPE::BLOCKQUOTE:
                m_list.push_back(std::make_shared<Blockquote>(m_scan, m_out));
                break;
            case TYPE::CODE:
                m_list.push_back(std::make_shared<Code>(m_scan, m_out));
                break;
            case TYPE::TABLE:
                m_list.push_back(std::make_shared<Table>(m_scan, m_out));
                break;
            case TYPE::UNORDERED_LIST:
                m_list.push_back(std::make_shared<Unordered_list>(m_scan, m_out));
                break;
            case TYPE::ORDERED_LIST:
                m_list.push_back(std::make_shared<Ordered_list>(m_scan, m_out));
                break;

             // inner type, should be included in the TEXT
//            case TYPE::LINK:
//                m_list.push_back(std::make_shared<Outer_link>(m_scan, m_out));
//                break;
//            case TYPE::IMAGE:
//                m_list.push_back(std::make_shared<Outer_image>(m_scan, m_out));
//                break;
//            case TYPE::BARE_LINK:
//                m_list.push_back(std::make_shared<Outer_barelink>(m_scan, m_out));
//                break;

//            case TYPE::TEXT:
            default:
                m_list.push_back(std::make_shared<Paragraph>(m_scan, m_out));
                break;
        }
    }

    m_isTransed = true;
}

