#include <iostream>
#include <regex>
#include <sstream>
#include "Scanner.h"
#include "Document.h"

using namespace std;

int main(int argc, char** args) {

    std::cout << "=====main=====" << std::endl;

//    Document d("TEST.md");
//    d.writeToFile();


    stringstream s;
    stringstream& ss = s;

    ss << "haha";
    ss << "\n hhehe\n";

    string string1("hello");

    ss << string1;

    cout << s.str() << endl;

    std::cout << "=====end=====" << std::endl;
    return 0;
}

