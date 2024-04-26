#include "IntervalAlreadyOccupied.h"

const char *IntervalAlreadyOccupied::what() const noexcept {
    return "Intervallo già occupato da un'altra attività";
}
