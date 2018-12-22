#include <iostream>
#include "../priority_queue.h"

using namespace std;

int main() {
    PriorityQueue queue1(10);
    PriorityQueue queue2(queue1);
    queue1.push(1, 3);
    queue1.push(2, 5);
    queue1.push(3, 10);
    queue1.push(4, 1);
    queue1.push(5, 3);
    queue1.push(6, 7);
    queue1.push(7, 4);
    queue1.push(8, 8);
    queue1.push(9, 0);
    cout << "queue1.pop() = " << queue1.pop() << endl;
    queue1.push(10, 11);
    cout << "queue1.push(10) = " << queue1.top() << endl;
    cout << "queue1.top() = " << queue1.top() << endl;
    queue1.pop();
    queue1.push(11, 3);
    cout << "queue1.top() = " << queue1.top() << endl;
    
    PriorityQueue queue3(10);
    try {
        queue3.pop();
    }
    catch (std::exception error) {
        cout << "queue3 is empty" << endl;
    }
}
