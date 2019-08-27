#pragma once
#ifndef HEAP_H
#define HEAP_H

class Heap {
private:
    int* _Array = nullptr;
    int _Size;

public:
    Heap(int maxSize);
    ~Heap();
    int getPeek();
    void update(int index);
    void push(int val);
    void pop();
    void swap(int&, int&);
};

#endif