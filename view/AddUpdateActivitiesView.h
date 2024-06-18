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

#include "../model/Tag.h"
#include "../model/Place.h"
#include "../model/DayActivities.h"
#include "../controller/DayActivitiesController.h"
#include "MainWindowView.h"
#include "../exception/IntervalAlreadyOccupiedException.h"
#include "../exception/EmptyActivityNameException.h"

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
        QDate selectedDate;

        DayActivities *model;
        DayActivitiesController *controller;

        void setupUI();
        void fillUI( const Activity &activity );
        void resetUI();

    private slots:
        void saveActivityFromView();

    protected:
        void closeEvent( QCloseEvent *event ) override {
            resetUI();
        }

    public:
        explicit AddUpdateActivitiesView( DayActivities *model, DayActivitiesController *controller,
                const QDate &date, Activity *activity = nullptr,
                QWidget *parent = nullptr, int width = WIDTH_SCREEN_SIZE / 2,
                int height = HEIGHT_SCREEN_SIZE / 2  ) : MainWindowView( parent, width, height ) {

            this->model = model;
            this->controller = controller;
            this->selectedDate = date;

            setupUI();

            // Logica di popolazine della modale
            if ( activity != nullptr )
                fillUI( *activity );

            connect( saveActivityButton, &QPushButton::clicked, this,
                     &AddUpdateActivitiesView::saveActivityFromView );
        }

        virtual ~AddUpdateActivitiesView();
};


#endif
