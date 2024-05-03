#include "Tag.h"

const std::string &Tag::getName() const {
    return name;
}

void Tag::setName( const std::string &tagName ) {
    Tag::name = tagName;
}

QColor Tag::getColor() const {
    return color;
}
