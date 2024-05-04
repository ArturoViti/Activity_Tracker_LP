#include<gtest/gtest.h>
#include "../model/DayActivities.h"

TEST( DayActivities, CorrectSequenceActivites ) {
    std::string name = "Ripasso";
    std::string desc = "Laboratorio di Programmazione";
    std::vector<Tag> tags;
    Tag tag = Tag( "Università", *(new QColor(Qt::blue)) );
    tags.push_back(tag);
    QTime start = QTime( 0 ,0);
    QTime end = QTime( 0 ,10);
    Place place = Place( "Morgagni", "Viale Morgagni" );
    Activity *activity = new Activity( name, start, end, tags, place );
    QTime start2 = QTime( 0 ,20);
    QTime end2 = QTime( 0 ,40);
    Activity *secondActivity = new Activity( name, start2, end2, tags, place );
    vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities( activities );
    dayActivities.addActivity(*secondActivity);
    ASSERT_EQ( 2, dayActivities.getNumOfActivities() );
}

TEST( DayActivities, WrongSequenceActivites ) {
    std::string name = "Ripasso";
    std::string desc = "Laboratorio di Programmazione";
    std::vector<Tag> tags;
    Tag tag = Tag( "Università", *(new QColor(Qt::blue)) );
    tags.push_back(tag);
    QTime start = QTime( 0 ,0);
    QTime end = QTime( 0 ,10);
    Place place = Place( "Morgagni", "Viale Morgagni" );
    Activity *activity = new Activity( name, start, end, tags, place );
    start = QTime( 0, 5 );
    end = QTime( 0,30 );
    Activity *secondActivity = new Activity( name, start, end, tags, place );
    vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities( activities );

    ASSERT_THROW(dayActivities.addActivity(*secondActivity), IntervalAlreadyOccupiedException );

}
