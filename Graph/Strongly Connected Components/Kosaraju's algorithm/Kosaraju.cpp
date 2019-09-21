#include "Kosaraju.h"

Kosaraju::Kosaraju(int n) {
    _NumNode = n;
    adj = new vector<int>[n + 1];
    radj = new vector<int>[n + 1];
    visited = new bool[n + 1];
    memset(visited, false, sizeof(visited[0]) * (_NumNode + 1));
    // Result
    _Odd = _Even = _Count = 0;
}

Kosaraju::~Kosaraju() {
    delete[] adj;
    delete[] radj;
    delete[] visited;
}

void Kosaraju::addEdge(int u, int v) {
    adj[u].push_back(v);
    radj[v].push_back(u);
}

void Kosaraju::dfs(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
    st.push(u);
}

void Kosaraju::findSCC() {
    for (int i = 1; i <= _NumNode; i++) {
        if (!visited[i]) this->dfs(i);
    }
    // Reset tracker
    memset(visited, false, sizeof(visited[0]) * (_NumNode + 1));
    // Travel through reverse graph
    while (!st.empty()) {
        if (visited[st.top()]) {
            _Count++;
            //cout << st.top() << " ";
            st.pop();
            continue;
        }
        if (_Count != 0) {
            if (_Count % 2 == 0)
                _Even += _Count;
            else
                _Odd += _Count;
        }
        _Count = 1;
        reachable(st.top());
        st.pop();
        
    }
    if (_Count != 0) {
        if (_Count % 2 == 0)
            _Even += _Count;
        else
            _Odd += _Count;
    }
}

void Kosaraju::reachable(int u) {
    visited[u] = true;
    for (auto v : radj[u]) {
        if (visited[v]) continue;
        reachable(v);
    }
}

void Kosaraju::printResult() {
    cout << _Odd -  _Even;
}