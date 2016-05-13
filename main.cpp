#include <iostream>
#include <regex>
#include "Scanner.h"


using namespace std;


int main() {

    std::cout << "=====main=====" << std::endl;

//    Scanner scanner("~/Desktop/MarkTrans/README.md");
//    scanner.getType();

    std::regex r(TYPE_REGEX::TABLE);
    std::smatch res;
//    std::string s = "aaaabcb";
//    std::cout << regex_search(s, res, r) << std::endl;

    Scanner s("./README.md");
    std::string str;
    int count = 300;
    while (count--) {

        std::string& ss = s.getLine();
        if (regex_match(ss, r))
            std::cout << (299 - count)<< "=->" << ss << std::endl;
        if (!s.consume())
            break;
    }


    std::cout << "=====end=====" << std::endl;
    return 0;
}

