#include "DayActivitiesController.h"

void DayActivitiesController::addActivity( const Activity &activity ) {
    vector<Activity> activities = model->getActivities();
    for ( auto i : activities )
    {
        cout << i.getName() << "--> COSA C?é <-- " << i.getStart().toString().toStdString() << endl;
    }
    auto activitiesStart = activities.begin();
    auto activitiesEnd = activities.end();
    auto it = find_if( activitiesStart, activitiesEnd,
    [activity] (const Activity &temp) {
            cout << activity.getName() << "--> INIZIO INGRESSO " << activity.getStart().toString().toStdString() << endl;
            cout << temp.getName() << " ---> INIZIO CORRENTE " << temp.getStart().toString().toStdString() << endl;
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
