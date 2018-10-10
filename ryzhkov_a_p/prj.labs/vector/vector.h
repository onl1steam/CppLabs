#ifndef UNTITLED2_VECTOR_H
#define UNTITLED2_VECTOR_H

#include <iostream>

class Vector {
    
public:
    Vector();
    Vector(const int init_size);
    Vector(const Vector& copy);
    Vector& operator=(const Vector& vector);
    ~Vector();
    
    
    int size() const;
    void resize(const int size);
    double& operator[](const int i);
    const double& operator[](const int i) const;
    
    std::ostream& writeTo(std::ostream& ostrm);
    
private:
    int size_{ 0 };
    double* data_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, Vector& obj);


#endif // UNTITLED2_VECTOR_H
