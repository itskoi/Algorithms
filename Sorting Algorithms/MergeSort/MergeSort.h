#pragma once

class MergeSort {
private:
    int* _Container;
    int _Size;
public:
    MergeSort(int maxSize);
    ~MergeSort();
    void input();
    void sort(int left, int right);
    void merge(int a, int b, int c, int d);
    void print();
    int getSize();
};