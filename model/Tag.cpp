#include "Tag.h"

const std::string &Tag::getName() const {
    return name;
}

void Tag::setName( const std::string &tagName ) {
    Tag::name = tagName;
}

Tag::~Tag() {
    delete color;
}

QColor Tag::getColor() const {
    return *color;
}
