//
// Created by Рыжков Артем on 13/11/2018.
//

#ifndef VECTORT_VECTORT_H
#define VECTORT_VECTORT_H

#include <iostream>


template <typename T>
class VectorT {
    
public:
    VectorT();
    VectorT(const int init_size);
    VectorT(const VectorT<T>& copy);
    VectorT& operator=(const VectorT<T>& vector);
    ~VectorT();
    
    
    int size() const;
    void resize(const int size);
    T& operator[](const int i);
    const T& operator[](const int i) const;
    
    std::ostream& writeTo(std::ostream& ostrm);
    
private:
    int size_{ 0 };
    T* data_{ nullptr };
};

template <typename T>
std::ostream& operator<<(std::ostream& ostrm, VectorT<T>& obj);

template <typename T>
VectorT<T>::VectorT() {
    data_ = new T[0];
    size_ = 0;
}

template <typename T>
VectorT<T>::VectorT(const int init_size) {
    data_ = new T[init_size];
    size_ = init_size;
}

template <typename T>
VectorT<T>::VectorT(const VectorT<T> &copy) {
    *this = copy;
}

template <typename T>
VectorT<T>& VectorT<T>::operator=(const VectorT<T> &vector) {
    if (this != &vector){
        delete[] data_;
        size_ = vector.size_;
        data_ = new T[size_];
        for(int i(0); i < size_; ++i){
            data_[i] = vector[i];
        }
    }
    return *this;
}

template <typename T>
T &VectorT<T>::operator[](const int i) {
    if (i >= size_ ) {
        throw std::out_of_range("Out of range in vector");
    }
    return data_[i];
}

template <typename T>
const T &VectorT<T>::operator[](const int i) const {
    if (i >= size_ ) {
        throw std::out_of_range("Out of range in vector");
    }
    return data_[i];
}

template <typename T>
int VectorT<T>::size() const {
    return size_;
}

template <typename T>
void VectorT<T>::resize(const int size) {
    if (size > size_) {
        VectorT tmp{*this};
        delete[] data_;
        data_ = new T[size];
        *this = tmp;
        this->size_ = size;
    }
    size_ = size;
}

template <typename T>
VectorT<T>::~VectorT() {
    delete[] data_;
}

template <typename T>
std::ostream& VectorT<T>::writeTo(std::ostream& ostrm) {
    for(int i(0); i < size_; ++i){
        ostrm << (*this)[i] << ((i != size_ - 1) ? ", " : ".") ;
    }
    return ostrm;
}

template <typename T>
std::ostream &operator<<(std::ostream &ostrm, VectorT<T>& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}





#endif //VECTORT_VECTORT_H

