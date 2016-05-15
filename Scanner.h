//
// Created by pengnan on 16/5/5.
//

#ifndef MARKTRANS_SCANNER_H
#define MARKTRANS_SCANNER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Types.h"

class Scanner {
public:
    Scanner(std::string filename) : m_in(filename), m_isEnd(false){}

    std::string& getLine() {
        return m_line;
    }
    bool consume() {
        if (getline(m_in, m_line))
            return true;
        m_isEnd = true;
        return false;
    }
    bool isEnd() {
        return  m_isEnd;
    }
    TYPE getOuterType();
    TYPE getInnerType();

private:
    std::ifstream m_in;
    std::string m_line;
    bool m_isEnd;
};


#endif //MARKTRANS_SCANNER_H
