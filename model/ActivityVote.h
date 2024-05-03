#ifndef ACTIVITY_TRACKER_LP_ACTIVITYVOTE_H
#define ACTIVITY_TRACKER_LP_ACTIVITYVOTE_H

#include<string>

enum class ActivityVote {
    NONE = -1,
    BAD = 0,
    GOOD = 1,
    VERY_GOOD = 2
};

const std::map<std::string, ActivityVote> ActivityRatings = {
    { "Nessuna", ActivityVote::NONE },
    { "Pessima", ActivityVote::BAD },
    { "Bene", ActivityVote::GOOD },
    { "Molto Bene", ActivityVote::VERY_GOOD }
};

#endif
