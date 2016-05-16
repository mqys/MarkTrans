//
// Created by pengnan on 16/5/13.
//

#include <string>
#include "Types.h"


const std::regex TYPE_REGEX::EMPTY("");
const std::regex TYPE_REGEX::HEADER("^#+ .+");
const std::regex TYPE_REGEX::UNORDERED_LIST("\\s*[-*+] .+");
const std::regex TYPE_REGEX::ORDERED_LIST("\\s*\\d\\. .+");
const std::regex TYPE_REGEX::BLOCKQUOTE("> .+");
const std::regex TYPE_REGEX::HORIZONTAL("-{3,}");
const std::regex TYPE_REGEX::CODE("`{3}.*");
const std::regex TYPE_REGEX::TABLE("(\\|.+)+\\|");

const std::regex TYPE_REGEX::LINK("[^!]*\\[.+]\\(.+)");
const std::regex TYPE_REGEX::BARE_LINK("^\\s*<.+>\\s*$");
const std::regex TYPE_REGEX::IMAGE(".*!\\[.+]\\(.+)");
const std::regex TYPE_REGEX::TEXT(".+");

//const std::regex TYPE_REGEX::PARAGRAPH;
