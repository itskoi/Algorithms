#include "Stack.h"

Stack::Stack(int size) {
    _MaxSize = size;
    _Container = new int[_MaxSize];
    _Top = _Size = 0;
}

Stack::~Stack() {
    delete[] _Container;
}

void Stack::push(int val) {
    if (_Size >= _MaxSize) return;
    _Size++;
    if (_Size == 0) {
        _Container[_Top] = val;
    } else {
        _Top++;
        _Container[_Top] = val;
    }
}

void Stack::pop() {
    if (this->isEmpty()) return; // Make sure the stack isnt empty
    _Top--;
}

int Stack::getTop() {
    if (!this->isEmpty()) { // Make sure the stack isnt empty
        return _Container[_Top];
    }
}

bool Stack::isEmpty() {
    return (_Size == 0);
}