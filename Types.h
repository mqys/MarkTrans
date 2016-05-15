//
// Created by pengnan on 16/5/7.
//

#ifndef MARKTRANS_TYPES_H
#define MARKTRANS_TYPES_H

#include <regex>

enum class TYPE {
    // outer type
    EMPTY,
    HEADER,
    UNORDERED_LIST,
    ORDERED_LIST,
    CODE,
    TABLE,
    BLOCKQUOTE,
    HORIZONTAL,
//    PARAGRAPH,
    // can be inner type
    TEXT,
    LINK,
    BARE_LINK,
    IMAGE
};


class TYPE_REGEX {
public:

    static const std::regex EMPTY;
    static const std::regex TEXT;
    static const std::regex HEADER;
    static const std::regex UNORDERED_LIST;
    static const std::regex ORDERED_LIST;
    static const std::regex LINK;
    static const std::regex BARE_LINK;
    static const std::regex IMAGE;
    static const std::regex BLOCKQUOTE;
    static const std::regex HORIZONTAL;
    static const std::regex CODE;
//    static const std::regex PARAGRAPH;
    static const std::regex TABLE;

    
};

#endif //MARKTRANS_TYPES_H
