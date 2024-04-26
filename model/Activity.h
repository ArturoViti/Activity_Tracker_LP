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
    void checkInterval( int startHour=0, int startMinute=0, int endHour=0, int endMinute=0 );

protected:
    string name;
    string description;
    ActivityVote vote;
    vector<Tag> tags;
    Place *place;
    QTime *start;
    QTime *end;

    inline virtual void checkIntervalValues( const QTime &start, const QTime &end ) {
        checkInterval( start, end );
    }
    inline virtual void checkIntervalValues( int startHour=0, int startMinute=0, int endHour=0, int endMinute=0 ) {
        checkInterval( startHour, startMinute, endHour, endMinute );
    }

public:
    Activity( string name, QTime &start, QTime &end, const vector<Tag> &tags, Place &place, string desc="", ActivityVote vote=ActivityVote::NONE ):
            name(name), description(desc), vote(vote), place(&place), tags(tags) {
        try
        {
            checkInterval( start, end );
            this->start = &start;
            this->end = &end;
        }
        catch ( const WrongIntervalException& ex )
        {
            cout << ex.what();
            throw;
        }
    }

    explicit Activity( string name, const vector<Tag> &tags, Place &place, int startHour=0, int startMinute=0, int endHour=0,
            int endMinute=0, string desc="", ActivityVote vote=ActivityVote::NONE  ) {
        QTime *tempStart, *tempEnd;
        try
        {
            checkInterval( startHour, startMinute, endHour, endMinute );
            tempStart = new QTime(startHour, startMinute);
            tempEnd = new QTime(endHour, endMinute);
            Activity(name, *tempStart, *tempEnd, tags, place, desc, vote );
        }
        catch ( const WrongIntervalException& ex )
        {
            delete tempStart;
            delete tempEnd;
            cout << ex.what();
            throw;
        }
        catch ( ... )
        {
            delete tempStart;
            delete tempEnd;
            cout << "Formato non valido";
            throw;
        }
    }

    Activity( const Activity &sourceActivity ) :
        name(sourceActivity.name), description(sourceActivity.description), vote(sourceActivity.vote),
        place(sourceActivity.place), start(sourceActivity.start), end(sourceActivity.end), tags(sourceActivity.tags) { }

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


    virtual ~Activity() {
        tags.clear();
        delete place;
        delete start;
        delete end;
    }

    const string &getName() const;
    void setName(const string &name);

    const string &getDescription() const;
    void setDescription(const string &description);

    ActivityVote getVote() const;
    void setVote(ActivityVote vote);

    const vector<Tag> &getTags() const;
    void setTags(const vector<Tag> &tags);

    Place *getPlace() const;
    void setPlace(Place *place);

    QTime *getAnEnd() const;
    void setAnEnd(QTime *anEnd);

    QTime *getStart() const;
    void setStart(QTime *start);
};


#endif //ACTIVITY_TRACKER_LP_ACTIVITY_H
