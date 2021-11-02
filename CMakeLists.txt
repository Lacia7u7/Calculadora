cmake_minimum_required(VERSION 3.20)
project(Calculadora)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(Calculadora
        main.cpp Number.cpp Number.h Number.cpp Number.h CNumber.cpp CNumber.h instanceof.cpp instanceof.h string_utilities.cpp string_utilities.h CalculatorError.cpp CalculatorError.h ArithmeticError.cpp ArithmeticError.h
        Matrix.h Matrix.cpp CVector.h CVector.cpp)
