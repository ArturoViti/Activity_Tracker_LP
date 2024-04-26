#ifndef ACTIVITY_TRACKER_LP_INTERVALALREADYOCCUPIED_H
#define ACTIVITY_TRACKER_LP_INTERVALALREADYOCCUPIED_H

#include<exception>
#include<string>
using namespace std;

class IntervalAlreadyOccupied : public exception {

private:
    string what_message;

public:
    IntervalAlreadyOccupied() : exception() {}
    const char* what() const noexcept override;
};



#endif //ACTIVITY_TRACKER_LP_INTERVALALREADYOCCUPIED_H
