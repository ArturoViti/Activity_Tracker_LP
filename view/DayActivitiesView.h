#ifndef ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
#define ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QWidget>

class DayActivitiesView : public QWidget {

public:
    explicit DayActivitiesView(QWidget *parent = nullptr) : QWidget(parent) {
        setupUI();
    }

private:
    void onGoToDayClicked() {
        //goToDayClicked(dateEdit->date());
    }

private:
    QDateEdit *dateEdit;
    QPushButton *goToDayButton;

    void setupUI() {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        QHBoxLayout *layout = new QHBoxLayout;

        dateEdit = new QDateEdit(this);
        layout->addWidget(dateEdit);


        goToDayButton = new QPushButton("Vai al Giorno", this);
        connect(goToDayButton, &QPushButton::clicked, this, &DayActivitiesView::onGoToDayClicked);
        layout->addWidget(goToDayButton);

        mainLayout->addLayout(layout);
    }
};

#endif //ACTIVITY_TRACKER_LP_DAYACTIVITIESVIEW_H
