#include <gtest/gtest.h>
#include "../model/Activity.h"

class ActivityTest : public ::testing::Test {
    protected:
        std::string name;
        std::string desc;
        std::vector<Tag> tags;
        Place *place;
        QTime start;
        QTime end;

        void SetUp() override {
            name = "Ripasso";
            desc = "Laboratorio di Programmazione";
            tags.push_back(Tag("Università", *(new QColor(Qt::blue))));
            start = QTime(0, 0);
            end = QTime(0, 10);
            place = new Place("Morgagni", "Viale Morgagni");
        }

        void TearDown() override {
            delete place;
        }
};

TEST_F( ActivityTest, RegularIntervalNoException ) {
    QTime start;
    QTime end;
    start = QTime(0, 0);
    end = QTime(0, 10);
    Activity* activity = new Activity(name, start, end, tags, *place);
    ASSERT_EQ(name, activity->getName());
    delete activity;
}

TEST_F( ActivityTest, EmptyNameException ) {
    name = "";
    ASSERT_THROW(new Activity(name, start, end, tags, *place), EmptyActivityNameException );
}

TEST_F( ActivityTest, WrongIntervalException ) {
    start = QTime(0,30);
    end = QTime(0,10);
    ASSERT_THROW(new Activity(name, start, end, tags, *place), WrongIntervalException );
}