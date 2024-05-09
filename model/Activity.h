#ifndef ACTIVITY_TRACKER_LP_ACTIVITY_H
#define ACTIVITY_TRACKER_LP_ACTIVITY_H

#include<iostream>
#include<vector>
#include<QTime>

#include "ActivityVote.h"
#include "Tag.h"
#include "Place.h"
#include "../exception/WrongIntervalException.h"

using namespace std;

class Activity {
    private:
        void checkInterval( const QTime &start, const QTime &end );

    protected:
        string name;
        string description;
        ActivityVote vote;
        vector<Tag> tags;
        Place *place;
        QTime start;
        QTime end;

    public:
        Activity( string name, QTime &start, QTime &end, const vector<Tag> &tags, Place &place, string desc="",
                  ActivityVote vote=ActivityVote::NONE ):
                  name(name), description(desc), vote(vote), tags(tags), place(&place) {
            try
            {
                this->start = start;
                this->end = end;
                checkInterval( start, end );
            }
            catch ( const WrongIntervalException& ex )
            {
                cout << ex.what();
                throw;
            }
        }

        Activity( const Activity &sourceActivity ) :
            name(sourceActivity.name), description(sourceActivity.description), vote(sourceActivity.vote),
            tags(sourceActivity.tags), place(sourceActivity.place), start(sourceActivity.start),
            end(sourceActivity.end) { }

        inline Activity& operator=( const Activity &rActivity ) {
            name = rActivity.name;
            description = rActivity.description;
            vote = rActivity.vote;
            tags = rActivity.tags;
            place = rActivity.place;
            start = rActivity.start;
            end = rActivity.end;

            return *this;
        }

        inline bool operator==( const Activity &rActivity );

        virtual ~Activity() {
            //delete place;
            //delete start;
            //delete end;
        }

        const string &getName() const;
        void setName( const string &name );

        const string &getDescription() const;
        void setDescription( const string &description );

        ActivityVote getVote() const;
        void setVote( ActivityVote vote );

        const vector<Tag> &getTags() const;
        void addTag( const Tag &tag );
        void removeTag( const Tag &tag );

        Place *getPlace() const;
        void setPlace( Place &place );

        QTime getAnEnd() const;
        void setAnEnd( QTime &anEnd );

        QTime getStart() const;
        void setStart( QTime &start );
};


#endif //ACTIVITY_TRACKER_LP_ACTIVITY_H
