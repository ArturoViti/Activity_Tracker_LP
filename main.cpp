#include <QApplication>
#include "view/DayActivitiesView.h"

int main( int argc, char *argv[] ) {
    QApplication a(argc, argv);

    DayActivitiesView view;
    view.show();

    return QApplication::exec();
}
