#include <ostream>
#include "CVector.h"
#include "CNumber.h"
#include "CalculatorError.h"


#ifndef CALCULADORA_MATRIX_H
#define CALCULADORA_MATRIX_H

class Matrix{
private:
    std::vector<CVector> matrix;
public:
    Matrix(std::vector<CVector> vector);
    Matrix(int r,int c);

    CNumber getDeterminant(class CVector(CVector(CNumber)));
    CVector setValueAt(int i,int j, const CNumber& value);

    CNumber getValueAt(int i,int j) const;
    CVector setMatrix(std::vector<CVector> vector);


    Matrix inverse_matrix(const Matrix& matrix) const;


    int getColumns() const;
    int getRows() const;

    std::string toString(bool addTAG) const;

    Matrix operator ^ (const int& matrix1) const;

    Matrix operator *(const CNumber& complex) const;
    Matrix operator *(Matrix matrix) const;

    Matrix operator /(const CNumber& complex) const;
    Matrix operator /(Matrix complex) const;

    bool operator==(const Matrix &rhs) const;

    bool operator!=(const Matrix &rhs) const;

    bool operator<(const Matrix &rhs) const;

    bool operator>(const Matrix &rhs) const;

    bool operator<=(const Matrix &rhs) const;

    bool operator>=(const Matrix &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    static Matrix diagonalMatrix(int r, int c);
};


#endif //CALCULADORA_MATRIX_H
