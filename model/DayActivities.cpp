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
                return ( (activity.getStart() < temp.getAnEnd()) || (activity.getAnEnd() < temp.getStart()) );
            }
    );

    if ( it != activities.end() )
        throw IntervalAlreadyOccupiedException();
    else
        this->activities.push_back( activity );
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

int DayActivities::getNumOfActivities() {
    return activities.size();
}
