//
// Created by Arturo Viti on 18/06/24.
//

#ifndef ACTIVITY_TRACKER_LP_EMPTYPLACENAMEEXCEPTION_H
#define ACTIVITY_TRACKER_LP_EMPTYPLACENAMEEXCEPTION_H

#include<exception>
#include<string>
using namespace std;

class EmptyPlaceNameException : public exception {
    private:
        string what_message;

    public:
        EmptyPlaceNameException() : exception() {}
        const char* what() const noexcept override;
};

#endif //ACTIVITY_TRACKER_LP_EMPTYPLACENAMEEXCEPTION_H
