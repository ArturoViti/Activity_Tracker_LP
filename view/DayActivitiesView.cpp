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

    addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller, QDate::currentDate() );
}

void DayActivitiesView::resizeEvent( QResizeEvent *event )  {
    updateCalendarWidth();
    QWidget::resizeEvent(event);
}

void DayActivitiesView::update() {
    Activity newActivity = model->getActivities().back();
    DayActivityRow *item = new DayActivityRow(newActivity);
    listView->addItem(item);
    listView->setItemWidget( item, item->getWidget() );
    QPushButton *removeButtonInstance = item->getDeleteButton();
    QPushButton *openButtonInstance = item->getOpenButton();
    connect(removeButtonInstance, &QPushButton::clicked, this, [this, item]() {
        deleteRow(item);
    });
    connect(openButtonInstance, &QPushButton::clicked, this, [this, item]() {
        Activity tempActivity = item->getActivity();
        addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller, model->getDateDay(), &tempActivity );
        addUpdateActivityWindow->show();
    });

    QMessageBox *msgBox = new QMessageBox;
    QPixmap *exportSuccess = new QPixmap(QString::fromStdString("../" + SUCCESS_ICON_PATH) );
    msgBox->setIconPixmap(*exportSuccess);
    msgBox->setText( QString::fromStdString(SUCCESS_TEXT ) );
    msgBox->setWindowTitle( QString::fromStdString(SUCCESS_TITLE) );
    msgBox->addButton( QMessageBox::Ok );
    msgBox->exec();
}

void DayActivitiesView::deleteRow( DayActivityRow *item ) {
    controller->removeActivity(item->getActivity());
    delete item;
}

void DayActivitiesView::updateOnDelete() {
    QMessageBox *msgBox = new QMessageBox;
    QPixmap *exportSuccess = new QPixmap(QString::fromStdString("../" + SUCCESS_DELETE_ICON_PATH) );
    msgBox->setIconPixmap(*exportSuccess);
    msgBox->setText( QString::fromStdString(SUCCESS_DELETE_TEXT ) );
    msgBox->setWindowTitle( QString::fromStdString(SUCCESS_TITLE) );
    msgBox->addButton( QMessageBox::Ok );
    msgBox->exec();
}


void DayActivitiesView::refreshAll( const QDate date ) {
    for( auto newActivity : model->getActivities() )
    {
        cout << newActivity.getName() << endl;
        DayActivityRow *item = new DayActivityRow(newActivity);
        listView->addItem(item);
        listView->setItemWidget( item, item->getWidget() );
        QPushButton *removeButtonInstance = item->getDeleteButton();
        QPushButton *openButtonInstance = item->getOpenButton();
        connect(removeButtonInstance, &QPushButton::clicked, this, [this, item]() {
            deleteRow(item);
        });
        connect(openButtonInstance, &QPushButton::clicked, this, [this, item]() {
            Activity tempActivity = item->getActivity();
            addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller, model->getDateDay(), &tempActivity );
            addUpdateActivityWindow->show();
        });
    }

}


void DayActivitiesView::onChangeDateDay( const QDate &date ) {
    listView->clear();

    // Backup dell'attuale modello <> vengo da un giorno con attività
    DayActivities *backup = model;
    if ( model->getNumOfActivities() > 0 )
    {
        bool exists = std::any_of(dayRegistry.begin(), dayRegistry.end(),
          [&backup](DayActivities* existing) {
                    return existing->getDateDay() == backup->getDateDay();
        });

        if ( !exists )
            dayRegistry.push_back(backup);
    }


    // Carica il nuovo modello per la data selezionata
    auto it = std::find_if(dayRegistry.begin(), dayRegistry.end(), [&date](DayActivities* activities) {
        return activities->getDateDay() == date;
    });

    if ( it != dayRegistry.end() )
    {
        model = *it;
        controller = new DayActivitiesController(model);
        addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller, date );
        refreshAll( date );
    }
    else
    {
        vector <Activity> act;
        model = new DayActivities(act, date);
        model->addObserver(this);
        controller = new DayActivitiesController(model);
        addUpdateActivityWindow = new AddUpdateActivitiesView( model, controller, date );

    }
}

