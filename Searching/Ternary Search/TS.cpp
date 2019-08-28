// Rank It <> Hackerearth
#include <iostream>
#include <algorithm>

using namespace std;

int TS(int, int, int, int*);

int main() {
    // Input
    int size = 0;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    sort(array, array + size);

    // Query
    int Q; cin >> Q;
    while(Q--) {
        int val; cin >> val;
        cout << TS(0, size - 1, val, array) << endl;
    }

    // Free memory
    delete[] array;
    return 0;
}

int TS(int l, int r, int val, int* array) {
    if (l > r) return -1;
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;

    // Start finding !!
    if (array[mid1] == val) return mid1 + 1;
    if (array[mid2] == val) return mid2 + 1;
    if (val < array[mid1]) {
        return TS(l, mid1 - 1, val, array);
    } else if (val > array[mid2]) {
        return TS(mid2 + 1, r, val, array);
    } else {
        return TS(mid1 + 1, mid2 - 1, val, array);
    }
    return -1;
}