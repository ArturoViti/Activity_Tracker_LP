//
// Created by Arturo Viti on 26/04/24.
//

#include "SportActivity.h"

void SportActivity::checkIntervalValues( const QTime &start, const QTime &end ) {
    Activity::checkIntervalValues(start, end);

    if ( (end.hour() * SportActivity::MAX_INTERVAL_SPORT_ACTIVITY + end.minute())
            - (start.hour() * SportActivity::MAX_INTERVAL_SPORT_ACTIVITY + start.minute())
                > SportActivity::MAX_INTERVAL_SPORT_ACTIVITY )
        throw WrongIntervalException();
}

void SportActivity::checkIntervalValues(int startHour, int startMinute, int endHour, int endMinute) {
    Activity::checkIntervalValues(startHour, startMinute, endHour, endMinute);

    int startTotalMinutes = startHour * SportActivity::MAX_INTERVAL_SPORT_ACTIVITY + startMinute;
    int endTotalMinutes = endHour * SportActivity::MAX_INTERVAL_SPORT_ACTIVITY + endMinute;
    int intervalMinutes = endTotalMinutes - startTotalMinutes;

    if ( intervalMinutes > SportActivity::MAX_INTERVAL_SPORT_ACTIVITY )
        throw WrongIntervalException();
}
