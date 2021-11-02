//
// Created by carlo on 9/22/2021.
//

#include "Number.h"

Number::Number() {
    containsR= false;
    r=0;
}

long double Number::getR() const {
    return r;
}

Number* Number::setR(long double _number) {
    Number::r = _number;
    return this;
}


bool Number::isContainingR() const {
    return r!=0;
}

void Number::setContainsR(bool _containsData) {
    Number::containsR = _containsData;
}
bool Number::operator<(const Number &rhs) const {
    return r < rhs.getR();
}

bool Number::operator>(const Number &rhs) const {
    return rhs < *this;
}

bool Number::operator<=(const Number &rhs) const {
    return !(rhs < *this);
}

bool Number::operator>=(const Number &rhs) const {
    return !(*this < rhs);
}


bool Number::operator==(const Number &rhs) const {
    return r == rhs.r;
}

bool Number::operator!=(const Number &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Number &number) {
    os << number.r;
    return os;
}
void Number::assign(const Number &a) {
    setR(a.getR());
}

Number&  Number::operator=(const Number& number1) {
    assign(number1);
    return *this;
}

std::string Number::toString() const {
    return std::to_string(r);
}


