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
#include "MainWindowView.h"
#include "AddUpdateActivitiesView.h"
#include "ListActivitiesTemplate.h"

class DayActivitiesView : public MainWindowView, public Observer {

    private:
        QHBoxLayout *mainLayout;
        QVBoxLayout *calendarButtonLayout;
        QVBoxLayout *activityLayout;

        QCalendarWidget *calendar;
        QPushButton *button;
        QListView *listView;
        ListActivitiesTemplate *listActivitiesTemplate;

        AddUpdateActivitiesView *addUpdateActivityWindow;
        DayActivities *model;
        DayActivitiesController *controller;

        inline void updateCalendarWidth() {
            calendar->setFixedWidth(width() / 2);
        }

        void setupUI();

    private slots:
        void openAddUpdateActivityWindow() {
            addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller );
            addUpdateActivityWindow->show();
        }

        void updateListView() {
            this->update();
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

            //connect(addUpdateActivityWindow, &AddUpdateActivitiesView::activitySaved, this, &DayActivitiesView::updateListView);

        }

        virtual ~DayActivitiesView() {
            model->removeObserver(this);
        }


        virtual void update() override;

};

#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
