//
// Created by carlo on 9/22/2021.
//

#include "CNumber.h"
#include "instanceof.h"
#include "CalculatorError.h"
#include "ArithmeticError.h"
#include <complex>
CNumber *CNumber::get0CNumber(){
    return (new CNumber())->setR(0)->setI(0);
}

CNumber *CNumber::getCNumber(long double r, long double i) {
    return (new CNumber())->setR(r)->setI(i);
}

CNumber::CNumber() :Number() {
    containsI= false;
    i=0;
}

long double CNumber::getI() const {
    return i;
}

CNumber* CNumber::setI(long double _i) {
    CNumber::i = _i;
    return this;
}

CNumber *CNumber::setR(long double _number) {
    Number::setR(_number);
    return this;
}


bool CNumber::isContainingI() const {
    return i!=0;
}

void CNumber::setContainsI(bool containsI) {
    CNumber::containsI = containsI;
}

bool CNumber::operator==(const CNumber &rhs) const {
    return static_cast<const Number &>(*this) == static_cast<const Number &>(rhs) &&
           i == rhs.i;
}

bool CNumber::operator!=(const CNumber &rhs) const {
    return !(rhs == *this);
}

bool CNumber::operator<(const CNumber &rhs) const {
    if (static_cast<const Number &>(*this) < static_cast<const Number &>(rhs))
        return true;
    if (static_cast<const Number &>(rhs) < static_cast<const Number &>(*this))
        return false;
    return i < rhs.i;
}

bool CNumber::operator>(const CNumber &rhs) const {
    return rhs < *this;
}

bool CNumber::operator<=(const CNumber &rhs) const {
    return !(rhs < *this);
}

bool CNumber::operator>=(const CNumber &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const CNumber &number) {
    os<<(number.toString());
    return os;
}
void CNumber::assign(const CNumber &cNumber) {
    Number::assign(cNumber);
    setI(cNumber.getI());
}
CNumber &CNumber::operator=(const CNumber &number1) {
    if(instanceof<CNumber>(&number1)){
        assign(number1);
    }else{
        throw std::bad_cast();
    }
    return *this;
}

CNumber &CNumber::operator=(const Number &number) {
    setR(number.getR());
    this->i=0;
    return *this;
}
bool CNumber::isInvalidCNumber(CNumber* cNumber){
    return (!std::isfinite(cNumber->getR()) || !std::isfinite(cNumber->getI()));
}
CNumber CNumber::operator+(const CNumber &number1) const {
    CNumber res;
    res.setR(getR()+number1.getR());
    res.setI(getI()+number1.getI());
    return res;
}

CNumber CNumber::operator-(const CNumber &number1) const {
    CNumber res;
    res.setR(getR()-number1.getR());
    res.setI(getI()-number1.getI());
    return res;
}
CNumber CNumber::operator/(const CNumber &b) const {
    CNumber *division = CNumber::divide(*this, b);
    return *division;
}

CNumber CNumber::operator*(const CNumber &number1) const {
    return *CNumber::multiply(*this,number1);
}
CNumber *CNumber::divide(const CNumber& number1, const CNumber& number2) {;
    std::complex<long double> n1(number1.getR(),number1.getI());
    std::complex<long double> n2(number2.getR(),number2.getI());
    std::complex<long double> res=n1/n2;
    CNumber *division = (new CNumber())->setR(res.real())->setI(res.imag());
    if(isInvalidCNumber(division)){
        ArithmeticError arithmeticError;
        std::string error;
        error.append("Error con la division: ").append(number1.toString()).append("/").append(number2.toString());
        arithmeticError.setError(error);
        throw arithmeticError;
    }
    return division;
}
CNumber *CNumber::multiply(const CNumber& number1, const CNumber& number2) {;
    std::complex<long double> n1(number1.getR(),number1.getI());
    std::complex<long double> n2(number2.getR(),number2.getI());
    std::complex<long double> res=n1*n2;
    return (new CNumber())->setR(res.real())->setI(res.imag());
}


std::string CNumber::toString() const {
    if(isContainingR() && !isContainingI()){
        return std::to_string(getR());
    }else if(!isContainingR() && isContainingI()){
        return std::to_string(getI()).append("i");
    }else if(!isContainingR() && !isContainingI()){
        return "0";
    }else{
        if(this->getR() == 0 && this->getI() == 0){
            return "0";
        }else if(this->getR() != 0 && this->getI() == 0){
            return std::to_string(this->getR());
        }else if(this->getR() == 0 && this->getI() != 0){
            std::to_string(this->getI()).append("i");
        }else{
            if(this->getI()>0){
                return std::to_string(this->getR()).append("+").append(std::to_string(this->getI())).append("i");
            }else{
                return std::to_string(this->getR()).append(std::to_string(this->getI())).append("i");
            }
        }
    }
    return "";
}
