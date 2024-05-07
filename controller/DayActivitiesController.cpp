#include "DayActivitiesController.h"

void DayActivitiesController::addActivity( const Activity &activity ) {
    try
    {
        model->addActivity( activity );
    }
    catch( ... )
    {
        throw;
    }
}

void DayActivitiesController::removeActivity( const Activity &activity ) {
    model->removeActivity( activity );
}
