#ifndef ACTIVITY_TRACKER_LP_PLACE_H
#define ACTIVITY_TRACKER_LP_PLACE_H

#include<iostream>
#include "../exception/EmptyPlaceNameException.h"

class Place {
    private:
        std::string location;
        std::string name;

    public:
        explicit Place( std::string name, std::string location="" ) {
            if ( name == "" )
                throw EmptyPlaceNameException();
            this->name = name;
            this->location = location;
        }

        explicit Place( std::string nameWithLocation, char separator='-' ) {
            size_t pos = nameWithLocation.find(separator);
            this->name = nameWithLocation.substr(0, pos);
            this->location = nameWithLocation.substr(pos + 1);
        }

        std::string getName() const;
        std::string serializePlace() const;
};


#endif //ACTIVITY_TRACKER_LP_PLACE_H
