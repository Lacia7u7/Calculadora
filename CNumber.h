//
// Created by carlo on 9/22/2021.
//

#include <ostream>
#include "Number.h"
#ifndef CALCULADORA_CNUMBER_H
#define CALCULADORA_CNUMBER_H

class CNumber : public Number{
private:
    long double i;
    bool containsI;
public:
    CNumber();
    long double getI() const;
    CNumber * setI(long double _i);

    CNumber *setR(long double _number) override;

    bool isContainingI() const;

    void setContainsI(bool containsI);

    std::string toString() const override;

    friend std::ostream &operator<<(std::ostream &os, const CNumber &number);

    bool operator<(const CNumber &rhs) const;

    bool operator>(const CNumber &rhs) const;

    bool operator<=(const CNumber &rhs) const;

    bool operator>=(const CNumber &rhs) const;

    bool operator==(const CNumber &rhs) const;

    bool operator!=(const CNumber &rhs) const;

    CNumber  operator +(const CNumber &number1)const;

    CNumber operator -(const CNumber &number1)const ;

    CNumber operator /(const CNumber &b)const ;

    CNumber operator *(const CNumber &number1)const ;

    CNumber& operator=(const CNumber& number);
    CNumber& operator=(const Number& number) override;

    static CNumber *get0CNumber();
    static CNumber *getCNumber(long double r, long double i);
    static bool isInvalidCNumber(CNumber* cNumber);
    static CNumber *multiply(const CNumber& number1, const CNumber& number2);
    static CNumber *divide(const CNumber &number1, const CNumber &number2);

protected:
    virtual void assign(const CNumber & cNumber);
};


#endif //CALCULADORA_CNUMBER_H
