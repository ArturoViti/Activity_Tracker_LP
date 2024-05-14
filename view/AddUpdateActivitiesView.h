#ifndef ACTIVITY_TRACKER_LP_ADDUPDATEACTIVITIESVIEW_H
#define ACTIVITY_TRACKER_LP_ADDUPDATEACTIVITIESVIEW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QButtonGroup>
#include <QLabel>
#include <QCheckBox>
#include <QObject>
#include <QMessageBox>

#include "../model/ActivityVote.h"
#include "../model/Tag.h"
#include "../model/Place.h"
#include "../model/DayActivities.h"
#include "../controller/DayActivitiesController.h"
#include "MainWindowView.h"
#include "../exception/IntervalAlreadyOccupiedException.h"

class AddUpdateActivitiesView : public MainWindowView {
    private:
        QPushButton *saveActivityButton;
        QLineEdit *activityName;
        QLineEdit *activityDescription;
        QComboBox *ratingComboBox;
        QButtonGroup *objectsComboBox;
        QComboBox *locationComboBox;
        QTimeEdit *startTimeEdit;
        QTimeEdit *endTimeEdit;
        QDateEdit *dateEdit;

        DayActivities *model;
        DayActivitiesController *controller;

        void setupUI();

    private slots:
        void saveActivityFromView();

    public:
        explicit AddUpdateActivitiesView( DayActivities *model, DayActivitiesController *controller,
                QWidget *parent = nullptr, int width = WIDTH_SCREEN_SIZE / 2,
                int height = HEIGHT_SCREEN_SIZE / 2 ) : MainWindowView(parent, width, height ) {

            this->model = model;
            this->controller = controller;

            setupUI();
            connect( saveActivityButton, &QPushButton::clicked, this,
                     &AddUpdateActivitiesView::saveActivityFromView );
        }

        virtual ~AddUpdateActivitiesView();
};


#endif
