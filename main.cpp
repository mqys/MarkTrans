#include <iostream>
#include <regex>
#include "Scanner.h"
#include "Document.h"


using namespace std;


int main() {

    std::cout << "=====main=====" << std::endl;

//    Scanner scanner("~/Desktop/MarkTrans/README.md");
//    scanner.getType();


//    Scanner s("./README.md");
//    std::string str;
//    int count = 300;
//    while (count--) {
//
//        std::string& ss = s.getLine();
////        if (regex_match(ss, r))
//        if (regex_match(ss, TYPE_REGEX::HEADER))
//            std::cout << (299 - count)<< "=->" << ss << std::endl;
//        if (!s.consume())
//            break;
//    }

    Document d("README.md");
    d.writeToFile();

    std::cout << "=====end=====" << std::endl;
    return 0;
}

