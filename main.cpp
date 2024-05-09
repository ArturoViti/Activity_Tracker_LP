#include <QApplication>
#include "view/DayActivitiesView.h"

int main( int argc, char *argv[] ) {
    QApplication a(argc, argv);

    std::unique_ptr<std::vector<Activity>> activities(new std::vector<Activity>());
    DayActivities model(*activities);
    DayActivitiesController controller(&model);

    DayActivitiesView view( &model, &controller);
    view.show();

    return QApplication::exec();
}
