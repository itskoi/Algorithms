#pragma once

class QuickSort {
private:
    int* _Container;
    int _Size;
public:
    QuickSort(int maxSize);
    ~QuickSort();
    void input();
    void sort(int left, int right);
    void print();
    int getSize();
};