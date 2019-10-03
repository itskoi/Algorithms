#include "HamiltonianPath.h"

HamiltonianPath::HamiltonianPath(int n) {
    _NumNode = n;
    adj = new vector<int>[n + 1];
    //memset(dp, false, sizeof(dp[0][0]) * 10101 * 20);
}

void HamiltonianPath::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool HamiltonianPath::checkHamPath() {
    for (int i = 0; i < _NumNode; i++) {
        dp[1 << i][i] = true;
    }
    // 
    for (int i = 0; i < (1 << _NumNode); i++) {
        for (int u = 0; u < _NumNode; u++) {
            // if uth bit is set in i
            if (i & (1 << u)) {
                for (auto v : adj[u]) {
                    if (dp[i ^ (1 << u)][v] && (i & (1 << v))) {
                        dp[i][u] = true;
                        break;
                    }
                }
            }
        }
    }
    //
    for (int u = 0; u < _NumNode; u++) {
        if (dp[(1 << _NumNode) - 1][u]) return true;
    }
    return false;
}
