//
// Created by Рыжков Артем on 22/12/2018.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H


class PriorityQueue {
public:
    PriorityQueue() = default;
    
    explicit PriorityQueue(int size);
    
    PriorityQueue(const PriorityQueue &obj);
    
    ~PriorityQueue();
    
    bool isEmpty();
    
    bool isEmpty() const;
    
    bool isFull();
    
    bool isFull() const;
    
    int top();
    
    int top() const;
    
    int pop();
    
    void push(int value, int priority);
    
    PriorityQueue &operator=(const PriorityQueue &rhs);
    
private:
    int *data_;
    int *priorities_;
    int size_;
    int end_;
};


#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

