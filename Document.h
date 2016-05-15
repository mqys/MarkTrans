//
// Created by pengnan on 16/5/5.
//

#ifndef MARKTRANS_DOCUMENT_H
#define MARKTRANS_DOCUMENT_H


#include <string>
#include "Scanner.h"
#include "Elements.h"

class Document {
public:
    Document(std::string filename);

    void trans();
    void writeToFile(std::string anothername = "");
private:
    Scanner m_scan;
    std::ofstream m_out;
    bool m_isTransed;
    std::string m_barename;
    std::vector<std::shared_ptr<Element>> m_list;

    static const std::string HTML_START;
    static const std::string HTML_TITLE;
    static const std::string HTML_AD;
    static const std::string HTML_END;
};


#endif //MARKTRANS_DOCUMENT_H
