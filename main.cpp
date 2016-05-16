#include <iostream>
#include <regex>
#include "Scanner.h"
#include "Document.h"


using namespace std;


int main(int argc, char** args) {

    std::cout << "=====main=====" << std::endl;

//    Scanner scanner("~/Desktop/MarkTrans/TEST.md");
//    scanner.getType();


//    Scanner s("./TEST.md");
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
//    std::string file;
//    if (argc == 2)
//        file = args[1];
//    Document d(file);
//    d.writeToFile();

    Document d("TEST.md");
    d.writeToFile();
    std::cout << "=====end=====" << std::endl;
    return 0;
}

