#include <iostream>
#include <regex>
#include "Scanner.h"
#include "Document.h"

using namespace std;

int main(int argc, char** args) {

    std::cout << "=====main=====" << std::endl;

//    std::smatch res;
////    std::string input = "- [Algorithms](./algorithms.md) \"Algorithms(4th)\"";
////    std::string input = "haha <kkkkkk> afehuh";
////    std::string input = "- ![haha](addr) aeahfuegau\"hhh\"";
////    std::string input = "ha`java`ha**jafieji** jfaihe";
//    std::string input = "haha <jfiaefiah>  <hahaha, haha> <哈哈>";
//
//    // if (std::regex_search(input, res, TYPE_REGEX::LINK)) {
//    if (std::regex_search(input.cbegin()+18, input.cend(), res, TYPE_REGEX::BARE_LINK)) {
////        auto it = res[0].first;
////        it += res.length();
//        auto it = res[0].second;
////        std::cout << res.empty() << std::endl;
////        std::cout << res.size() << std::endl;
////        std::cout << res[0].matched << std::endl;
//        std::cout << res.length() << std::endl;
//        // std::cout << *res[0].first << std::endl;
//        // std::cout << *(res[0].second) << std::endl;
//        // for (auto& i : res)
//        //     std::cout << i << std::endl;
//        std::cout << std::string(it, input.cend()) << std::endl;
//    }


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

