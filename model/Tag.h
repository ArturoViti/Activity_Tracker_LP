#ifndef ACTIVITY_TRACKER_LP_TAG_H
#define ACTIVITY_TRACKER_LP_TAG_H

#include<iostream>
#include<QColor>
#include "../exception/EmptyTagNameException.h"


class Tag {
    private:
        std::string name;
        QColor color;

    public:
        Tag( std::string name, const QColor &color=QColor(0, 0, 0) ) {
            if ( name == "" )
                throw EmptyTagNameException();
            this->name = name;
            this->color = color;
        };

        inline bool operator==( const Tag &rTag ) const {
            return ( name == rTag.name && color == rTag.color );
        }

        std::string getName() const;
        QColor getColor() const;
    };


#endif //ACTIVITY_TRACKER_LP_TAG_H
