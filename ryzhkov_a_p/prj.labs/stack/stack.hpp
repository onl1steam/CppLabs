#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include <iosfwd>

class Stack {
    
public:
    Stack() = default;
    ~Stack();
    Stack(const Stack &copyStack);
    
    Stack &operator=(const Stack &copyStack);
    
    void push(const char &value);
    void pop();
    char &top();
    const char &top() const;
    
    bool isEmpty() const;
    std::ostream &writeTo(std::ostream &ostrm) const;
    
    
private:
    struct Node {
        Node(Node *pNext);
        Node(Node *pNext, const char &value);
        Node *pNext_{nullptr};
        char data_{char(0)};
    };
    Node *pHead_{nullptr};
};

std::ostream &operator<<(std::ostream &ostrm, const Stack &stack);


#endif //STACK_STACK_HPP

