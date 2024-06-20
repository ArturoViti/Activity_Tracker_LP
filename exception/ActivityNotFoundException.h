//
// Created by Arturo Viti on 20/06/24.
//

#ifndef ACTIVITY_TRACKER_LP_ACTIVITYNOTFOUNDEXCEPTION_H
#define ACTIVITY_TRACKER_LP_ACTIVITYNOTFOUNDEXCEPTION_H

#include<exception>
#include<string>
using namespace std;

class ActivityNotFoundException : public exception {
    private:
        string what_message;

    public:
        ActivityNotFoundException() : exception() {}
        const char* what() const noexcept override;
};


#endif //ACTIVITY_TRACKER_LP_ACTIVITYNOTFOUNDEXCEPTION_H
