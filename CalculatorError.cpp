//
// Created by carlo on 9/26/2021.
//

#include "CalculatorError.h"
CalculatorError::~CalculatorError() noexcept {

}

const char *CalculatorError::what() const noexcept {
    std::stack<std::string> stackTrace=*getStackTrace();
    std::string *res = new std::string;
    res->append("Error: ").append(CalculatorError::error).append("\n\n");
    res->append("StackTrace:\n\n");
    while (!stackTrace.empty()){
        res->append("\t").append(stackTrace.top()).append("\n");
        stackTrace.pop();
    }
    auto * errorStr=new std::string;
    errorStr->append(*res);
    return errorStr->c_str();
}

CalculatorError::CalculatorError() {
    error="";
}

CalculatorError CalculatorError::addToStack(std::string message) {
    stack.push_back(message);
    return *this;
}

std::stack<std::string> * CalculatorError::getStackTrace() const {
    std::stack<std::string> *stackTrace=new std::stack<std::string>;
    for (const auto &item : stack){
        stackTrace->push(item);
    }
    return stackTrace;
}

const std::vector<std::string> &CalculatorError::getStack() const {
    return stack;
}

void CalculatorError::setStack(const std::vector<std::string> &stack) {
    CalculatorError::stack = stack;
}

const std::string &CalculatorError::getError() const {
    return error;
}

void CalculatorError::setError(const std::string &error) {
    CalculatorError::error = error;
}

CalculatorError::CalculatorError(const std::vector<std::string> &stack, const std::string &error) : stack(stack),
                                                                                                    error(error) {}

CalculatorError::CalculatorError(const std::string &error) : error(error) {}

CalculatorError CalculatorError::addToStack(std::vector<std::string> messages) {
    for (int i = 0; i < messages.size(); ++i) {
        addToStack(messages[i]);
    }
    return *this;
}
