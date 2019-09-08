#include "BellmanFord.h"

BellmanFord::BellmanFord(int N) {
    _NumNode = N;
    _Dis = new long long[N + 1];
    for (int i = 1; i <= N; i++) {
        _Dis[i] = 1e9;
    }
}

BellmanFord::~BellmanFord() {
    delete[] _Dis;
}

void BellmanFord::addEdge(int u, int v, int d) {
    _Edges.push_back({d, {u, v}});
}

void BellmanFord::getMinDis(int scr) {
    _Dis[scr] = 0;
    for (int i = 1; i < _NumNode; i++) {
        for (auto it : _Edges) {
            long long w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (_Dis[v] > _Dis[u] + w) {
                _Dis[v] = _Dis[u] + w;
            }
        }
    }
    for (int i = 2; i <= _NumNode; i++) {
        cout << _Dis[i] << " ";
    }
} 