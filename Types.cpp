//
// Created by pengnan on 16/5/13.
//

#include <string>
#include "Types.h"


const std::string TYPE_REGEX::EMPTY("");
const std::string TYPE_REGEX::TEXT(".+");
const std::string TYPE_REGEX::HEADER("^#+ .+");
const std::string TYPE_REGEX::UNORDERED_LIST("\\s*[-*] .+");
const std::string TYPE_REGEX::ORDERED_LIST("\\s*\\d\\. .+");
const std::string TYPE_REGEX::LINK("[^!]*\\[.+]\\(.+)");
const std::string TYPE_REGEX::BARE_LINK(".*<.+>.*");
const std::string TYPE_REGEX::IMAGE(".*!\\[.+]\\(.+)");
const std::string TYPE_REGEX::BLOCKQUOTE("> .+");
const std::string TYPE_REGEX::HORIZONTAL("-{3,}");
const std::string TYPE_REGEX::CODE("`{3}.*");
const std::string TYPE_REGEX::TABLE("(\\|.+)+\\|");

//const std::string TYPE_REGEX::PARAGRAPH;
