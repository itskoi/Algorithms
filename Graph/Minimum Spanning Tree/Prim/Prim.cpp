#include "Prim.h"

using namespace std;

Prim::Prim(int N) {
    this->_NumNode = N;
    _Marked = new bool[N + 1];
    adj = new vector<pii>[N + 1];
    for (int i = 1; i <= _NumNode; i++) {
        _Marked[i] = false;
    }
}

Prim::~Prim() {
    delete[] _Marked;
}

void Prim::addEdge(int u, int v, int d) {
    adj[u].push_back(make_pair(v, d));
    adj[v].push_back(make_pair(u, d));
}

void Prim::findMinSpanTree() {
    int result = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (_Marked[u]) continue;
        _Marked[u] = true;
        result += d;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first;
            int w = it->second;
            if (!_Marked[v]) pq.push(make_pair(w, v));
        }
    }
    cout << result;
}