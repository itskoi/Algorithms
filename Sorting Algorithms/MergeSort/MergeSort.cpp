#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort(int maxSize) {
    _Container = new int[maxSize];
}

MergeSort::~MergeSort() {
    delete[] _Container;
}

void MergeSort::input() {
    std::cout << "How many elements in your list? : ";
    std::cin >> _Size;
    for (int i = 0; i < _Size; ++i) {
        std::cin >> _Container[i];
    }
}

void MergeSort::sort(int left, int right) {
    if (left == right) return;
    int mid = (left + right) >> 1;
    // Sort left side
    if (left < mid && mid != right) sort(left, mid);
    // Sort right side
    if (mid + 1 < right && mid + 1 != left) sort(mid + 1, right);
    // Merge 2 sides
    merge(left, mid, mid + 1, right);
}

void MergeSort::merge(int a, int b, int c, int d) {
    int leftMost = a;
    int sizeA = b - a + 1;
    int sizeB = d - c + 1;
    int* tmp = new int[sizeA + sizeB];

    // Have totally d - a + 1 elements
    for (int i = 0; i < sizeA + sizeB; i++) {
        if (a > b) {
            tmp[i] = _Container[c];
            c++;
            continue;
        }
        if (c > d) {
            tmp[i] = _Container[a];
            a++;
            continue;
        }
        if (_Container[a] < _Container[c]) {
            tmp[i] = _Container[a];
            a++;
        } else {
            tmp[i] = _Container[c];
            c++;

        }
    }
    for (int i = 0; i < sizeA + sizeB; i++) {
        _Container[i + leftMost] = tmp[i];
    }
    
    delete[] tmp;
}

void MergeSort::print() {
    for (int i = 0; i < _Size; i++) {
        std::cout << _Container[i] << " ";
    }
}

int MergeSort::getSize() {
    return _Size;
}
