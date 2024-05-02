#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QButtonGroup>
#include <QLabel>
#include <QCheckBox>
#include "../model/ActivityVote.h"
#include "AddUpdateActivitiesView.h"
#include "../model/Tag.h"
#include "../model/Place.h"

void AddUpdateActivitiesView::setupUI() {
    // Impostazione Layout
    QVBoxLayout *formContainer = new QVBoxLayout(this);
    QHBoxLayout *tagsLayout = new QHBoxLayout(this);
    formContainer->setAlignment(Qt::AlignTop);
    QGridLayout *layout = new QGridLayout(this);

    // Nome
    QLineEdit *activityName = new QLineEdit(this);

    // Descrizione
    QLineEdit *activityDescription = new QLineEdit(this);

    // Voto
    QComboBox *ratingComboBox = new QComboBox(this);
    for ( const auto& pair : ActivityRatings )
        ratingComboBox->addItem( QString::fromStdString(pair.second) );

    // Campo Tags
    // Generazione dei Tags @TODO: Sposta Complessità Altrove
    Tag *tag1 = new Tag( "Formazione", *(new QColor(Qt::blue)) );
    Tag *tag2 = new Tag( "Università", *(new QColor(Qt::darkGreen)) );
    Tag *tag3 = new Tag( "Lavoro", *(new QColor(Qt::red)) );
    QButtonGroup *objectsComboBox = new QButtonGroup(this);
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
    QComboBox *locationComboBox = new QComboBox(this);
    // Generazione dei Luoghi
    Place *place1 = new Place( "UniFi", "Centro Didattico Morgagni");
    Place *place2 = new Place( "Azienda", "Zona Santa Maria Novella Firenze");
    locationComboBox->addItem( QString::fromStdString( place1->serializePlace() ) );
    locationComboBox->addItem( QString::fromStdString( place2->serializePlace() ) );

    // Campo Ora Inizio
    QTimeEdit *startTimeEdit = new QTimeEdit(this);

    // Campo Ora Fine
    QTimeEdit *endTimeEdit = new QTimeEdit(this);

    // Campo Data
    QDateEdit *dateEdit = new QDateEdit( QDate::currentDate() );

    // Pulsante di Salvataggio
    saveActivityButton = new QPushButton( "Salva Attività");

    layout->addWidget(new QLabel("Nome Attività:"), 0, 0);
    layout->addWidget(activityName, 0, 1);

    layout->addWidget(new QLabel("Descrizione Attività:"), 1, 0);
    layout->addWidget(activityDescription, 1, 1);

    layout->addWidget(new QLabel("Voto:"), 2, 0);
    layout->addWidget(ratingComboBox, 2, 1);

    int i = 0;
    QList<QAbstractButton*> buttonList = objectsComboBox->buttons();
    for ( auto it = buttonList.cbegin(); it!=buttonList.cend(); ++it)
    {
        tagsLayout->addWidget(*it);
        i++;
    }

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
