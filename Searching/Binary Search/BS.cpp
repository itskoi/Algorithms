// Rank It <> Hackerearth
#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(int val, int size, int* array);
int BS(int l, int r, int val, int size, int* array);

int main() {
    // Input
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    sort(array, array + size);
    // Query
    int Q;
    cin >> Q;
    while(Q--) {
        int val; cin >> val;
        //cout << BinarySearch(val, size, array) << endl;
        cout << BS(0, size - 1, val, size, array) << endl;
    }

    // Free memory
    delete[] array;
    return 0;
}

int BinarySearch(int val, int size, int* array) {
    int l, r, mid;
    l = 0; r = size - 1;
    mid = (l + r) >> 1;
    while (l <= r) {
        if (array[mid] == val) return mid + 1;
        if (array[mid] > val) r = mid - 1;
        else l = mid + 1;
        mid = (l + r) >> 1; 
    }
    return -1;
}

int BS(int l, int r, int val, int size, int* array) {
    if (l > r) return -1;
    int mid = l + r >> 1;
    if (array[mid] == val) return mid + 1;
    if (val > array[mid]) return BS(mid + 1, r, val, size, array);
    else return BS(l, mid - 1, val, size, array);
    return -1;
}