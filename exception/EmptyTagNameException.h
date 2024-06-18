//
// Created by Arturo Viti on 18/06/24.
//

#ifndef ACTIVITY_TRACKER_LP_EMPTYTAGNAMEEXCEPTION_H
#define ACTIVITY_TRACKER_LP_EMPTYTAGNAMEEXCEPTION_H

#include<exception>
#include<string>
using namespace std;

class EmptyTagNameException : public exception {
    private:
        string what_message;

    public:
        EmptyTagNameException() : exception() {}
        const char* what() const noexcept override;
};


#endif //ACTIVITY_TRACKER_LP_EMPTYTAGNAMEEXCEPTION_H
