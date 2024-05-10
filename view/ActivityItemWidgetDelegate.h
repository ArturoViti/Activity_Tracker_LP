#ifndef ACTIVITY_TRACKER_LP_ACTIVITYITEMWIDGETDELEGATE_H
#define ACTIVITY_TRACKER_LP_ACTIVITYITEMWIDGETDELEGATE_H


#include <QWidget>
#include <QTime>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "../config.h"

class ActivityItemWidgetDelegate {
    public:
        static QWidget* createRow( const QString &activityName, const QTime &start, const QTime &end );
};


#endif //ACTIVITY_TRACKER_LP_ACTIVITYITEMWIDGETDELEGATE_H
