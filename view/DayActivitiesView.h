#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QWidget>
#include "MainWindowView.h"

class DayActivitiesView : public MainWindowView {
    private:
        QCalendarWidget *calendar;

        inline void updateCalendarWidth() {
            calendar->setFixedWidth(width() / 2);
        }

        void setupUI();


    protected:
        void resizeEvent( QResizeEvent *event ) override;


    public:
        explicit DayActivitiesView( QWidget *parent = nullptr ) : MainWindowView(parent) {
            setupUI();
        }
    };

#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
