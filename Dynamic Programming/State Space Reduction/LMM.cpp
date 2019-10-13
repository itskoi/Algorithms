// Hackerearth
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int n, X, Y;
int A[1010], dp[1010][51][3][2];

int main() {
    cin >> n >> X >> Y;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i][0][1][1] += 1;
            } else {
                dp[i][0][1][0] += 1;
            }
        }
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            for (int x = 0; x <= X; x++) {
                for (int y = 0; y < 3; y++) {
                    if (A[i] > A[j]) {
                        dp[i][x][y][1] = (dp[i][x][y][1] + dp[j][x][y][1] % MOD);
                        if (x < X && y != 0) {
                            dp[i][x + 1][y - 1][1] = (dp[i][x + 1][y - 1][1] + dp[j][x][y][0]) % MOD;
                        }
                    } else {
                        dp[i][x][y][0] = (dp[i][x][y][0] + dp[j][x][y][0] % MOD);
                        if (x < Y && y != 2) {
                            dp[i][x][y + 1][0] = (dp[i][x][y + 1][0] + dp[j][x][y][1]) % MOD;
                        }
                    }
                }
            }
        }
    }

    // Modify Y
    if (Y < X) Y = 0;
    else if (Y == X) Y = 1;
    else Y = 2;

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = (result + dp[i][X][Y][0]) % MOD;
        result = (result + dp[i][X][Y][1]) % MOD;
    }

    cout << result;
    
    return 0;
}