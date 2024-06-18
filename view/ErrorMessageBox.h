//
// Created by Arturo Viti on 18/06/24.
//

#ifndef ACTIVITY_TRACKER_LP_ERRORMESSAGEBOX_H
#define ACTIVITY_TRACKER_LP_ERRORMESSAGEBOX_H


#include "MessageBox.h"
#include "config.h"

class ErrorMessageBox : public MessageBox {
    public:
        void show( string text=ERROR_GENERIC_TEXT, string title=ERROR_TITLE ) override {
            QPixmap exportSuccess(QString::fromStdString("../" + ERROR_ICON_PATH) );
            msgBox.setIconPixmap(exportSuccess);
            msgBox.setText( QString::fromStdString(text) );
            msgBox.setWindowTitle( QString::fromStdString(ERROR_TITLE) );
            msgBox.addButton( QMessageBox::Ok );
            msgBox.exec();
        }
};

#endif //ACTIVITY_TRACKER_LP_ERRORMESSAGEBOX_H
