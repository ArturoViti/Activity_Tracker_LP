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

const QDate &DayActivities::getDateDay() const {
    return dateDay;
}

void DayActivities::setDateDay( const QDate &dateDay ) {
    DayActivities::dateDay = dateDay;
    notify();
}

void DayActivities::addActivity( const Activity &activity ) {
    auto it = find_if( activities.begin(), activities.end(),
       [&activity] (const Activity &temp) {
                return ( (activity.getStart() < temp.getAnEnd()) || (activity.getAnEnd() < temp.getStart()) );
            }
    );

    if ( it != activities.end() )
        throw IntervalAlreadyOccupiedException();
    else
    {
        this->activities.push_back( activity );
        notify();
    }

}

void DayActivities::removeActivity( const Activity &activity ) {
    auto it = find_if( activities.begin(), activities.end(),
    [&activity] ( const Activity &temp ) {
            return ( &activity == &temp );
        }
    );

    if ( it != activities.end() )
    {
        this->activities.erase( it );
        notify();
    }

}

int DayActivities::getNumOfActivities() {
    return activities.size();
}


