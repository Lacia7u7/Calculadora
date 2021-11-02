//
// Created by carlo on 9/22/2021.
//

#include "string_utilities.h"

std::vector<std::string>* split(std::string arg,std::string divider){
    std::vector<std::string> *results=new std::vector<std::string>;
    const char *cadena = arg.data();
    char *token = std::strtok(const_cast<char *>(cadena), divider.data());
    while (token){
        results->emplace_back(token);
        token = std::strtok(NULL, divider.data());
    }
    return results;
}
