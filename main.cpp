#include <QApplication>
#include <QPushButton>
#include "config.h"
#include "view/DayActivitiesView.h"

int main( int argc, char *argv[] ) {
    QApplication a(argc, argv);
    /*QPushButton button("Hello world!", nullptr);
    button.resize(WIDTH_SCREEN_SIZE, HEIGHT_SCREEN_SIZE);
    button.show();*/
    DayActivitiesView view;
    view.show();
    return QApplication::exec();
}
