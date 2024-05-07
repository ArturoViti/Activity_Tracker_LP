#ifndef ACTIVITY_TRACKER_LP_SUBJECT_H
#define ACTIVITY_TRACKER_LP_SUBJECT_H

#include "Observer.h"

class Subject {

    public:
        virtual ~Subject() { }

        virtual void notify() = 0;

        virtual void addObserver( Observer *o ) = 0;

        virtual void removeObserver( Observer *o ) = 0;
};

#endif //ACTIVITY_TRACKER_LP_SUBJECT_H
