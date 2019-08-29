#include "QuickSort.h"
#include <iostream>

using namespace std;

QuickSort::QuickSort(int maxSize) {
    _Container = new int[maxSize];
}

QuickSort::~QuickSort() {
    delete[] _Container;
}

void QuickSort::input() {
    cout << "How many elements are in your list? : ";
    cin >> _Size;
    for (int i = 0; i < _Size; ++i) {
        cin >> _Container[i];
    }
}

void QuickSort::swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
// Aim: Devide whole array to 2 parts:
// part 1: <= pivot
// part 2: > pivot
void QuickSort::sort(int left, int right) {
    // Initialize
    int l = left;
    int r = right;
    int pivot = _Container[(l + r) >> 1];

    // Sorting
    while(l <= r) {
        while(_Container[l] < pivot) l++;
        while(_Container[r] > pivot) r--;
        if (l > r) break;
        swap(_Container[l], _Container[r]);
        l++;
        r--;
    }
    if (left < r) sort(left, r);
    if (l < right) sort(l, right);
}

void QuickSort::print() {
    for (int i = 0; i < _Size; i++) {
        cout << _Container[i] << " ";
    }
}

int QuickSort::getSize() {
    return _Size;
}
