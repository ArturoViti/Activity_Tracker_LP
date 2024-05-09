#include <QStringListModel>

#ifndef ACTIVITY_TRACKER_LP_LISTACTIVITIESTEMPLATE_H
#define ACTIVITY_TRACKER_LP_LISTACTIVITIESTEMPLATE_H

#include<QStringListModel>
#include "../model/Activity.h"

class ListActivitiesTemplate : public QStringListModel {
    public:
        explicit ListActivitiesTemplate( QObject *parent = nullptr ) : QStringListModel(parent) { }

        inline void addItem( const Activity &item ) {
            beginInsertRows(QModelIndex(), rowCount(), rowCount());
            activitiesItems << item;
            endInsertRows();
        }

    private:
        QList<Activity> activitiesItems;
};


#endif //ACTIVITY_TRACKER_LP_LISTACTIVITIESTEMPLATE_H