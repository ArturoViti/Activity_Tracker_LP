#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITYROW_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITYROW_H


#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>

#include "model/Activity.h"
#include "DayActivitiesList.h"

#include "config.h"

class DayActivityRow : public QListWidgetItem {
    private:
        QWidget *widget;
        QHBoxLayout *layout;
        QLabel *labelActivity;
        QLabel *labelStartEndActivity;
        QPushButton *openButton;
        QPushButton *deleteButton;
        Activity *rowData;

    public:
        DayActivityRow( const Activity &activity );
        QWidget *getWidget();
        Activity getActivity();
        QPushButton *getDeleteButton() const;
        QPushButton *getOpenButton() const;

};


#endif //ACTIVITY_TRACKER_LP_DAYACTIVITYROW_H
