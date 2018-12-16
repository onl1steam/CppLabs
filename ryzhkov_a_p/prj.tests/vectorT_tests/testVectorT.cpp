#include <iostream>
#include "../../prj.labs/vectorT/vectorT.h"
using namespace std;

int main() {
    // Создание вектора на 10 элементов и проинициализируем его элементы индексами
    VectorT<double> vector(10);
    
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
    
    VectorT<double> newVector;
    newVector = vector;
    cout << newVector << endl;
    
    // Изменим размер вектора до 5 и выведем его длину
    
    newVector.resize(5);
    cout << newVector << endl;
    cout << newVector.size() << endl;
    
    cout << "" << endl;
    cout << "" << endl;
    // То же самое с типом char
    
    // Создание вектора на 10 элементов и проинициализируем его элементы индексами
    VectorT<char> vectorC(10);
    
    for(int i(0); i < 10; ++i){
        vectorC[i] = 'a' + i;
    }
    cout << vectorC << endl;
    char c = vectorC[7];
    cout << c << endl;
    
    // Попробуем обратиться к 12 элементу вектора
    try{
        vector[12];
    }catch (out_of_range)
    {
        cout << "Выход за границы вектора" << endl;
    }
    
    // Создадим новый вектор и присвоим ему старый
    
    VectorT<char> newVectorC;
    newVectorC = vectorC;
    cout << newVectorC << endl;
    
    // Изменим размер вектора до 5 и выведем его длину
    
    newVectorC.resize(5);
    cout << newVectorC << endl;
    cout << newVectorC.size() << endl;
    return 0;
}
