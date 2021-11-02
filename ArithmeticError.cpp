//
// Created by carlo on 10/5/2021.
//

#include <string>
#include <utility>
#include "ArithmeticError.h"

ArithmeticError::ArithmeticError() {

}

ArithmeticError::ArithmeticError(std::string error) {
    this->error=std::move(error);
}
const std::string &ArithmeticError::getError() const {
    return error;
}

void ArithmeticError::setError(const std::string &error) {
    ArithmeticError::error = error;
}

