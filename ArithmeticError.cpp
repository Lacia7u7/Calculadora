//
// Created by carlo on 10/5/2021.
//

#include <string>
#include "ArithmeticError.h"

ArithmeticError::ArithmeticError() {

}

const std::string &ArithmeticError::getError() const {
    return error;
}

void ArithmeticError::setError(const std::string &error) {
    ArithmeticError::error = error;
}
