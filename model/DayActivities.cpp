//
// Created by Arturo Viti on 26/04/24.
//

#include "DayActivities.h"

const QDate &DayActivities::getDateDay() const {
    return dateDay;
}

void DayActivities::setDateDay( const QDate &dateDay ) {
    DayActivities::dateDay = dateDay;
}
