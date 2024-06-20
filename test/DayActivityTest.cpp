#include <gtest/gtest.h>
#include "../model/DayActivities.h"

class DayActivitiesTest : public ::testing::Test {
protected:
    std::string name;
    std::string desc;
    std::vector<Tag> tags;
    Tag *tag;
    Place *place;
    Activity* activity;
    Activity* secondActivity;
    QTime start;
    QTime end;
    QTime start2;
    QTime end2;

    void SetUp() override {
        name = "Ripasso";
        desc = "Laboratorio di Programmazione";
        tag = new Tag("Università", *(new QColor(Qt::blue)));
        tags.push_back(*tag);
        place = new Place("Morgagni", "Viale Morgagni");
        start = QTime(0, 0);
        end = QTime(0, 10);
        activity = new Activity(name, start, end, tags, *place);
        start2 = QTime(0, 20);
        end2 = QTime(0, 40);
        secondActivity = new Activity(name, start2, end2, tags, *place);
    }

    void TearDown() override {
        delete activity;
        delete secondActivity;
        delete tag;
        delete place;
    }
};

TEST_F( DayActivitiesTest, CorrectSequenceActivites ) {
    std::vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities(activities);
    dayActivities.addActivity(*secondActivity);

    ASSERT_EQ(2, dayActivities.getNumOfActivities());
}

TEST_F( DayActivitiesTest, WrongSequenceActivites ) {
    std::vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities(activities);
    QTime overlappingStart = QTime(0, 5);
    QTime overlappingEnd = QTime(0, 30);
    Activity overlappingActivity(name, overlappingStart, overlappingEnd, tags, *place);

    ASSERT_THROW(dayActivities.addActivity(overlappingActivity), IntervalAlreadyOccupiedException);
}

TEST_F( DayActivitiesTest, DeleteActivity ) {
    std::vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities(activities);
    dayActivities.addActivity(*secondActivity);
    dayActivities.removeActivity(*activity);

    ASSERT_EQ(1, dayActivities.getNumOfActivities());
}

TEST_F( DayActivitiesTest, DeleteActivityNoActivityFound ) {
    std::vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities(activities);
    dayActivities.addActivity(*secondActivity);
    start2 = QTime(1, 20);
    end2 = QTime(1, 40);
    Activity *thirdActivity = new Activity(name, start2, end2, tags, *place);
    dayActivities.removeActivity(*thirdActivity);

    ASSERT_EQ(2, dayActivities.getNumOfActivities());
    delete thirdActivity;
}

TEST_F( DayActivitiesTest, SearchActivity ) {
    std::vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities(activities);
    name = "Studio Design Pattern";
    Activity *thirdActivity = new Activity(name, start2, end2, tags, *place);
    dayActivities.addActivity(*thirdActivity);
    ASSERT_NO_THROW( dayActivities.searchActivityByName("Studio Design Pattern") );
    delete thirdActivity;
}

TEST_F( DayActivitiesTest, SearchActivityNoActivityFound ) {
    std::vector<Activity> activities;
    activities.push_back(*activity);
    DayActivities dayActivities = DayActivities(activities);
    name = "Studio Design Pattern";
    Activity *thirdActivity = new Activity(name, start2, end2, tags, *place);
    dayActivities.addActivity(*thirdActivity);
    ASSERT_THROW( dayActivities.searchActivityByName("Studio Observer"), ActivityNotFoundException );
    delete thirdActivity;
}

