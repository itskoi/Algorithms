#include <cstring>
#include "Disjoint.h"

Disjoint::Disjoint(int maxSize) {
    _Root = new int[maxSize];
    _Rank = new int[maxSize];
    for (int i = 0; i < maxSize; i++) _Root[i] = i;
    memset(_Rank, 0, sizeof _Rank);
}

Disjoint::~Disjoint() {
    delete[] _Root;
    delete[] _Rank;
}

int Disjoint::getRoot(int u) {
    return _Root[u] == u ? u : _Root[u] = getRoot(_Root[u]);
}

void Disjoint::merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u != v) {
        if (_Rank[u] < _Rank[v]) {
            _Root[u] = _Root[v];
        } else if (_Rank[u] > _Rank[v]) {
            _Root[v] = _Root[u];
        } else {
            _Root[u] = _Root[v];
            _Rank[v]++;
        }
    }
}

bool Disjoint::find(int u, int v) {
    return getRoot(u) == getRoot(v);
}
