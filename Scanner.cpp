//
// Created by pengnan on 16/5/5.
//

#include "Scanner.h"

TYPE Scanner::getOuterType() {
    // analyse current line and return its type

    if (std::regex_match(m_line, TYPE_REGEX::EMPTY))
        return TYPE::EMPTY;

    // outer type first
    if (std::regex_match(m_line, TYPE_REGEX::HEADER))
        return TYPE::HEADER;
    else if (std::regex_match(m_line, TYPE_REGEX::UNORDERED_LIST))
        return TYPE::UNORDERED_LIST;
    else if (std::regex_match(m_line, TYPE_REGEX::ORDERED_LIST))
        return TYPE::ORDERED_LIST;
    else if (std::regex_match(m_line, TYPE_REGEX::BLOCKQUOTE))
        return TYPE::BLOCKQUOTE;
    else if (std::regex_match(m_line, TYPE_REGEX::HORIZONTAL))
        return TYPE::HORIZONTAL;
    else if (std::regex_match(m_line, TYPE_REGEX::TABLE))
        return TYPE::TABLE;
    else if (std::regex_match(m_line, TYPE_REGEX::CODE))
        return TYPE::CODE;

        // match inner type, no need, just return TEXT
//    else if (std::regex_match(m_line, TYPE_REGEX::LINK))
//        return TYPE::LINK;
//    else if (std::regex_match(m_line, TYPE_REGEX::BARE_LINK))
//        return TYPE::BARE_LINK;
//    else if (std::regex_match(m_line, TYPE_REGEX::IMAGE))
//        return TYPE::IMAGE;

    return TYPE::TEXT;
}

bool Scanner::getInnerType(const std::string::const_iterator& begin, const std::string::const_iterator& end, const std::regex& reg) {

    return std::regex_search(begin, end, m_matchRes, reg);

}