#include <QFrame>
#include <QLabel>
#include "DayActivitiesView.h"

void DayActivitiesView::setupUI() {
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *calendarButtonLayout = new QVBoxLayout(this);
    QVBoxLayout *activityLayout = new QVBoxLayout(this);

    mainLayout->setAlignment(Qt::AlignLeft);
    activityLayout->setAlignment(Qt::AlignTop);

    QPushButton *button = new QPushButton("Inserisci una nuova attività");

    calendar = new QCalendarWidget;
    calendar->setFirstDayOfWeek(Qt::Monday);
    calendar->setSelectedDate( QDate::currentDate() );
    calendar->setFixedWidth(QWidget::width() / 2);

    QLabel *label = new QLabel(this);
    QFont *font = new QFont;
    font->setPointSize(32);

    label->setFont(*font);
    label->setText("Le tue Attività");
    label->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    activityLayout->addWidget(label);

    calendarButtonLayout->addWidget(button);
    calendarButtonLayout->addWidget(calendar);
    mainLayout->addLayout(calendarButtonLayout);
    mainLayout->addLayout(activityLayout);
}

void DayActivitiesView::resizeEvent( QResizeEvent *event )  {
    updateCalendarWidth();
    QWidget::resizeEvent(event);
}

