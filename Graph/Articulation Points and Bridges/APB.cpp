#include "APB.h"

APB::APB(int n, int m) {
    _NumNode = n;
    _NumNode = m;
    _Clock = 0;
    //
    _Low.assign(n, 0);
    _Dis.assign(n, 0);
    _Adj = new vector<int>[n];
}

APB::~APB() {
    delete[] _Adj;
}

void APB::addEdges(int u, int v) {
    _Adj[u].push_back(v);
    _Adj[v].push_back(u);
}

void APB::DFS(int u, int p) {
    int child = 0;
    _Dis[u] = _Low[u] = ++_Clock;
    for (auto v : _Adj[u]) {
        if (v == p) continue;
        if (_Low[v] != 0) {
            _Low[u] = min(_Low[u], _Dis[v]);
        } else {
            DFS(v, u);
            child++;
            _Low[u] = min(_Low[u], _Low[v]);
            // Determine Articulation point
            if (u != p && _Low[v] >= _Dis[u]) {
                AP.push_back(u);
            }
            if (u == p && child >= 2) {
                AP.push_back(u);
            }
            // Determine Articulation bridge
            if (_Low[v] > _Dis[u]) {
                AB.push_back({u, v});
            }
        }
    }
}

void APB::printResult() {
    reverse(AP.begin(), AP.end());
    cout << AP.size() << endl;
    for (auto u : AP) {
        cout << u << " ";
    }
    reverse(AB.begin(), AB.end());
    cout << endl << AB.size() << endl;
    for (auto it : AB) {
        cout << it.first << " " << it.second << endl;
    }
}

void APB::debug() {
    for (auto it : _Low) {
        cout << it << " ";
    }
}