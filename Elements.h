//
// Created by pengnan on 16/5/7.
//

#ifndef MARKTRANS_ELEMENT_H
#define MARKTRANS_ELEMENT_H

#include <iosfwd>
#include "Scanner.h"

/*
 *  Element is the abstract base class for all elements
 *  derived elements need to implement trans && write
// *  func trans: read in string, put into self structure
 *  trans inside the cons of element, not the trans func
 *  func write: write info the out stream
 * */
class Element {
public:
    Element(Scanner& scan, std::string& out) : m_scan(scan), m_out(out) {}

//    virtual void trans() = 0;
    virtual void write() = 0;
    virtual TYPE getType();
protected:
    Scanner& m_scan;
    std::string& m_out;
};


// rich text, can contain Links, Emphasis, Code, Image...
class RichText : public Element {
public:
    RichText(Scanner& scan, std::string& out, std::string text = "");
    virtual void write() override;
    void setText(std::string str) {
        m_text = str;
    }

private:
    std::string m_text;
};

// Outer elements
class Header: public Element {
public:
    Header(Scanner& scan, std::string& out);
    virtual void write() override;

private:
    std::string m_headerName;
    int m_level;
};

class Horizontal : public Element {
public:
    Horizontal(Scanner& scan, std::string& out) : Element(scan, out) {
        m_scan.consume();
    }

    virtual void write() override {
        m_out += "<hr />\n";
    }
};

class Blockquote : public Element {
public:
    Blockquote(Scanner& scan, std::string& out);
    virtual void write() override;

private:
    std::string m_quote;
};

class Code : public Element {
public:
    Code(Scanner& scan, std::string& out);
    virtual void write() override;

private:
    std::string m_code;
};

class Table : public Element {
public:
    Table(Scanner& scan, std::string& out);
    virtual void write() override;

private:
    std::vector<std::vector<std::string>> m_rows;
};

//class Outer_link : public Element {
//public:
//    Outer_link(Scanner& scan, std::string& out);
//    virtual void write() override;
//
//private:
//    std::string m_name;
//    std::string m_addr;
//};
//
//class Outer_barelink : public Element {
//public:
//    Outer_barelink(Scanner& scan, std::string& out);
//    virtual void write() override;
//
//private:
//    std::string m_link;
//};
//
//class Outer_image : public Element {
//public:
//    Outer_image(Scanner& scan, std::string& out);
//    virtual void write() override;
//
//private:
//    std::string m_name;
//    std::string m_addr;
//};

class Paragraph : public Element {
public:
    Paragraph(Scanner& scan, std::string& out);
    virtual void write() override;

private:
    std::vector<std::shared_ptr<RichText>> m_arr;
};


class Unordered_list : public Element {
public:
    Unordered_list(Scanner& scan, std::string& out, int indent = 0);
    virtual void write() override;
    virtual TYPE getType() override;
private:
    std::vector<std::shared_ptr<Element>> m_list;
    int m_indent;
};

class Ordered_list : public Element {
public:
    Ordered_list(Scanner& scan, std::string& out, int indent = 0);
    virtual void write() override;
    virtual TYPE getType() override;
private:
    std::vector<std::shared_ptr<Element>> m_list;
    int m_indent;
};
#endif //MARKTRANS_ELEMENT_H
