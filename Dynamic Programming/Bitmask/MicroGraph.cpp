// Hackerearth

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> adj[15];
int dp[11][4097];
bool dpp[11][4097];

bool getBit(int idx, int state) {
    return ((state >> (idx - 1)) & 1);
}

bool cmp(pii A, pii B) {
    return A.second < B.second;
}

int main() {
    // Input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // DP
    memset(dp, 0, sizeof(dp[0][0]) * 11 * 4097);
    memset(dpp, 0, sizeof(dpp[0][0]) * 11 * 4097);
    
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
        dpp[i][1 << (i - 1)] = true;
    }

    for (int state = 0; state < (1 << n); state++) {
        for (int u = 1; u <= n; u++) {
            if (getBit(u, state)) {
                for (auto it : adj[u]) {
                    int v = it.first;
                    int w = it.second;
                    if (getBit(v, state) && dpp[v][state ^ (1 << (u - 1))]) {
                        dp[u][state] = dp[v][state ^ (1 << (u - 1))] + w;
                        dpp[u][state] = true;
                        break;
                    }
                }
            }
        }
    }

    int result = 1e9;
    for (int i = 1; i <= n; i++) {
        if (dpp[i][(1 << n) - 1]) {
            result = min(result, dp[i][(1 << n) - 1]);
        }
    }
    cout << result;
    return 0;
}