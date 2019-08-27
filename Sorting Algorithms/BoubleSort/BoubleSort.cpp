#include "BoubleSort.h"
#include <iostream>

using namespace std;

BoubleSort::BoubleSort(int maxSize) {
    _Container = new int[maxSize];
}

BoubleSort::~BoubleSort() {
    delete[] _Container;
}

void BoubleSort::input() {
    cout << "How many elements are in your list? : ";
    cin >> _Size;
    for (int i = 0; i < _Size; ++i) {
        cin >> _Container[i];
    }
}

void BoubleSort::sort() {
    for (int i = _Size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (_Container[j] > _Container[j + 1]) {
                swap(_Container[j], _Container[j + 1]);
            }
        }
    }
}

void BoubleSort::print() {
    for (int i = 0; i < _Size; i++) {
        cout << _Container[i] << " ";
    }
}
