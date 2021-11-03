#include "CVector.h"
#include "ArithmeticError.h"
#include "CalculatorError.h"
#include "Matrix.h"
#include "main.h"
#include <utility>

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os<<matrix.toString(true);
    return os;
}

bool Matrix::operator<(const Matrix &rhs) const {
    return matrix < rhs.matrix;
}

bool Matrix::operator>(const Matrix &rhs) const {
    return rhs < *this;
}

bool Matrix::operator<=(const Matrix &rhs) const {
    return !(rhs < *this);
}

bool Matrix::operator>=(const Matrix &rhs) const {
    return !(*this < rhs);
}

bool Matrix::operator==(const Matrix &rhs) const {
    return matrix == rhs.matrix;
}

bool Matrix::operator!=(const Matrix &rhs) const {
    return !(rhs == *this);
}

Matrix::Matrix(std::vector<CVector> vector) {
    if(vector.empty() || vector[0].getSize()==0){
        throw ArithmeticError("Invalid vector data: the rows and columnes must be >0, provided: ("+ std::to_string(vector.size())+"x"+std::to_string(vector[0].getSize())+")");
    }
    for (int i = 1; i < vector.size(); ++i) {
        if(vector[i].getSize()!=vector[i-1].getSize()){
            std::string vectorErr="\n";
            for (const auto &item : vector){
                vectorErr.append(item.toString(true)).append("\n");
            }
            throw ArithmeticError("The provided vector has different dimensions in its data: "+vectorErr);
        }
    }
    this->matrix=std::move(vector);
}

CNumber Matrix::getDeterminant(struct CVector (*)(CVector (*)(CNumber))) {
    return CNumber();
}

CVector Matrix::setValueAt(int i, int j, const CNumber& value) {
    matrix[i].setValueAt(j,value);
}

CVector Matrix::setMatrix(std::vector<CVector> vector) {
    this->matrix=std::move(vector);
}

CNumber Matrix::getValueAt(int i, int j) const{
    return matrix[i][j];
}

int Matrix::getColumns() const{
    return matrix[0].getSize();
}

int Matrix::getRows() const{
    return matrix.size();
}

Matrix Matrix::operator^(const int& n) const {
    Matrix result=Matrix(matrix);
    if(n==0){
        return Matrix::diagonalMatrix(getRows(), getColumns());
    }else if(n<0){
        result=inverse_matrix(result);
    }
    Matrix expI=Matrix(result.matrix);
    result= diagonalMatrix(getRows(),getColumns());
    int exp=n;
    while (exp>0){
        if(exp&1){//esto es lo mismo que exp%2!=0, es para saber si es impar a partir de su numero binario :)
            result=expI*result;
        }
        exp=exp>>1;//exp= (int)(exp/2);
        expI=expI*expI;
    }
    return result;
}

Matrix Matrix::operator*(const CNumber& complex) const {
    Matrix res=Matrix(matrix);
    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getColumns(); ++j) {
            res.setValueAt(i,j,matrix[i][j]*complex);
        }
    }
}

Matrix Matrix::operator/(const CNumber& complex) const {
    std::string inverseS = "1/(" + complex.toString() + ")";
    CNumber complexInv=  *computeExpression(inverseS);;
    return *this*complexInv;
}

Matrix Matrix::operator/(Matrix complex) const {
    return Matrix(std::vector());
}

Matrix Matrix::inverse_matrix(const Matrix& matrix) const {
    Matrix diag=Matrix::diagonalMatrix(getRows(), getColumns());
    Matrix result=Matrix(this->matrix);
    for (int row= 0; row < getRows(); ++row) {//recorremos las filas
        const CNumber &diagI = getValueAt(row, row);
        result.setValueAt(row,row,CNumber(1,0));
        for(int col=0; col<getColumns(); col++){// hacemos 1 el valor actual de la diagonal
            diag.setValueAt(row,col,diag.getValueAt(row,col)/ diagI);
            result.setValueAt(row,col,result.getValueAt(row,col)/ diagI);
        }
        //Convertimos en 0 toda la columna de la posicion de la diagonal actual
        for (int rowI = 0; rowI < getRows(); ++rowI) {
            if(row != rowI){
                const CNumber &multiplier =result.getValueAt(rowI,row);
                for (int colI = 0; colI < getColumns() ; ++colI) {
                    diag.setValueAt(rowI,colI,diag.getValueAt(rowI,colI)-multiplier*diag.getValueAt(row,colI));
                    result.setValueAt(rowI,colI,result.getValueAt(rowI,colI)-multiplier*result.getValueAt(row,colI));
                }
            }
        }
    }
    return result;
    for(int i=0; i<getRows(); i++){//recorre filas
        for(int j=0; j<getColumns(); j++){//recorre columnas
            const CNumber &currentVal = getValueAt(i, j);
            if(i == j){//si i==j es parte de la diagonal, y si no es -1
                result.setValueAt(i, j, CNumber(1,0));
                for(int k=0; k<getColumns(); k++){
                    diag.setValueAt(i,k,diag.getValueAt(i,k)/ currentVal);
                }
            }else{
                if(currentVal.getReal() != 0){
                    for(int h=0; h<getRows(); h++){
                        for(int k=0; k<getColumns(); k++){
                            if(h!=i){//no estoy en la fila que cambie por ultima vez a uno
                                const CNumber &multi = result.getValueAt(h,j)/result.getValueAt(i,j);//que debo multiplicar para quitar el otro
                                result.setValueAt(h,k,result.getValueAt(h,j)-multi);
                                diag.setValueAt(h,k,diag.getValueAt(h,j)-multi)
                            }
                        }
                    }
                    diag.setValueAt(i,j, diag.getValueAt(i,j)-diag.getValueAt(i,j));
                    result.setValueAt(i,j, currentVal-result.getValueAt(i,j));
                }
            }
        }
    }
    return diag;
}
Matrix Matrix::operator*(Matrix matrix) const { 
    if(getColumns()!=matrix.getRows()){
        ArithmeticError error = ArithmeticError();
        error.setError("Dimension error ("+ std::to_string(getRows())+","+ std::to_string(getColumns())+") x ("+std::to_string(matrix.getRows())+","+ std::to_string(matrix.getColumns())+") is not compatible!");
        throw error;
    }else {
        Matrix result = Matrix(getRows(), matrix.getColumns());

        CNumber value;
        for (int i = 0; i < getRows(); i++) {
            value = 0;
            for (int j = 0; j < matrix.getColumns(); j++) {
                for (int k = 0; k < getColumns(); k++) {
                    value=value+ getValueAt(i, k) * matrix.getValueAt(j, k);
                }
                matrix.setValueAt(i, j, value);
            }
        }
        return result;
    }
}

std::string Matrix::toString(bool addTAG) const{
    std::string result="mat<";
    if(!addTAG){
        result="<";
    }
    for(int i=0; i<getRows()-1; i++){
        result+=matrix[i].toString(addTAG)+";";
    }
    result+=matrix[getRows()-1].toString(addTAG)+">";
    return result;
}

Matrix::Matrix(int r, int c) {
    if(r<0 || c<0){
        throw ArithmeticError("Negative Dimension: ("+ std::to_string(r)+" x "+std::to_string(c)+")";
    }
    for (int i = 0; i < r; ++i) {
        std::vector<CNumber> numbers;
        for (int j = 0; j < c; ++j) {
            numbers.emplace_back(CNumber(0,0));
        }
        matrix.emplace_back(CVector(numbers));
    }
}

Matrix Matrix::diagonalMatrix(int r, int c) {
    Matrix res=Matrix(r,c);
    for (int i = 0; i < r && i<c; ++i) {
        res.setValueAt(i,i,CNumber(1,0));
    }
}


