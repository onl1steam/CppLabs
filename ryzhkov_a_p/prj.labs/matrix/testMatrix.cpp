#include <iostream>
#include "matrix.hpp"
using namespace std;

int main() {
    
    // Создадим матрицу 5x5 и заполним ее
    
    Matrix test(5, 5);
    for(int i(0); i < 5; ++i) {
        for(int j(0); j < 5; j++) {
            test.at(i,j) = i + j;
        }
    }
    
    // Выведем матрицу
    
    cout << test << endl;
    
    // Создадим новую матрицу и заполним ее иными значениями
    
    Matrix test1(test);
    for(int i(0); i < 5; ++i) {
        for(int j(0); j < 5; j++) {
            test1.at(i,j) = 5;
        }
    }
    cout << test1 << endl;
    // Присвоим первой матрице вторую и выведем ее
    
    test = test1;
    cout << test << endl;
    
    // Попробуем обратиться к элементу за границами матрицы
    
    try {
        test.at(5,5);
    } catch(out_of_range) {
        cout << "Out of range in Matrix";
    }
    
}
