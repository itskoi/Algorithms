#pragma once

class Stack {
private:
    int _MaxSize;
    int _Top;
    int _Size;
    int* _Container = nullptr;
public:
    Stack(int size);
    ~Stack();
    void push(int val);
    void pop();
    int getTop();
    bool isEmpty();
};  