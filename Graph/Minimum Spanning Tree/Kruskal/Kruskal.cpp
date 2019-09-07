#include "Kruskal.h"
#include <algorithm>

Kruskal::Kruskal(int N) {
    this->_NumNode = N;
    _Root = new int[_NumNode + 1];
    _Level = new int[_NumNode + 1];
    for (int i = 1; i <= _NumNode; i++) {
        _Root[i] = i;
        _Level[i] = 0;
    }
}

Kruskal::~Kruskal() {
    delete[] _Root;
}

void Kruskal::addEdge(int u, int v, int d) {
    _Edges.push_back(make_pair(d, make_pair(u, v)));
}

int Kruskal::getRoot(int u) {
    return _Root[u] == u ? u : _Root[u] = getRoot(_Root[u]);
}

void Kruskal::mergeRoot(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);

    // Union by rank
    if (_Level[u] > _Level[v]) {
        _Root[v] = u;
    } else if (_Level[v] > _Level[u]) {
        _Root[u] = v;
    } else {
        _Root[v] = u;
        _Level[u]++;
    }
}

int Kruskal::getSumSpanningTree() {
    int result = 0;
    sort(_Edges.begin(), _Edges.end());
    for (auto it = _Edges.begin(); it != _Edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;
        int d = it->first;
        if (getRoot(u) != getRoot(v)) {
            mergeRoot(u, v);
            result += d;
        }
    }
    return result;
}