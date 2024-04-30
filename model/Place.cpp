#include "Place.h"

const std::string &Place::getLocation() const {
    return location;
}

void Place::setLocation( const std::string &location ) {
    Place::location = location;
}

const std::string &Place::getName() const {
    return name;
}

void Place::setName( const std::string &name ) {
    Place::name = name;
}

Place::~Place() {

}
