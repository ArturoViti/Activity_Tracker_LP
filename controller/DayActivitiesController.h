#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIESCONTROLLER_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIESCONTROLLER_H


#include "../model/DayActivities.h"

class DayActivitiesController {

    private:
        DayActivities *model;

    public:
        DayActivitiesController( DayActivities *m ) : model(m) { }

        void addActivity( const Activity &activity );
        void removeActivity( const Activity &activity );

};



#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIESCONTROLLER_H
