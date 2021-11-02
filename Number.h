//
// Created by carlo on 9/22/2021.
//

#ifndef CALCULADORA_NUMBER_H
#define CALCULADORA_NUMBER_H


#include <ostream>

class Number {
private:
    long double r;
    bool containsR;
public:
    explicit Number();

    long double getR() const;

    virtual Number * setR(long double _number);

    bool isContainingR() const;

    void setContainsR(bool _containsData);

    virtual std::string toString() const;

    bool virtual operator==(const Number &rhs) const;

    bool virtual operator!=(const Number &rhs) const;

    bool virtual operator<(const Number &rhs) const;

    bool virtual operator>(const Number &rhs) const;

    bool virtual operator<=(const Number &rhs) const;

    bool virtual operator>=(const Number &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Number &number);

    virtual Number& operator=(const Number& number);
protected:
    virtual void assign(const Number & a);

};


#endif //CALCULADORA_NUMBER_H
