#ifndef ACTIVITY_TRACKER_LP_PLACE_H
#define ACTIVITY_TRACKER_LP_PLACE_H

#include<iostream>

class Place {
    private:
        std::string location;
        std::string name;

    public:
        explicit Place( std::string name, std::string location="" ) : location(location), name(name) { }

        Place( const Place& that ) : location(that.location), name(that.name) { }

        explicit Place( std::string nameWithLocation, char separator='-' ) {
            size_t pos = nameWithLocation.find(separator);
            this->name = nameWithLocation.substr(0, pos);
            this->location = nameWithLocation.substr(pos + 1);
        }

        inline Place& operator=( const Place &rPlace ) {
            if ( this == &rPlace )
                return *this;

            name = rPlace.name;
            location = rPlace.location;
            return *this;
        }

        std::string getName() const;
        std::string serializePlace() const;
};


#endif //ACTIVITY_TRACKER_LP_PLACE_H
