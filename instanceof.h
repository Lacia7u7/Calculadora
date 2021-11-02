//
// Created by carlo on 9/22/2021.
//

#ifndef CALCULADORA_INSTANCEOF_H
#define CALCULADORA_INSTANCEOF_H

#endif //CALCULADORA_INSTANCEOF_H
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}