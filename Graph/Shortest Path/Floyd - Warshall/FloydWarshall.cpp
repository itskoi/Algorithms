#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int adj[100][100];
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j) adj[i][j] = 1e9;
            else adj[i][j] = 0;
        }
    }
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        cout << adj[1][i] << " ";
    }
    return 0;
}