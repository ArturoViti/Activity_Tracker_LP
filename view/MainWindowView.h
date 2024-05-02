#ifndef ACTIVITY_TRACKER_LP_MAINWINDOWVIEW_H
#define ACTIVITY_TRACKER_LP_MAINWINDOWVIEW_H


#include <QWidget>
#include "../config.h"

class MainWindowView : public QWidget {
    public:
        explicit MainWindowView( QWidget *parent = nullptr, int width = WIDTH_SCREEN_SIZE,
                int height = HEIGHT_SCREEN_SIZE  ) : QWidget(parent) {
            resize(width, height);
        }

};


#endif //ACTIVITY_TRACKER_LP_MAINWINDOWVIEW_H
