//
// Created by pengnan on 16/5/7.
//

#ifndef MARKTRANS_TYPES_H
#define MARKTRANS_TYPES_H

enum class TYPE {
    EMPTY,
    TEXT,
    HEADER,
    UNORDERED_LIST,
    ORDERED_LIST,
    LINK,
    BARE_LINK,
    IMAGE,
    CODE,
    PARAGRAPH,
    TABLE,
    BLOCKQUOTE,
    HORIZONTAL
};


class TYPE_REGEX {
public:

    static const std::string EMPTY;
    static const std::string TEXT;
    static const std::string HEADER;
    static const std::string UNORDERED_LIST;
    static const std::string ORDERED_LIST;
    static const std::string LINK;
    static const std::string BARE_LINK;
    static const std::string IMAGE;
    static const std::string BLOCKQUOTE;
    static const std::string HORIZONTAL;
    static const std::string CODE;
    static const std::string PARAGRAPH;
    static const std::string TABLE;

};

#endif //MARKTRANS_TYPES_H
