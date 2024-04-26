#ifndef ACTIVITY_TRACKER_LP_WRONGINTERVALEXCEPTION_H
#define ACTIVITY_TRACKER_LP_WRONGINTERVALEXCEPTION_H

#include<exception>
#include<string>
using namespace std;

class WrongIntervalException : public exception {

private:
    string what_message;

public:
    WrongIntervalException() : exception() {}
    const char* what() const noexcept override;
};


#endif //ACTIVITY_TRACKER_LP_WRONGINTERVALEXCEPTION_H
