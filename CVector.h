//
// Created by Laptop on 10/10/2021.
//

#include<vector>
#include "../../../../../Downloads/CNumber.h"
#ifndef UNTITLED5_VECTOR_H
#define UNTITLED5_VECTOR_H

class CVector{
    private:
        std::vector<CNumber> vec;
    public:
       CVector();
       CVector(std::vector<CNumber> anotherVec);

       std::vector<CNumber> getVector();
       CVector setVector(std::vector<CNumber>);


    int getSize() const;
       CNumber getMagnitude();

    CNumber pointProduct(CVector);
    CVector crossProduct(CVector);

    CVector setValueAt(int idx, CNumber value) ;

    std::string toString(bool addTAG) const;
    bool operator==(const CVector &rhs) const;

    bool operator!=(const CVector &rhs) const;

    bool operator<(const CVector &rhs) const;

    bool operator>(const CVector &rhs) const;

    bool operator<=(const CVector &rhs) const;

    bool operator>=(const CVector &rhs) const;

    CNumber operator [](int index) const;

    CVector operator +(const CVector &vectorToPlus) const;
    CVector operator -(const CVector &vectorToPlus) const;
    CVector operator *(int k) const;
    CVector operator *(CNumber complex) const;
    CVector operator /(CNumber complex) const;

};

#endif //UNTITLED5_VECTOR_H
