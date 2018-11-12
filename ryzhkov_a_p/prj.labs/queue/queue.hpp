#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

class Queue
{
public:
    Queue() = default;
    Queue(int size);
    Queue(const Queue& obj);
    
    ~Queue();
    
    bool isEmpty();
    bool isFull();
    int top();
    int pop();
    void enqueue(int value);
    
    Queue& operator=(const Queue& rhs);
private:
    int* data_;
    int size_;
    int start_;
    int end_;
};

#endif //QUEUE_QUEUE_HPP
