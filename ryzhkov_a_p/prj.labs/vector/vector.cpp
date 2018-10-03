#include <iostream>
#include <sstream>
using namespace std;

class Vector {
public:
    Vector();
    Vector(const int init_size);
    Vector(const Vector& copy);
    Vector& operator=(const Vector& vector);
    ~Vector();

    double& operator[](const int i);
    const double& operator[](const int i) const;

    std::ostream& writeTo(std::ostream& ostrm);

private:
    int size_{ 0 };
    double* data_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, Vector& obj);


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


Vector::~Vector() {
    delete[] data_;
}


std::ostream& Vector::writeTo(std::ostream& ostrm){
    for(int i(0); i < size_; ++i){
        ostrm << (*this)[i] << ((i != size_ - 1) ? ", " : ".") ;
    }
    return ostrm;
}


std::ostream &operator<<(std::ostream &ostrm, Vector& obj){
    obj.writeTo(ostrm);
    return ostrm;
}

void runTests(){
    // Создание вектора на 10 элементов и проинициализируем его элементы индексами
    Vector vector(10);

    for(int i(0); i < 10; ++i){
        vector[i] = i;
    }
    cout << vector << endl;
    double a = vector[7];
    cout << a << endl;

    // Попробуем обратиться к 12 элементу вектора
    try{
        vector[12];
    }catch (out_of_range)
    {
        cout << "Выход за границы вектора" << endl;
    }

    // Создадим новый вектор и присвоим ему старый

    Vector newVector;
    newVector = vector;
    cout << newVector << endl;


}

int main() {

    runTests();

    return 0;
}
