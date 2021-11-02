//
// Created by Laptop on 10/10/2021.

#include "CVector.h"
#include "main.h"
#include "instanceof.h"
#include "CalculatorError.h"
#include "CNumber.h"

//

CVector::CVector() {

}

CVector::CVector(std::vector<CNumber> anotherVec) {

}

std::vector<CNumber> CVector::getVector() {
    return std::vector<CNumber>();
}

CVector CVector::setVector(std::vector<CNumber> anotherVector) {
    if(anotherVector.size()!=vec.size()){
        throw "Dimensions of another vector is different of our vector";
    }else{
        for (int i = 0; i < anotherVector.size(); ++i) {
            setValueAt(i,anotherVector[i]);
        }
    }
    return *this;
}

CVector CVector::setValueAt(int idx, CNumber value) {
    if(idx<0 || idx>=vec.size()){
        throw "Index error";
    }else{
        vec[idx]=value;
    }
    return *this;
}

CNumber CVector::getMagnitude() {
    string expr="(";
    for (int i = 0; i < vec.size()-1; ++i) {
        expr.append("(").append(vec[i].toString()).append(")^(2)+");
    }
    expr.append("(").append(vec[vec.size()-1].toString()).append(")^(2)");
    expr.append(")^(1/2)");
    return *computeExpression(expr);
}

bool CVector::operator<(const CVector &rhs) const {
    return vec < rhs.vec;
}

bool CVector::operator>(const CVector &rhs) const {
    return rhs < *this;
}

bool CVector::operator<=(const CVector &rhs) const {
    return !(rhs < *this);
}

bool CVector::operator>=(const CVector &rhs) const {
    return !(*this < rhs);
}

bool CVector::operator==(const CVector &rhs) const {
    return vec == rhs.vec;
}

bool CVector::operator!=(const CVector &rhs) const {
    return !(rhs == *this);
}

CVector CVector::operator+(const CVector &vectorToPlus) const {
    CVector result;
    if(vectorToPlus.getSize()!= getSize()){
        throw "Dimensions of another vector is different of our vector";
    }
    for (int i = 0; i < vectorToPlus.getSize(); ++i) {
        result.setValueAt(i,vectorToPlus[i]+vec[i]);
    }
    return result;
}

CVector CVector::operator-(const CVector &vectorToPlus) const {
    return (*this+(vectorToPlus*-1));
}

int CVector::getSize() const {
    return vec.size();
}

CNumber CVector::operator[](int index) const {
    return vec[index];
}

CVector CVector::operator*(int k) const {
    CNumber kComplex=*CNumber::get0CNumber()->setR(k)->setI(0);
    return *this*kComplex;
}

CVector CVector::operator*(CNumber complex) const {
    CVector result;
    for (int i = 0; i < getSize(); ++i) {
        result.setValueAt(i,vec[i]*complex);
    }
    return result;
}

CVector CVector::operator/(CNumber complex) const {
    string expr="1/(";
    expr.append(complex.toString()).append(")");
    CVector res= *this**computeExpression(expr);
    return res;
}

CNumber CVector::pointProduct(CVector anotherVector) {
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

std::string CVector::toString(bool addTAG) const{
    string result;
    if(addTAG){
        result+="vec<";
    }else{
        result+="<";
    }
    for (int i = 0; i < getSize() - 1; ++i) {
        result+= (*this)[i].toString() + ",";
    }
    result+=(*this)[getSize()-1].toString()+">";
}
