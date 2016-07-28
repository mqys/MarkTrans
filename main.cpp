#include <iostream>
#include <regex>
#include <sstream>
#include "Scanner.h"
#include "Document.h"

using namespace std;

void help() {
    cout << "usage: ./MarkTrans [-f] inputFileName\n\t -f: write result to file\n\t default: write result to console";
}

int main(int argc, char** args) {

//    std::cout << "=====main=====" << std::endl;

    string filename;
    if (argc == 2) {
        filename = args[1];
        cout << filename << endl;
        Document d(filename);
        if (d.good())
            d.writeToStdout();
        return 0;
    }

    if (argc == 3) {
        if (strcmp(args[1], "-f") == 0) {
            filename = args[2];
            cout << filename << endl;
            Document d(filename);
            if (d.good())
                d.writeToFile();
            return 0;
        }
        help();
        return 0;
    }

    help();

//    std::cout << "=====end=====" << std::endl;
    return 0;
}

