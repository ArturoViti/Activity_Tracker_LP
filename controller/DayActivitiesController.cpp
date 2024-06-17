#include "DayActivitiesController.h"

void DayActivitiesController::addActivity( const Activity &activity ) {
    model->addActivity( activity );
}

void DayActivitiesController::removeActivity( const Activity &activity ) {
    model->removeActivity( activity );
}
