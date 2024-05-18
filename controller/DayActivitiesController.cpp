#include "DayActivitiesController.h"

void DayActivitiesController::addActivity( const Activity &activity ) {
    vector<Activity> activities = model->getActivities();
    auto activitiesStart = activities.begin();
    auto activitiesEnd = activities.end();
    auto it = find_if( activitiesStart, activitiesEnd,
    [activity] (const Activity &temp) {
            return ( (activity.getStart() < temp.getAnEnd()) || (activity.getAnEnd() < temp.getStart()) );
        }
    );

    if ( it != activitiesEnd )
        throw IntervalAlreadyOccupiedException();
    else
        model->addActivity( activity );
}

void DayActivitiesController::removeActivity( const Activity &activity ) {
    model->removeActivity( activity );
}

const vector<Activity> &DayActivitiesController::getActivities() const {
    return model->getActivities();
}
