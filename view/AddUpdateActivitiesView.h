#ifndef ACTIVITY_TRACKER_LP_ADDUPDATEACTIVITIESVIEW_H
#define ACTIVITY_TRACKER_LP_ADDUPDATEACTIVITIESVIEW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QWidget>
#include "MainWindowView.h"

class AddUpdateActivitiesView : public MainWindowView {
    private:
        QPushButton *saveActivityButton;

        void setupUI();

    public:
        explicit AddUpdateActivitiesView( QWidget *parent = nullptr, int width = WIDTH_SCREEN_SIZE / 2,
                int height = HEIGHT_SCREEN_SIZE / 2 ) : MainWindowView(parent, width, height ) {
            setupUI();
        }
};


#endif
