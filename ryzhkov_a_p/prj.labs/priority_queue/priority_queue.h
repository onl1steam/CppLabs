//
// Created by Рыжков Артем on 22/12/2018.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H


class PriorityQueue {
public:
    PriorityQueue() = default;
    
    explicit PriorityQueue(int size);
    
    PriorityQueue(const PriorityQueue &copy);
    
    ~PriorityQueue();
    
    bool isEmpty();
    bool isFull();
    
    int top();
    int pop();
    
    void push(int value, int priority);
    
    PriorityQueue &operator=(const PriorityQueue &queue);
    
private:
    int *data_;
    int *priorities_;
    int size_;
    int end_;
};


#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

