//
// Created by pengnan on 16/5/7.
//


#include <iostream>
#include "../Scanner.h"


using namespace std;

int main() {

    std::cout << "====TEST====" << std::endl;
    Scanner s("../README.md");
    std::string str;
    int count = 30;
    while (count-- ) {
        std::string& ss = s.getCurrentLine();
        if (!ss.empty())
            std::cout << "===" << ss << std::endl;
        s.consume();
    }

    return 0;
}