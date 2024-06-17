#include "Place.h"

std::string Place::getName() const {
    return name;
}

std::string Place::serializePlace() const {
    return name + " - " + location;
}
