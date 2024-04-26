#include "Activity.h"

const string &Activity::getName() const {
    return name;
}

void Activity::setName( const string &name ) {
    Activity::name = name;
}

const string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription( const string &description ) {
    Activity::description = description;
}

ActivityVote Activity::getVote() const {
    return vote;
}

void Activity::setVote( ActivityVote vote ) {
    Activity::vote = vote;
}

const vector<Tag> &Activity::getTags() const {
    return tags;
}

void Activity::setTags(const vector<Tag> &tags) {
    Activity::tags = tags;
}

Place *Activity::getPlace() const {
    return place;
}

void Activity::setPlace( Place *place ) {
    Activity::place = place;
}

QTime *Activity::getAnEnd() const {
    return end;
}

void Activity::setAnEnd( QTime *anEnd ) {
    end = anEnd;
}

QTime *Activity::getStart() const {
    return start;
}

void Activity::setStart( QTime *start ) {
    Activity::start = start;
}

void Activity::checkInterval( const QTime &start, const QTime &end ) {
    if ( start > end || start < end )
        throw WrongIntervalException();
}

void Activity::checkInterval( int startHour, int startMinute, int endHour, int endMinute ) {
    if ( startHour > endHour || (startHour == endHour && startMinute > endMinute) )
        throw WrongIntervalException();
}
