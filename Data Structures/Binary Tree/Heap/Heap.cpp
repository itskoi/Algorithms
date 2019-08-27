#include "Heap.h"
#include <iostream>

using namespace std;

// HEAP DEFINITION
Heap::Heap(int maxSize) {
    _Size = 0;
    _Array = new int[maxSize];
}

Heap::~Heap() {
    delete[] _Array;
}

int Heap::getPeek() {
    return _Array[1];
}

void Heap::swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

void Heap::update(int index) {
    int pos = index; // element's index greater than _array[index]
    int l = index * 2;
    int r = index * 2 + 1;
    if (l <= _Size && _Array[index] < _Array[l]) {
        pos = l;
    }
    if (r <= _Size && _Array[index] < _Array[r]) {
        pos = r;
    }
    // Exit recursion
    if (pos == index) return;

    // swap and update child's branch
    swap(_Array[index], _Array[pos]);
    update(pos);
}

void Heap::push(int val) {
    if (!_Size) {
        _Array[1] = val;
        _Size++;
    }
    else {
        _Size++;
        _Array[_Size] = val;
        // Bottom-up update
        int index = _Size;
        while(index != 1) {
            if (_Array[index] > _Array[index / 2]) {
                swap(_Array[index], _Array[index / 2]);
            }
            index /= 2;
        }
    }
}

void Heap::pop() {
    if (!_Size) {;
        cout << "This heap is empty !!\n";
        return;
    }
    swap(_Array[1], _Array[_Size]);
    _Size--;
    update(1);
}
