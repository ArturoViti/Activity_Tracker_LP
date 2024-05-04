#include<gtest/gtest.h>
#include "../model/Activity.h"

TEST( Activity, MainConstructor ) {
    std::string name = "Ripasso";
    std::string desc = "Laboratorio di Programmazione";
    std::vector<Tag> tags;
    Tag tag = Tag( "Università", *(new QColor(Qt::blue)) );
    tags.push_back(tag);
    QTime start = QTime( 0 ,0);
    QTime end = QTime( 0 ,10);
    Place place = Place( "Morgagni", "Viale Morgagni" );
    Activity *activity = new Activity( name, start, end, tags, place );
    ASSERT_EQ( name, activity->getName() );
}

TEST( Activity, MainConstructorIntervalException ) {
    std::string name = "Ripasso";
    std::string desc = "Laboratorio di Programmazione";
    std::vector<Tag> tags;
    Tag tag = Tag( "Università", *(new QColor(Qt::blue)) );
    tags.push_back(tag);
    QTime start = QTime( 5 ,50);
    QTime end = QTime( 0 ,30);
    Place place = Place( "Morgagni", "Viale Morgagni" );
    ASSERT_THROW( new Activity(name, start, end, tags, place, desc, ActivityVote::GOOD), WrongIntervalException );

}