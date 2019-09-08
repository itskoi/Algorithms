#include "Dijsktra.h"

Dijsktra::Dijsktra(int N) {
    _NumNode = N;
    _Adj = new vector<pii>[N + 1];
    _Dis = new long long[N + 1];
    for (int i = 1; i <= N; i++) {
        _Dis[i] = 1e9;
    }
}

Dijsktra::~Dijsktra() {
    delete[] _Adj;
    delete[] _Dis;
}

void Dijsktra::addEdge(int u, int v, int w) {
    _Adj[u].push_back({v, w});
    //_Adj[v].push_back({u, w});
}

void Dijsktra::getMinDis(int scr) {
    _Dis[scr] = 0; 
    pq.push({0, scr});
    while(!pq.empty()) {
        auto top = pq.top();
        int u = top.second;
        pq.pop();
        if (top.first != _Dis[u]) {
            continue;
        }
        for (auto it : _Adj[u]) {
            int v = it.first;
            long long w = it.second;
            if (_Dis[v] > _Dis[u] + w) {
                _Dis[v] = _Dis[u] + w;
                pq.push({_Dis[v], v});
            }
        }
    }
    for (int i = 2; i <= _NumNode; i++) {
        if (_Dis[i] < 1e9) {
            cout << _Dis[i] << " ";
        } else {
            cout << 1000000000 << " ";
        }
    }
}