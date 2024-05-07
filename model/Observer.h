#ifndef ACTIVITY_TRACKER_LP_OBSERVER_H
#define ACTIVITY_TRACKER_LP_OBSERVER_H

class Observer {

    public:
        virtual ~Observer() { }

        virtual void update() = 0;
};

#endif //ACTIVITY_TRACKER_LP_OBSERVER_H
