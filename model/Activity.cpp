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

Place *Activity::getPlace() const {
    return place;
}

void Activity::setPlace( Place &place ) {
    Activity::place = &place;
}

QTime Activity::getAnEnd() const {
    return end;
}

void Activity::setAnEnd( QTime &anEnd ) {
    end = anEnd;
}

QTime Activity::getStart() const {
    return start;
}

void Activity::setStart( QTime &start ) {
    Activity::start = start;
}

void Activity::checkInterval( const QTime &start, const QTime &end ) {
    if ( start >= end )
        throw WrongIntervalException();
}

void Activity::addTag( const Tag &tag ) {
    auto it = find_if( tags.begin(), tags.end(),
        [&tag] ( const Tag &temp ) { return ( &temp == &tag ); }
    );

    if ( it != tags.end() )
        tags.push_back(tag);
}

void Activity::removeTag( const Tag &tag ) {
    auto it = find_if( tags.begin(), tags.end(),
        [&tag] ( const Tag &temp ) {
            return ( &temp == &tag );
        }
    );
    if ( it != tags.end() )
        tags.erase(it);
}

bool Activity::operator==( const Activity &rActivity ) const {
    return ( start == rActivity.start && end == rActivity.end && name == rActivity.name );
}
