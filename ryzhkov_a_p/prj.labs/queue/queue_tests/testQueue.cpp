#include <iostream>
#include "../queue.hpp"

using namespace std;

int main() {
    // Создадим очередь
    Queue q1(5);
    // Заполним очередь
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    // Попробуем вставить лишний элемент
    try {
        q1.push(5);
    } catch(std::invalid_argument) {
        cout << "Queue is full" << endl;
    }
    // Конструктор с копированием
    Queue q2(q1);
    // Проверка 2 очереди
    cout << "Queue 2 top" << endl;
    cout << q2.top() << endl;
    // Присваивание
    Queue q3 = q1;
    // Проверка 3 очереди
    cout << "Queue 3 top" << endl;
    cout << q3.top() << endl;
    // Освободим 1 очередь и попробуем взять элемент из пустой очереди
    cout << "Queue 1" << endl;
    cout << q1.pop() << endl;
    cout << q1.pop() << endl;
    cout << q1.pop() << endl;
    cout << q1.pop() << endl;
    try {
        q1.pop();
    } catch(std::invalid_argument) {
        cout << "Queue is empty" << endl;
    }
}
