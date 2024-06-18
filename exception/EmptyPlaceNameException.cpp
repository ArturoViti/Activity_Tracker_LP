//
// Created by Arturo Viti on 18/06/24.
//

#include "EmptyPlaceNameException.h"

const char *EmptyPlaceNameException::what() const noexcept {
    return "Nome del Luogo Obbligatorio";
}
