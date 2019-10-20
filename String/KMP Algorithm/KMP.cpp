// Hackerearth: Apply KMP
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Input 2 string
    string S, P;
    cin >> P >> S;

    // Modify S and P for handling easily
    S = " " + S;
    P = " " + P;

    // Contribute the vector store length of the suffix of the prefix of the string at each index
    vector<int> F(P.size() + 1);
    F[0] = F[1] = 0; // at the first step lenght equals 0
    for (int i = 2; i < P.size(); i++) {
        int k = F[i - 1];
        while(k > 0 && P[i] != P[k + 1]) {
            k = F[k];
        }
        if (P[i] == P[k + 1]) k++;
        F[i] = k;
    }

    // Find the number of occurences of P in S
    int result = 0;
    int k = 0;
    for (int i = 1; i < S.size(); i++) {
        while(k > 0 && S[i] != P[k + 1]) {
            k = F[k];
        }
        if (P[k + 1] == S[i]) {
            k++;
        }
        if (k == P.size() - 1) {
            result++;
            k = F[k];
        }
    }

    cout << result;
    return 0;
}