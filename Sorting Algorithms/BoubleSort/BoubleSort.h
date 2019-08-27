#pragma once

class BoubleSort {
private:
    int* _Container = nullptr;
    int _Size;
public:
    BoubleSort(int maxSize);
    ~BoubleSort();
    void input();
    void sort();
    void print();
};
