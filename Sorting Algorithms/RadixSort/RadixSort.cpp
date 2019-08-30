#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include "RadixSort.h"

using namespace std;

RadixSort::RadixSort(int maxSize) {
    _Array = new int[maxSize];
}

RadixSort::~RadixSort() {
    delete[] _Array;
}

void RadixSort::input() {
    cin >> _Size;
    for (int i = 0; i < _Size; i++) {
        cin >> _Array[i];
    }
    _MaxVal = _Array[0];
    for (int i = 1; i < _Size; i++) {
        _MaxVal = _MaxVal < _Array[i] ? _Array[i] : _MaxVal;
    }
}

int RadixSort::getDigit(int key, int pos) {
    int base = 1;
    for (int i = 1; i < pos; i++) base *= 10;
    return (key / base) % 10;
}

void RadixSort::sort() {
    // Get max number of digits
    stringstream ss;
    ss << _MaxVal;
    string str = ss.str();
    int maxNumDigit = str.size();

    // Sort
    for (int i = 1; i <= maxNumDigit; i++) {
        int* tmp = new int[_Size];
        int idx = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < _Size; k++) {
                if (getDigit(_Array[k], i) == j) {
                    tmp[idx++] = _Array[k];
                }
            }
        }
        for (int k = 0; k < _Size; k++) {
            _Array[k] = tmp[k];
            cout << _Array[k] << " ";
        }
        cout << endl;
        delete[] tmp;
    }
}