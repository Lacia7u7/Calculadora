//
// Created by carlo on 10/5/2021.
//

#ifndef CALCULADORA_ARITHMETICERROR_H
#define CALCULADORA_ARITHMETICERROR_H

#include <exception>

class ArithmeticError : public std::exception{
private:
    std::string error;
public:
    ArithmeticError();
    ArithmeticError(std::string error);

    const std::string &getError() const;

    void setError(const std::string &error);
};


#endif //CALCULADORA_ARITHMETICERROR_H
