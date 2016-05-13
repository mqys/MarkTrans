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
    Scanner(std::string filename) : m_in(filename) {}

    std::string& getLine() {
        return m_line;
    }
    bool consume() {
        return (bool)getline(m_in, m_line);
    }
    TYPE getType();

private:
    std::ifstream m_in;
    std::string m_line;

};


#endif //MARKTRANS_SCANNER_H
