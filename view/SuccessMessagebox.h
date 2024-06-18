//
// Created by Arturo Viti on 18/06/24.
//

#ifndef ACTIVITY_TRACKER_LP_SUCCESSMESSAGEBOX_H
#define ACTIVITY_TRACKER_LP_SUCCESSMESSAGEBOX_H


#include "MessageBox.h"
#include "config.h"

class SuccessMessagebox : public MessageBox {
    public:
        void show( string text=SUCCESS_TEXT, string title=SUCCESS_TITLE ) override {
            QPixmap exportSuccess(QString::fromStdString("../" + SUCCESS_ICON_PATH) );
            msgBox.setIconPixmap(exportSuccess);
            msgBox.setText( QString::fromStdString(text) );
            msgBox.setWindowTitle( QString::fromStdString(title) );
            msgBox.addButton( QMessageBox::Ok );
            msgBox.exec();
        }
};


#endif //ACTIVITY_TRACKER_LP_SUCCESSMESSAGEBOX_H
