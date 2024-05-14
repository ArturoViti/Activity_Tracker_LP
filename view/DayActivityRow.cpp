#include "DayActivityRow.h"


DayActivityRow::DayActivityRow( const Activity &activity ) {
    rowData = new Activity(activity);
    widget = new QWidget;
    layout = new QHBoxLayout();
    labelActivity = new QLabel( QString::fromStdString(activity.getName() ));

    labelStartEndActivity = new QLabel(
            activity.getStart().toString("hh:mm") + " - " + activity.getAnEnd().toString("hh:mm")
    );

    openButton = new QPushButton("Apri");
    deleteButton = new QPushButton("Elimina");

    layout->addWidget(labelActivity);
    layout->addWidget(labelStartEndActivity);
    layout->addWidget(openButton);
    layout->addWidget(deleteButton);
    layout->setContentsMargins( PADDING_ROW, PADDING_ROW, PADDING_ROW, PADDING_ROW );
    widget->setLayout(layout);
    this->setSizeHint(QSize(0, HEIGHT_ROW_CONTAINER_HEIGHT) );
}

QWidget *DayActivityRow::getWidget() {
    return widget;
}

QPushButton *DayActivityRow::getDeleteButton() const {
    return deleteButton;
}

Activity DayActivityRow::getActivity() {
    return *rowData;
}
