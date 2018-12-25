//
// Created by Рыжков Артем on 22/12/2018.
//

#ifndef PQUEUE_PRIORITYQUEUE_H
#define PQUEUE_PRIORITYQUEUE_H


class PriorityQueue {
public:
    PriorityQueue() = default;
    PriorityQueue(const int size);
    PriorityQueue(PriorityQueue &copy);
    ~PriorityQueue();
    
    void push(const int data, const int priority);
    int pop();
    int top();
    
    bool isEmpty();
    bool isFull();
    
    PriorityQueue& operator=(const PriorityQueue &copy);
    
private:
    struct  QueueElement{
        int priority_;
        int data_;
        QueueElement() = default;
        QueueElement(const int data, const int priority);
    };
    QueueElement *array_;
    int end_{0};
    int size_{0};
};


#endif //PQUEUE_PRIORITYQUEUE_H
