#include "AddUpdateActivitiesView.h"
#include "../model/Activity.h"

void AddUpdateActivitiesView::setupUI() {
    // Impostazione Layout
    QVBoxLayout *formContainer = new QVBoxLayout(this);
    QHBoxLayout *tagsLayout = new QHBoxLayout(this);
    formContainer->setAlignment(Qt::AlignTop);
    QGridLayout *layout = new QGridLayout(this);

    // Nome
    activityName = new QLineEdit(this);

    // Descrizione
    activityDescription = new QLineEdit(this);

    // Voto
    ratingComboBox = new QComboBox(this);
    for ( const auto& pair : ActivityRatings )
        ratingComboBox->addItem( QString::fromStdString(pair.first) );

    // Campo Tags
    // Generazione dei Tags @TODO: Sposta Complessità Altrove
    Tag *tag1 = new Tag( "Formazione", *(new QColor(Qt::blue)) );
    Tag *tag2 = new Tag( "Università", *(new QColor(Qt::darkGreen)) );
    Tag *tag3 = new Tag( "Lavoro", *(new QColor(Qt::red)) );
    objectsComboBox = new QButtonGroup(this);
    objectsComboBox->setExclusive(false);
    QCheckBox *checkbox1 = new QCheckBox( QString::fromStdString(tag1->getName()), this );
    QCheckBox *checkbox2 = new QCheckBox( QString::fromStdString(tag2->getName()), this );
    QCheckBox *checkbox3 = new QCheckBox( QString::fromStdString(tag3->getName()), this );
    QPalette palette1 = checkbox1->palette();
    palette1.setColor(QPalette::WindowText, tag1->getColor());
    checkbox1->setPalette(palette1);
    QPalette palette2 = checkbox2->palette();
    palette2.setColor(QPalette::WindowText, tag2->getColor());
    checkbox2->setPalette(palette2);
    QPalette palette3 = checkbox3->palette();
    palette3.setColor(QPalette::WindowText, tag3->getColor());
    checkbox3->setPalette(palette3);

    objectsComboBox->addButton(checkbox1);
    objectsComboBox->addButton(checkbox2);
    objectsComboBox->addButton(checkbox3);

    // Campo Luogo (select)
    locationComboBox = new QComboBox(this);
    // Generazione dei Luoghi
    Place *place1 = new Place( "UniFi", "Centro Didattico Morgagni");
    Place *place2 = new Place( "Azienda", "Zona Santa Maria Novella Firenze");
    locationComboBox->addItem( QString::fromStdString( place1->serializePlace() ) );
    locationComboBox->addItem( QString::fromStdString( place2->serializePlace() ) );

    // Campo Ora Inizio
    startTimeEdit = new QTimeEdit(this);

    // Campo Ora Fine
    endTimeEdit = new QTimeEdit(this);

    // Campo Data
    dateEdit = new QDateEdit( QDate::currentDate() );

    // Pulsante di Salvataggio
    saveActivityButton = new QPushButton( "Salva Attività");

    layout->addWidget(new QLabel("Nome Attività:"), 0, 0);
    layout->addWidget(activityName, 0, 1);

    layout->addWidget(new QLabel("Descrizione Attività:"), 1, 0);
    layout->addWidget(activityDescription, 1, 1);

    layout->addWidget(new QLabel("Voto:"), 2, 0);
    layout->addWidget(ratingComboBox, 2, 1);

    QList<QAbstractButton*> buttonList = objectsComboBox->buttons();
    for ( auto it = buttonList.cbegin(); it!=buttonList.cend(); ++it )
        tagsLayout->addWidget(*it);

    layout->addWidget(new QLabel("Luogo:"), 3, 0);
    layout->addWidget(locationComboBox, 3, 1);

    layout->addWidget(new QLabel("Ora Inizio:"), 5, 0);
    layout->addWidget(startTimeEdit, 5, 1);

    layout->addWidget(new QLabel("Ora Fine:"), 6, 0);
    layout->addWidget(endTimeEdit, 6, 1);

    layout->addWidget(new QLabel("Data:"), 7, 0);
    layout->addWidget(dateEdit, 7, 1);

    formContainer->addLayout(layout);
    formContainer->addLayout(tagsLayout);
    formContainer->addWidget(saveActivityButton);
    setLayout(formContainer);
}

void AddUpdateActivitiesView::saveActivityFromView() {
    // Recupero dei tag
    std::vector<Tag> tags;
    QList<QAbstractButton*> buttonList = objectsComboBox->buttons();
    for ( auto it = buttonList.cbegin(); it!=buttonList.cend(); ++it)
    {
        if ( (*it)->isChecked() )
        {
            Tag tempTag =  Tag( (*it)->text().toStdString(), (*it)->palette().color(QPalette::WindowText) );
            tags.push_back(tempTag);
        }
    }

    // Recupero di Place
    Place tempPlace =  Place( locationComboBox->currentText().toStdString(), '-' );

    // Recupero dell'enumerato
    ActivityVote currentVote = ActivityRatings.at( ratingComboBox->currentText().toStdString() );

    // Recupero delle date
    QTime startTime = startTimeEdit->time();
    QTime endTime = endTimeEdit->time();

    Activity *activity;

    try
    {
        activity = new Activity( activityName->text().toStdString(), startTime, endTime,
            tags, tempPlace, activityDescription->text().toStdString(), currentVote );
        controller->addActivity( *activity );
        emit activitySaved();
    }
    catch ( const WrongIntervalException &wie )
    {
        std::cout << "err";
    }
    catch ( const IntervalAlreadyOccupiedException &iao )
    {
        std::cout << "occupato";
    }
    catch ( ... )
    {
        std::cout << "Errore Generico";
    }


}
