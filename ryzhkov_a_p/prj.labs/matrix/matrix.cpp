#include <stdexcept>
#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix() {
    rowNumber_ = 1;
    colNumber_ = 1;
    data = new double*[rowNumber_];
    data[0] = new double[colNumber_];
}

Matrix::Matrix(Matrix &copy) {
    makeNewMatrix(copy);
}

double &Matrix::at(const int numRow, const int numCol) {
    if(numRow < 0 || numCol < 0 || numCol >= colNumber_ || numRow >= rowNumber_) {
        throw std::out_of_range("Out of range in Matrix");
    }
    return data[numRow][numCol];
}

void Matrix::resize(const int rowNum, const int colNum) {
    if (rowNum < rowNumber_ && colNum < colNumber_) {
        rowNumber_ = rowNum;
        colNumber_ = colNum;
        return;
    } else {
        if (colNum < colNumber_ && rowNum == rowNumber_) {
            colNumber_ = colNum;
            return;
        } else {
            if(rowNum < rowNumber_ && colNum == colNumber_) {
                rowNumber_ = rowNum;
                return;
            }
        }
    }
    
}

void Matrix::makeNewMatrix(const Matrix &matrix) {
    rowNumber_ = matrix.rowNumber_;
    colNumber_ = matrix.colNumber_;
    data = new double*[rowNumber_];
    for (int rowNum(0); rowNum < rowNumber_; ++rowNum) {
        data[rowNum] = new double[colNumber_];
        for (int colNum(0); colNum < colNumber_; ++colNum) {
            data[rowNum][colNum] = matrix.data[rowNum][colNum];
        }
    }
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this != &matrix) {
        makeNewMatrix(matrix);
    }
    return *this;
}

const double &Matrix::at(const int numRow, const int numCol) const {
    if(numRow < 0 || numCol < 0 || numCol >= colNumber_ || numRow >= rowNumber_) {
        throw std::out_of_range("Out of range in Matrix");
    }
    return data[numRow][numCol];
}

void Matrix::size() {
    cout << "Matrix number of rows - " << rowNumber_ << ", and columns number - " << colNumber_ << endl;
}

Matrix::Matrix(int rowNumber, int colNumber) {
    colNumber_ = colNumber;
    rowNumber_ = rowNumber;
    data = new double*[rowNumber];
    for(int rowNum(0); rowNum < rowNumber; ++rowNum) {
        data[rowNum] = new double[colNumber];
    }
}

std::ostream& Matrix::writeTo(std::ostream &ostrm) const {
    for (int rowNum(0); rowNum < rowNumber_; ++rowNum) {
        for (int colNum(0); colNum < colNumber_; ++colNum) {
            ostrm << data[rowNum][colNum] << " ";
        }
        ostrm << endl;
    }
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostrm, Matrix matrix) {
    return matrix.writeTo(ostrm);
}

Matrix::~Matrix() {
    for(int rowNum(0); rowNum < rowNumber_; ++rowNum) {
        delete[] data[rowNum];
    }
    delete[] data;
    data = nullptr;
    rowNumber_ = 0;
    colNumber_ = 0;
}


