//
// Created by Laptop on 10/10/2021.
//

#include<vector>
#include "../../../../../Downloads/CNumber.h"
#ifndef UNTITLED5_VECTOR_H
#define UNTITLED5_VECTOR_H

class Vector{
    private:
        std::vector<CNumber> vec;
    public:
       Vector();
       Vector(std::vector<CNumber> anotherVec);

       std::vector<CNumber> getVector();
       Vector setVector(std::vector<CNumber>);

       CNumber getMagnitude();

    bool operator==(const Vector &rhs) const;

    bool operator!=(const Vector &rhs) const;

    bool operator<(const Vector &rhs) const;

    bool operator>(const Vector &rhs) const;

    bool operator<=(const Vector &rhs) const;

    bool operator>=(const Vector &rhs) const;

    int getSize() const;

    CNumber operator [](int index) const;

    Vector operator +(const Vector &vectorToPlus) const;
    Vector operator -(const Vector &vectorToPlus) const;
    Vector operator *(int k) const;
    Vector operator *(CNumber complex) const;
    Vector operator /(CNumber complex) const;

       CNumber pointProduct(Vector);
       Vector crossProduct(Vector);
       
       Vector setValueAt(int idx, CNumber value) ;
};

#endif //UNTITLED5_VECTOR_H
