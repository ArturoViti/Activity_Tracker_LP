#include "WrongIntervalException.h"

const char *WrongIntervalException::what() const noexcept {
    return "Intervallo non valido";
}
