#include <iostream>
#include "../stack.hpp"
using namespace std;

int main() {
    Stack stack;
    stack.push('o');
    stack.push('l');
    stack.push('l');
    stack.push('e');
    stack.push('h');
    cout << "Stack" << endl << stack << endl;
    
    stack.pop();
    cout << "Stack after pop" << endl << stack << endl;
    
    Stack stack2;
    stack2.push('i');
    stack2.push('h');
    cout << "Stack2" << endl << stack2 << endl;
    
    
    Stack stack4(stack2);
    cout << "Stack4" << endl << stack4 << endl;
    
    stack4 = stack;
    cout << "Stack4 = stack" << endl << stack4 << endl;
    
    stack4 = stack2;
    cout << "Stack4 = stack2" << endl << stack4 << endl;
    
    
    Stack stack3;
    try {
        stack3.top();
    } catch (invalid_argument) {
        cout << "Stack is empty!" << endl;
    }
    
    
    return 0;
}
