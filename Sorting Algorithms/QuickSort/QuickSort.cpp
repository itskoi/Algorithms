#include "QuickSort.h"
#include <iostream>
#include <ctime>

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

void QuickSort::sort(int left, int right) {
    // Initialize
    int l = left;
    int r = right;
    srand(time(NULL) * left);
    int pivot = rand() % (r - l) + l;

    // Sorting
    while(l < r) {
        while(_Container[l] < _Container[pivot]) l++;
        while(_Container[r] > _Container[pivot]) r--;
        if (l >= r) break;
        swap(_Container[l], _Container[r]);
        l++;
        r--;
    }
    if (l < pivot && r != pivot) sort(l, pivot);
    if (r > pivot && l != pivot) sort(pivot, r);
}

void QuickSort::print() {
    for (int i = 0; i < _Size; i++) {
        cout << _Container[i] << " ";
    }
}

int QuickSort::getSize() {
    return _Size;
}
