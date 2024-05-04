#ifndef ACTIVITY_TRACKER_LP_INTERVALALREADYOCCUPIEDEXCEPTION_H
#define ACTIVITY_TRACKER_LP_INTERVALALREADYOCCUPIEDEXCEPTION_H

#include<exception>
#include<string>
using namespace std;

class IntervalAlreadyOccupiedException : public exception {

private:
    string what_message;

public:
    IntervalAlreadyOccupiedException() : exception() {}
    const char* what() const noexcept override;
};



#endif //ACTIVITY_TRACKER_LP_INTERVALALREADYOCCUPIEDEXCEPTION_H
