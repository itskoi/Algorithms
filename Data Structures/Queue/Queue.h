#pragma once

class Queue {
private:
    int _Top;
    int _Size;
    int _MaxSize;
    int _Peek;
    int* _Container = nullptr;
public:
    Queue(int size);
    ~Queue();
    void push(int val);
    void pop();
    int getPeek();
    bool isEmpty();
};