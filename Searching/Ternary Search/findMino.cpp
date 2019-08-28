// Finding Mino <> Hackerearth
#include <iostream>
#include <iomanip>

using namespace std;

double func(double);
double TS(double, double);

int main() {
    int N;
    cin >> N;
    while(N--) {
        double l, r;
        cin >> l >> r;
        cout << fixed << setprecision(0) << TS(l, r) << endl;
    }
    return 0;
}

double func(double x) {
    return (2 * x * x) + (-12 * x) + 7; 
}

double TS(double l, double r) {
    for (int i = 0; i < 200; i++) {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        if (func(mid1) < func(mid2)) r = mid2;
        else l = mid1;
    }
    return func(l);
}