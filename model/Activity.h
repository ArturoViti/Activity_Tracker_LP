#ifndef ACTIVITY_TRACKER_LP_ACTIVITY_H
#define ACTIVITY_TRACKER_LP_ACTIVITY_H

#include<iostream>
#include<vector>
#include<QTime>

#include "ActivityVote.h"
#include "Tag.h"
#include "Place.h"
#include "../exception/WrongIntervalException.h"
#include "../exception/EmptyActivityNameException.h"

using namespace std;

class Activity {
    private:
        void checkInterval( const QTime &start, const QTime &end );

    protected:
        string name;
        string description;
        ActivityVote vote;
        vector<Tag> tags;
        Place place;
        QTime start;
        QTime end;

    public:
        Activity( string name, QTime &start, QTime &end, const vector<Tag> &tags, Place &place, string desc="",
                  ActivityVote vote=ActivityVote::NONE ): description(desc), vote(vote), tags(tags), place(place) {
            if ( name == "" )
                throw EmptyActivityNameException();

            this->name = name;

            try
            {
                this->start = start;
                this->end = end;
                checkInterval( start, end );
            }
            catch ( const WrongIntervalException& ex )
            {
                throw;
            }

        }

        Activity( const Activity &sourceActivity ) :
            name(sourceActivity.name), description(sourceActivity.description), vote(sourceActivity.vote),
            tags(sourceActivity.tags), place(sourceActivity.place), start(sourceActivity.start),
            end(sourceActivity.end) { }

        inline Activity& operator=( const Activity &rActivity ) {
            if ( this == &rActivity)
                return *this;

            name = rActivity.name;
            description = rActivity.description;
            vote = rActivity.vote;
            tags = rActivity.tags;
            place = rActivity.place;
            start = rActivity.start;
            end = rActivity.end;

            return *this;
        }

        bool operator==( const Activity &rActivity ) const;

        string getName() const;
        string getDescription() const;
        ActivityVote getVote() const;
        vector<Tag> getTags() const;
        Place getPlace() const;
        QTime getAnEnd() const;
        QTime getStart() const;
};


#endif //ACTIVITY_TRACKER_LP_ACTIVITY_H
