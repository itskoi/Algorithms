#include "Tarjan.h"

Tarjan::Tarjan(int n) {
    _NumNode = n;
    _Odd = _Even = _Timer = 0;
    adj = new vector<int>[n + 1];
    low = new int[n + 1];
    dis = new int[n + 1];
    onStack = new bool[n + 1];
    memset(onStack, false, sizeof(onStack[0]) * (n + 1));
    memset(low, 0, sizeof(low[0]) * (n + 1));
}

Tarjan::~Tarjan() {
    delete[] adj;
    delete[] low;
    delete[] dis;
}

void Tarjan::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Tarjan::printResult() {
    cout << _Odd - _Even;
}

void Tarjan::DFS(int u) {
    low[u] = dis[u] = ++_Timer;
    st.push(u);
    onStack[u] = true;
    for (auto v : adj[u]) {
        if (low[v] == 0) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], dis[v]);
        }
    }
    // if u is a root of SCC
    if (dis[u] == low[u]) {
        int _Count = 0;
        while(st.top() != u) {
            _Count++;
            onStack[st.top()] = false;
            st.pop();
        }
        onStack[st.top()] = false;
        _Count++;
        st.pop();
        if (_Count % 2 == 0) _Even += _Count;
        else _Odd += _Count;
    }
}

void Tarjan::findSCC() {
    for (int i = 1; i <= _NumNode; i++) {
        if (!low[i]) DFS(i);
    }
}