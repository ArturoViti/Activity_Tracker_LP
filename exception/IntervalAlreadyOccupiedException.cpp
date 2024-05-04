#include "IntervalAlreadyOccupiedException.h"

const char *IntervalAlreadyOccupiedException::what() const noexcept {
    return "Intervallo già occupato da un'altra attività";
}
