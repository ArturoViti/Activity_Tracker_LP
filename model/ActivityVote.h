#ifndef ACTIVITY_TRACKER_LP_ACTIVITYVOTE_H
#define ACTIVITY_TRACKER_LP_ACTIVITYVOTE_H

#include<string>

enum class ActivityVote {
    NONE = -1,
    BAD = 0,
    GOOD = 1,
    VERY_GOOD = 2
};

const std::map<ActivityVote, std::string> ActivityRatings = {
    { ActivityVote::NONE, "Nessuna" },
    { ActivityVote::BAD, "Pessima" },
    { ActivityVote::GOOD, "Bene" },
    { ActivityVote::VERY_GOOD, "Molto Bene" }
};

#endif
