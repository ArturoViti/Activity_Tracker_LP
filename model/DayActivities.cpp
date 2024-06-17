#include "DayActivities.h"

void DayActivities::addObserver( Observer *o ) {
    observers.push_back(o);
}

void DayActivities::removeObserver( Observer *o ) {
    observers.remove(o);
}

void DayActivities::notify() {
    for ( Observer* observer : observers )
        observer->update();
}

void DayActivities::notifyDelete() {
    for ( Observer* observer : observers )
        observer->updateOnDelete();
}

QDate DayActivities::getDateDay() const {
    return dateDay;
}

void DayActivities::addActivity( const Activity &activity ) {
    this->activities.push_back( activity );
    notify();
}

void DayActivities::removeActivity( const Activity &activity ) {
    auto it = find_if( activities.begin(), activities.end(),
    [&activity] ( const Activity &temp ) {
            return ( activity == temp );
        }
    );

    if ( it != activities.end() )
    {
        this->activities.erase( it );
        notifyDelete();
    }
}

int DayActivities::getNumOfActivities() {
    return activities.size();
}

vector<Activity> DayActivities::getActivities() const {
    return activities;
}




