#include "Queue.h"
#include <iostream>

Queue::Queue(int size) {
    _MaxSize = size;
    _Container = new int[_MaxSize];
    _Peek = _Size = _Top = 0;
}

Queue::~Queue() {
    delete[] _Container;
}

void Queue::push(int val) {
    if (_Size == _MaxSize - 1) {
        std::cout << "FULL QUEUE\n";
        return;
    }
    if (this->isEmpty()) {
        _Container[_Top] = val;
    } else {
        _Top++;
        _Container[_Top] = val;
    }
    _Size++;
}

void Queue::pop() {
    if (this->isEmpty()) { // Make sure the queue isnt empty
        std::cout << "QUEUE is empty !!\n";
        return;
    }
    _Peek++;
}

int Queue::getPeek() {
    if (!this->isEmpty()) { // Make sure the queue isnt empty
        return _Container[_Peek];
    } else {
        std::cout << "QUEUE is empty !!\n";
    }
}

bool Queue::isEmpty() {
    return (_Size == 0);
}

