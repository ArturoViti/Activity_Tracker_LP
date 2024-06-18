//
// Created by Arturo Viti on 18/06/24.
//

#ifndef ACTIVITY_TRACKER_LP_MESSAGEBOX_H
#define ACTIVITY_TRACKER_LP_MESSAGEBOX_H

#include <QMessageBox>
#include <iostream>
using namespace std;

class MessageBox {
    protected:
        QMessageBox msgBox;
    public:
        virtual void show( string text="", string title="" ) = 0;
};

#endif //ACTIVITY_TRACKER_LP_MESSAGEBOX_H
