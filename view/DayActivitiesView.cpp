#include "DayActivitiesView.h"

void DayActivitiesView::setupUI() {
    mainLayout = new QHBoxLayout(this);
    calendarButtonLayout = new QVBoxLayout(this);
    activityLayout = new QVBoxLayout(this);

    // Intestazione
    mainLayout->setAlignment(Qt::AlignLeft);
    activityLayout->setAlignment(Qt::AlignTop);

    button = new QPushButton("Inserisci una nuova attività");

    // Calendario
    calendar = new QCalendarWidget;
    calendar->setFirstDayOfWeek(Qt::Monday);
    calendar->setSelectedDate( QDate::currentDate() );
    calendar->setFixedWidth(QWidget::width() / 2);

    QLabel *label = new QLabel(this);
    QFont *font = new QFont;
    font->setPointSize(32);

    // Elenco delle attività
    label->setFont(*font);
    label->setText("Le tue Attività");
    label->setAlignment( Qt::AlignBottom | Qt::AlignCenter );
    activityLayout->addWidget(label);
    listView = new DayActivitiesList;
    activityLayout->addWidget(listView);


    // Collegamento
    calendarButtonLayout->addWidget(button);
    calendarButtonLayout->addWidget(calendar);
    mainLayout->addLayout(calendarButtonLayout);
    mainLayout->addLayout(activityLayout);

    addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller );
}

void DayActivitiesView::resizeEvent( QResizeEvent *event )  {
    updateCalendarWidth();
    QWidget::resizeEvent(event);
}

void DayActivitiesView::update() {
    // @TODO: messaggio di inserimento completato

    Activity newActivity = model->getActivities().back();
    DayActivityRow *item = new DayActivityRow(newActivity);
    listView->addItem(item);
    listView->setItemWidget( item, item->getWidget() );
    QPushButton *button = item->getDeleteButton();
    connect(button, &QPushButton::clicked, this, [this, item]() {
        deleteRow(item);
    });
}

void DayActivitiesView::deleteRow( DayActivityRow *item ) {
    controller->removeActivity(item->getActivity());
    delete item;
    for ( auto i : model->getActivities() )
        cout << i.getName();
}

void DayActivitiesView::updateOnDelete() {
    // @TODO: messaggio di cancellazione completata

}

