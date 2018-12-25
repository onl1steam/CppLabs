#include <iostream>
#include "../../prj.labs/priority_queue/priority_queue.h"

using namespace std;

int main() {
    // Конструктор
    PriorityQueue queue1(5);
    // Заполненим и попробуем вставить лишний элемент
    queue1.push(1, 3);
    queue1.push(2, 5);
    queue1.push(3, 10);
    queue1.push(4, 1);
    queue1.push(100, 0);
    try {
        queue1.push(11, 0);
    } catch (out_of_range){
        cout << "Queue is full" << endl;
    }
    cout << "Queue 1 top" << endl;
    cout << queue1.top() << endl;
    queue1.pop();
    cout << "Queue 1 top" << endl;
    cout << queue1.top() << endl;
    // Конструктор с копированием
    PriorityQueue queue2(queue1);
    cout << "Queue 2 top" << endl;
    cout << queue2.top() << endl;
    
    // Созданим пустую очередь и попробуем взять из нее элемент
    PriorityQueue queue3(10);
    try {
        queue3.pop();
    }
    catch (std::exception error) {
        cout << "Queue 3 is empty" << endl;
    }
}
