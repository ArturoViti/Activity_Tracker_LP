#include "Activity.h"

string Activity::getName() const {
    return name;
}

string Activity::getDescription() const {
    return description;
}

ActivityVote Activity::getVote() const {
    return vote;
}

vector<Tag> Activity::getTags() const {
    return tags;
}

Place Activity::getPlace() const {
    return place;
}

QTime Activity::getAnEnd() const {
    return end;
}


QTime Activity::getStart() const {
    return start;
}

void Activity::checkInterval( const QTime &start, const QTime &end ) {
    if ( start >= end )
        throw WrongIntervalException();
}

bool Activity::operator==( const Activity &rActivity ) const {
    return ( start == rActivity.start && end == rActivity.end && name == rActivity.name );
}
