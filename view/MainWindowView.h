#ifndef ACTIVITY_TRACKER_LP_MAINWINDOWVIEW_H
#define ACTIVITY_TRACKER_LP_MAINWINDOWVIEW_H


#include <QWidget>
#include "../config.h"

class MainWindowView : public QWidget {
    public:
        explicit MainWindowView( QWidget *parent = nullptr ) : QWidget(parent) {
            resize(WIDTH_SCREEN_SIZE, HEIGHT_SCREEN_SIZE);
        }

};


#endif //ACTIVITY_TRACKER_LP_MAINWINDOWVIEW_H
