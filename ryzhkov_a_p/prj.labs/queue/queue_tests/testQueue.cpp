#include <iostream>
#include "../queue.hpp"

using namespace std;

int main() {
    
    Queue q1(5);
    Queue q2(q1);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    try {
        q1.enqueue(5);
    } catch(invalid_argument) {
        cout << "Queue is full" << endl;
    }
    Queue q3 = q1;
    cout << q1.pop() << endl;
    q1.enqueue(10);
    cout << q1.pop() << endl;
    cout << q1.top() << endl;
    cout << q3.top() << endl;
    
}
