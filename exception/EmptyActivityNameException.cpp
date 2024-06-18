//
// Created by Arturo Viti on 18/06/24.
//

#include "EmptyActivityNameException.h"

const char *EmptyActivityNameException::what() const noexcept {
    return "L'attività deve avere almeno un nome";
}
