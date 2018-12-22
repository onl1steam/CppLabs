//
// Created by Рыжков Артем on 22/12/2018.
//

#include <algorithm>
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size)
: size_(size), end_(0) {
    data_ = new int[size_];
    priorities_ = new int[size_];
    for (int i(0); i < end_; i++) {
        priorities_[i] = 0;
    }
}

PriorityQueue::PriorityQueue(const PriorityQueue &copy)
: size_(copy.size_), end_(copy.end_) {
    data_ = new int[size_];
    std::copy(copy.data_, copy.data_ + copy.size_, data_);
    
    priorities_ = new int[size_];
    std::copy(copy.priorities_, copy.priorities_ + copy.size_, priorities_);
}

PriorityQueue::~PriorityQueue() {
    delete[] data_;
    delete[] priorities_;
}

bool PriorityQueue::isEmpty() {
    return end_ == 0;
}

bool PriorityQueue::isFull() {
    return size_ == end_;
}

int PriorityQueue::top() {
    return data_[end_];
}

int PriorityQueue::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    
    int result = data_[end_];
    end_--;
    return result;
}

void PriorityQueue::push(int value, int priority) {
    if (isFull()) {
        throw std::out_of_range("Queue is full");
    }
    
    end_++;
    
    for (int i(0); i < end_; i++) {
        if (priority >= priorities_[i]) {
            for (int j(end_); j > i; j--) {
                data_[j] = data_[j - 1];
                priorities_[j] = priorities_[j - 1];
            }
            data_[i] = value;
            priorities_[i] = priority;
            break;
        }
    }
}

PriorityQueue &PriorityQueue::operator=(const PriorityQueue &queue) {
    if (this != &queue) {
        if (size_ < queue.size_) {
            int *newData(new int[queue.size_]);
            delete[] data_;
            data_ = newData;
            
            int *newPriorities(new int[queue.size_]);
            
            delete[] priorities_;
            priorities_ = newPriorities;
        }
        std::copy(queue.data_, queue.data_ + queue.size_, data_);
        std::copy(queue.priorities_, queue.priorities_ + queue.size_, priorities_);
        size_ = queue.size_;
    }
    return *this;
}
