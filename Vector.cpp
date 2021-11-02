//
// Created by Laptop on 10/10/2021.

#include "Vector.h"
#include "main.h"
#include "instanceof.h"
#include "../../../../../Downloads/CNumber.h"
#include "CalculatorError.h"


//

Vector::Vector() {

}

Vector::Vector(std::vector<CNumber> anotherVec) {

}

std::vector<CNumber> Vector::getVector() {
    return std::vector<CNumber>();
}

Vector Vector::setVector(std::vector<CNumber> anotherVector) {
    if(anotherVector.size()!=vec.size()){
        throw "Dimensions of another vector is different of our vector";
    }else{
        for (int i = 0; i < anotherVector.size(); ++i) {
            setValueAt(i,anotherVector[i]);
        }
    }
    return *this;
}

Vector Vector::setValueAt(int idx, CNumber value) {
    if(idx<0 || idx>=vec.size()){
        throw "Index error";
    }else{
        vec[idx]=value;
    }
    return *this;
}

CNumber Vector::getMagnitude() {
    string expr="(";
    for (int i = 0; i < vec.size()-1; ++i) {
        expr.append("(").append(vec[i].toString()).append(")^(2)+");
    }
    expr.append("(").append(vec[vec.size()-1].toString()).append(")^(2)");
    expr.append(")^(1/2)");
    return *computeExpression(expr);
}

bool Vector::operator<(const Vector &rhs) const {
    return vec < rhs.vec;
}

bool Vector::operator>(const Vector &rhs) const {
    return rhs < *this;
}

bool Vector::operator<=(const Vector &rhs) const {
    return !(rhs < *this);
}

bool Vector::operator>=(const Vector &rhs) const {
    return !(*this < rhs);
}

bool Vector::operator==(const Vector &rhs) const {
    return vec == rhs.vec;
}

bool Vector::operator!=(const Vector &rhs) const {
    return !(rhs == *this);
}

Vector Vector::operator+(const Vector &vectorToPlus) const {
    Vector result;
    if(vectorToPlus.getSize()!= getSize()){
        throw "Dimensions of another vector is different of our vector";
    }
    for (int i = 0; i < vectorToPlus.getSize(); ++i) {
        result.setValueAt(i,vectorToPlus[i]+vec[i]);
    }
    return result;
}

Vector Vector::operator-(const Vector &vectorToPlus) const {
    return (*this+(vectorToPlus*-1));
}

int Vector::getSize() const {
    return vec.size();
}

CNumber Vector::operator[](int index) const {
    return vec[index];
}

Vector Vector::operator*(int k) const {
    CNumber kComplex=*CNumber::get0CNumber()->setR(k)->setI(0);
    return *this*kComplex;
}

Vector Vector::operator*(CNumber complex) const {
    Vector result;
    for (int i = 0; i < getSize(); ++i) {
        result.setValueAt(i,vec[i]*complex);
    }
    return result;
}

Vector Vector::operator/(CNumber complex) const {
    string expr="1/(";
    expr.append(complex.toString()).append(")");
    Vector res= *this**computeExpression(expr);
    return res;
}

CNumber Vector::pointProduct(Vector anotherVector) {
    CNumber result=*CNumber::get0CNumber();
    if(anotherVector.getSize()!=vec.size()){
        throw "Dimensions of another vector is different of our vector";
    }else{
        for (int i = 0; i < anotherVector.getSize(); ++i) {
            result= result + anotherVector[i]*vec[i];
        }
    }
    return result;
}
