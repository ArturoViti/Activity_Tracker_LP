#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIES_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIES_H

#include<QDate>
#include<vector>
#include "Activity.h"

class DayActivities {

private:
    QDate dateDay;
    std::vector<Activity> activities;

public:
    DayActivities( vector<Activity> &activities, QDate day=QDate::currentDate() ): dateDay(day), activities(activities) { };
    DayActivities( const DayActivities &sourceDay ) : activities(sourceDay.activities), dateDay(sourceDay.dateDay) { };

    inline DayActivities operator=( const DayActivities &rDay ) {
        dateDay = rDay.dateDay;
        activities = rDay.activities;

        return *this;
    }

    const QDate &getDateDay() const;
    void setDateDay(const QDate &dateDay);

};


#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIES_H
