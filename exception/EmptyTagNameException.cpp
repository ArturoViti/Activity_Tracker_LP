//
// Created by Arturo Viti on 18/06/24.
//

#include "EmptyTagNameException.h"

const char *EmptyTagNameException::what() const noexcept {
    return "Nome del Tag Obbligatorio";
}
