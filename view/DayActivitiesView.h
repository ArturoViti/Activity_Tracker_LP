#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QWidget>
#include <QStandardItem>
#include <QListView>
#include <QObject>
#include <QListWidget>
#include "MainWindowView.h"
#include "AddUpdateActivitiesView.h"

class DayActivitiesView : public MainWindowView, public Observer {
    Q_OBJECT
    private:
        QHBoxLayout *mainLayout;
        QVBoxLayout *calendarButtonLayout;
        QVBoxLayout *activityLayout;

        QCalendarWidget *calendar;
        QPushButton *button;
        QListWidget *listView;

        AddUpdateActivitiesView *addUpdateActivityWindow;
        DayActivities *model;
        DayActivitiesController *controller;
        QList<Activity> activitiesToView;

        inline void updateCalendarWidth() {
            calendar->setFixedWidth(width() / 2);
        }

        void setupUI();


    private slots:
        void openAddUpdateActivityWindow() {
            addUpdateActivityWindow->show();
        }
    protected:
        void resizeEvent( QResizeEvent *event ) override;


    public:
        explicit DayActivitiesView( DayActivities *model, DayActivitiesController *controller, QWidget *parent = nullptr ) : MainWindowView(parent) {
            this->model = model;
            model->addObserver(this);

            this->controller = controller;

            setupUI();

            connect( button, &QPushButton::clicked, this,
                     &DayActivitiesView::openAddUpdateActivityWindow );
        }

        virtual ~DayActivitiesView() {
            model->removeObserver(this);
        }


        virtual void update() override;

};

#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
