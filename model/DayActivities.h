#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIES_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIES_H

#include<QDate>
#include<vector>
#include "Activity.h"
#include "Subject.h"
#include "../exception/IntervalAlreadyOccupiedException.h"

class DayActivities  : public Subject {

    private:
        QDate dateDay;
        std::vector<Activity> activities;
        list<Observer*> observers;

    public:
        DayActivities( const vector<Activity> &activities, const QDate &day=QDate::currentDate() ):
            dateDay(day), activities(activities) { };

        DayActivities( const DayActivities &sourceDay ) : dateDay(sourceDay.dateDay),
            activities(sourceDay.activities) { };

        /*inline DayActivities operator=( const DayActivities &rDay ) {
            dateDay = rDay.dateDay;
            activities = rDay.activities;

            return *this;
        }*/

        virtual void addObserver( Observer *o ) override;
        virtual void removeObserver( Observer *o ) override;
        virtual void notify() override;

        void addActivity( const Activity &activity );
        void removeActivity( const Activity &activity );
        int getNumOfActivities();

        const vector<Activity> &getActivities() const;
        const QDate &getDateDay() const;
        void setDateDay( const QDate &dateDay );

};


#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIES_H
