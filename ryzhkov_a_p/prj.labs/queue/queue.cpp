#include "queue.hpp"
#include <iostream>

Queue::Queue(int size)
: size_(size), start_(0), end_(0)
{
    data_ = new int[size_];
}

Queue::Queue(const Queue& obj)
: size_(obj.size_), start_(obj.start_), end_(obj.end_)
{
    data_ = new int[size_];
    std::copy(obj.data_, obj.data_ + obj.size_, data_);
}

bool Queue::isEmpty()
{
    return start_ == end_;
}

bool Queue::isFull()
{
    return (end_+1) % size_ == start_;
}

int Queue::top()
{
    return data_[start_];
}

int Queue::pop()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Queue is empty");
    }
    
    int result = data_[start_];
    start_ = (start_ + 1) % size_;
    return result;
}

void Queue::push(int value)
{
    if (isFull())
    {
        throw std::invalid_argument("Queue is full");
    }
    
    data_[end_] = value;
    end_ = (end_ + 1) % size_;
}

Queue& Queue::operator=(const Queue& rhs)
{
    if (this != &rhs)
    {
        if (size_ < rhs.size_)
        {
            int* newData(new int[rhs.size_]);
            delete[] data_;
            data_ = newData;
        }
        std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
        size_ = rhs.size_;
    }
    return *this;
}

Queue::~Queue()
{
    delete[] data_;
}
