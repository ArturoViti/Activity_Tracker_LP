#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIES_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIES_H

#include<QDate>
#include<vector>
#include "Activity.h"
#include "Subject.h"
#include "../exception/IntervalAlreadyOccupiedException.h"
#include "../exception/ActivityNotFoundException.h"

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

        bool operator==( const DayActivities &other ) const {
            return dateDay == other.dateDay && activities == other.activities;
        }

        virtual void addObserver( Observer *o ) override;
        virtual void removeObserver( Observer *o ) override;
        virtual void notify() override;
        virtual void notifyDelete() override;

        void addActivity( const Activity &activity );
        void removeActivity( const Activity &activity );
        const Activity searchActivityByName( string name ) const;
        int getNumOfActivities();

        vector<Activity> getActivities() const;
        QDate getDateDay() const;

};


#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIES_H
