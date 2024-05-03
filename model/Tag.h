#ifndef ACTIVITY_TRACKER_LP_TAG_H
#define ACTIVITY_TRACKER_LP_TAG_H

#include<iostream>
#include<Qt>
#include <QColor>

class Tag {
    private:
        std::string name;
        QColor color;


    public:
            explicit Tag( std::string name, const QColor &color ) : name(name), color(color) { };

            Tag( const Tag& that ) : name(that.name), color(that.color) { }

            inline Tag& operator=( const Tag &rTag ) {
                name = rTag.name;
                color = rTag.color;
                return *this;
            }

            inline bool operator==( const Tag &rTag ) {
                return ( name == rTag.name && color == rTag.color );
            }

            const std::string &getName() const;
            void setName( const std::string &name );
            QColor getColor() const;
    };



#endif //ACTIVITY_TRACKER_LP_TAG_H
