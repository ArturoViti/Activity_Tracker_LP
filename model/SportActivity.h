#ifndef ACTIVITY_TRACKER_LP_SPORTACTIVITY_H
#define ACTIVITY_TRACKER_LP_SPORTACTIVITY_H


#include "Activity.h"
#include "SportActivityType.h"

class SportActivity : public Activity {

// @TODO: Gestione Costruttore per il controllo checkIntervalValues()
private:
    int calories;
    float avgHeartBeat;
    SportActivityType sportActivityType;
    static const int MAX_INTERVAL_SPORT_ACTIVITY = 60;
    void checkIntervalValues( const QTime &start, const QTime &end ) override;
    void checkIntervalValues( int startHour=0, int startMinute=0, int endHour=0, int endMinute=0 ) override;

public:
    explicit SportActivity( string name, QTime &start, QTime &end, vector<Tag> &tags, Place &place,
                            string desc="", ActivityVote vote=ActivityVote::NONE,
                            SportActivityType type=SportActivityType::OTHER, int calories=0, float avgHeartBeat=0.0) :
        Activity( name, start, end, tags, place, desc, vote ), sportActivityType(type), calories(calories),
                  avgHeartBeat(avgHeartBeat) {
            try
            {
                checkIntervalValues( start, end );
                this->start = &start;
                this->end = &end;
            }
            catch ( const WrongIntervalException& ex )
            {
                cout << ex.what();
                throw;
            }
        }

    inline SportActivity operator=( const SportActivity &rSportActivity ) {
        if ( this == &rSportActivity )
            return *this;

        Activity::operator=(rSportActivity);
        calories = rSportActivity.calories;
        avgHeartBeat = rSportActivity.avgHeartBeat;
        sportActivityType = rSportActivity.sportActivityType;

        return *this;
    }

    SportActivity( string name, QTime &start, QTime &end, const vector<Tag> &tags, Place &place, string desc,
                   ActivityVote vote, const SportActivity &sourceSportActivity) :
        Activity(name, start, end, tags, place, desc, vote), calories(sourceSportActivity.calories),
        avgHeartBeat(sourceSportActivity.avgHeartBeat), sportActivityType(sourceSportActivity.sportActivityType) { }

    virtual ~SportActivity() {

    }
};


#endif //ACTIVITY_TRACKER_LP_SPORTACTIVITY_H
