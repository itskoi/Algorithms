#pragma once

class RadixSort {
private:
    int* _Array;
    int _MaxVal;
    int _Size;
public:
    RadixSort(int);
    ~RadixSort();
    void input();
    void sort();
    void print();
    int getDigit(int, int);
};