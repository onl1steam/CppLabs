//
// Created by Рыжков Артем on 12/10/2018.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
public:
    Matrix();
    
    Matrix(int rowNumber, int columnNumber);
    
    ~Matrix();
    
    Matrix(Matrix &copy);
    
    void makeNewMatrix(const Matrix &matrix);
    
    Matrix& operator=(const Matrix &matrix);
    
    double &at(const int numRow, const int numCol);
    
    void size();
    
    void resize(const int rowNum, const int colNum);
    
    const double &at(const int numRow, const int numCol) const;
    
    std::ostream &writeTo(std::ostream &ostrm) const;
    
private:
    double** data{nullptr};
    int rowNumber_{0};
    int colNumber_{0};
};

std::ostream &operator<<(std::ostream &ostr, const Matrix matrix);

#endif //MATRIX_MATRIX_H

