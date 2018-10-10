#include "vector.h"

Vector::Vector() {
    data_ = new double[0];
    size_ = 0;
}


Vector::Vector(const int init_size) {
    data_ = new double[init_size];
    size_ = init_size;
}


Vector::Vector(const Vector &copy) {
    *this = copy;
}


Vector& Vector::operator=(const Vector &vector) {
    if (this != &vector){
        delete[] data_;
        size_ = vector.size_;
        data_ = new double[size_];
        for(int i(0); i < size_; ++i){
            data_[i] = vector[i];
        }
    }
    return *this;
}


double &Vector::operator[](const int i) {
    if (i >= size_ ) {
        throw std::out_of_range("Out of range in vector");
    }
    return data_[i];
}


const double &Vector::operator[](const int i) const {
    if (i >= size_ ) {
        throw std::out_of_range("Out of range in vector");
    }
    return data_[i];
}


int Vector::size() const {
    return size_;
}

void Vector::resize(const int size) {
    if (size > size_) {
        Vector tmp{*this};
        delete[] data_;
        data_ = new double[size];
        *this = tmp;
        this->size_ = size;
    }
    size_ = size;
}


Vector::~Vector() {
    delete[] data_;
}


std::ostream& Vector::writeTo(std::ostream& ostrm) {
    for(int i(0); i < size_; ++i){
        ostrm << (*this)[i] << ((i != size_ - 1) ? ", " : ".") ;
    }
    return ostrm;
}


std::ostream &operator<<(std::ostream &ostrm, Vector& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}
