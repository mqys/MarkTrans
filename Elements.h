//
// Created by pengnan on 16/5/7.
//

#ifndef MARKTRANS_ELEMENT_H
#define MARKTRANS_ELEMENT_H

#include <iosfwd>
#include <fstream>
#include "Scanner.h"

/*
 *  Element is the abstract base class for all elements
 *  derived elements need to implement the trans function
 *  to write html to out
 * */
class Element {
public:
    Element(Scanner& scan, std::ofstream out) : m_scanner(scan), m_out(out) {}

    virtual void trans() = 0;

protected:
    Scanner& m_scanner;
    std::ofstream& m_out;
};


#endif //MARKTRANS_ELEMENT_H
