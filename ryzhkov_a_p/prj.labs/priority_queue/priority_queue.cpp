//
// Created by Рыжков Артем on 22/12/2018.
//

#include "PriorityQueue.h"
#include "iostream"

PriorityQueue::QueueElement::QueueElement(const int data, const int priority){
    data_ = data;
    priority_ = priority;
}

PriorityQueue::PriorityQueue(PriorityQueue &copy):
size_(copy.size_), end_(copy.end_) {
    array_ = new QueueElement[size_];
    std::copy(copy.array_, copy.array_ + copy.size_, array_);
}

PriorityQueue::PriorityQueue(const int size)
: size_(size){
    array_ = new QueueElement[size];
}

PriorityQueue::~PriorityQueue() {
    delete[] array_;
    array_ = nullptr;
    size_ = 0;
    end_ = 0;
}

int PriorityQueue::pop() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty");
    }
    int result = array_[end_ - 1].data_;
    end_--;
    return result;
}

int PriorityQueue::top() {
    return array_[end_ - 1].data_;
}

void PriorityQueue::push(const int data, const int priority) {
    if (isFull()) {
        throw std::invalid_argument("Queue is full");
    }
    if (priority < 0) {
        throw std::invalid_argument("Priority cannot be negative");
    }
    bool isPushed = false;
    for (int i(0); i < end_; i++) {
        if (priority >= array_[i].priority_) {
            for (int j(end_); j > i; j--) {
                array_[j]= array_[j - 1];
            }
            array_[i].data_ = data;
            array_[i].priority_ = priority;
            isPushed = true;
            break;
        }
    }
    if (!isPushed) {
        array_[end_].data_ = data;
        array_[end_].priority_ = priority;
    }
    end_++;
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue &copy) {
    if (this != &copy)
    {
        if (size_ < copy.size_)
        {
            QueueElement* newData = new QueueElement[copy.size_];
            delete[] array_;
            array_ = newData;
        }
        std::copy(copy.array_, copy.array_ + copy.size_, array_);
        size_ = copy.size_;
    }
    return *this;
}

bool PriorityQueue::isFull() {
    return size_ == end_ - 1;
}

bool PriorityQueue::isEmpty() {
    return end_ == 0;
}
