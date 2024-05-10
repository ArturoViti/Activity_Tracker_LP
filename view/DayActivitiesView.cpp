#include <QFrame>
#include <QLabel>
#include "DayActivitiesView.h"
#include "ActivityItemWidgetDelegate.h"

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


    vector<Activity> temp = model->getActivities();
    activitiesToView.reserve(temp.size());
    std::copy(temp.begin(), temp.end(), std::back_inserter(activitiesToView));
    listView = new QListWidget;
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
    cout << "Evento!" << endl;

    Activity newActivity = model->getActivities().back();
    QListWidgetItem *item = new QListWidgetItem(listView);
    QWidget *widget = ActivityItemWidgetDelegate::createRow(
        QString::fromStdString(newActivity.getName()), newActivity.getStart(),
        newActivity.getAnEnd()
    );
    item->setSizeHint(QSize(0, HEIGHT_ROW_CONTAINER_HEIGHT) );
    listView->addItem(item);
    listView->setItemWidget(item, widget);
}

