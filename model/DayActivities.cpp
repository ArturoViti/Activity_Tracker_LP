#include "DayActivities.h"

const QDate &DayActivities::getDateDay() const {
    return dateDay;
}

void DayActivities::setDateDay( const QDate &dateDay ) {
    DayActivities::dateDay = dateDay;
}

void DayActivities::addActivity( const Activity &activity ) {
    auto it = find_if( activities.begin(), activities.end(),
       [&activity] (const Activity &temp) {
                return ( (temp.getStart() > activity.getStart() && temp.getStart() < activity.getAnEnd())
                    || (temp.getAnEnd() < activity.getAnEnd() && temp.getAnEnd() > activity.getStart() ) );
            }
    );

    if ( it != activities.end() )
        this->activities.push_back( activity );
    else
        throw IntervalAlreadyOccupied();
}

void DayActivities::removeActivity( const Activity &activity ) {
    auto it = find_if( activities.begin(), activities.end(),
    [&activity] ( const Activity &temp ) {
            return ( &activity == &temp );
        }
    );

    if ( it != activities.end() )
        this->activities.erase( it );
}
