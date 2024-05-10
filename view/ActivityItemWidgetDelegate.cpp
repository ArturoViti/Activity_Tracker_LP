#include "ActivityItemWidgetDelegate.h"

QWidget* ActivityItemWidgetDelegate::createRow( const QString &activityName, const QTime &start, const QTime &end ) {
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout();
    QLabel *labelActivity = new QLabel(activityName);

    QLabel *labelStartEndActivity = new QLabel(
        start.toString("hh:mm") + " - " + end.toString("hh:mm")
    );

    QPushButton *button1 = new QPushButton("Apri");
    QPushButton *button2 = new QPushButton("Elimina");
    layout->addWidget(labelActivity);
    layout->addWidget(labelStartEndActivity);
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->setContentsMargins(0, 0, 0, 0);
    widget->setLayout(layout);
    //widget->setFixedHeight(HEIGHT_ROW_CONTAINER_HEIGHT);
    return widget;
}
