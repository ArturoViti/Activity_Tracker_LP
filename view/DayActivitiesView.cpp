#include <QFrame>
#include <QLabel>
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
    listView = new QListView;
    listActivitiesTemplate = new ListActivitiesTemplate;
    listView->setModel( listActivitiesTemplate );
    activityLayout->addWidget(listView);

    // Collegamento
    calendarButtonLayout->addWidget(button);
    calendarButtonLayout->addWidget(calendar);
    mainLayout->addLayout(calendarButtonLayout);
    mainLayout->addLayout(activityLayout);
}

void DayActivitiesView::resizeEvent( QResizeEvent *event )  {
    updateCalendarWidth();
    QWidget::resizeEvent(event);
}

void DayActivitiesView::update() {
    // @FIXME: non si aggiorna la lista
    listActivitiesTemplate->addItem( controller->getActivities().front() );
    setLayout(activityLayout);
}

