//
// Created by Arturo Viti on 20/06/24.
//

#include "ActivityNotFoundException.h"

const char *ActivityNotFoundException::what() const noexcept {
    return "Nome del Luogo Obbligatorio";
}
