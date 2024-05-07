#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QWidget>
#include "MainWindowView.h"
#include "AddUpdateActivitiesView.h"

class DayActivitiesView : public MainWindowView {

    private:
        QCalendarWidget *calendar;
        QPushButton *button;
        AddUpdateActivitiesView *addUpdateActivityWindow;

        inline void updateCalendarWidth() {
            calendar->setFixedWidth(width() / 2);
        }

        void setupUI();

    private slots:
        void openAddUpdateActivityWindow() {
            addUpdateActivityWindow = new AddUpdateActivitiesView();
            addUpdateActivityWindow->show();
        }


    protected:
        void resizeEvent( QResizeEvent *event ) override;


    public:
        explicit DayActivitiesView( QWidget *parent = nullptr ) : MainWindowView(parent) {
            setupUI();
            connect( button, &QPushButton::clicked, this,
                     &DayActivitiesView::openAddUpdateActivityWindow );
        }

};

#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
