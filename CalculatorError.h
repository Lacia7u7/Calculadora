//
// Created by carlo on 9/26/2021.
//

#ifndef CALCULADORA_CALCULATORERROR_H
#define CALCULADORA_CALCULATORERROR_H

#include <stack>
#include <string>
#include <vector>
class CalculatorError: public std::exception{
private:
    std::vector<std::string> stack;
    std::string error;
public:
    CalculatorError();
    ~CalculatorError() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

    CalculatorError(const std::string &error);

    CalculatorError(const std::vector<std::string> &stack, const std::string &error);

    const std::vector<std::string> &getStack() const;

    void setStack(const std::vector<std::string> &stack);

    const std::string &getError() const;

    void setError(const std::string &error);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;
    std::stack<std::string> * getStackTrace() const;

    CalculatorError addToStack(std::string message);
    CalculatorError addToStack(std::vector<std::string> messages);
};


#endif //CALCULADORA_CALCULATORERROR_H
