#include "BC.h"

BC::BC(int n, int m) {
    this->_NumNodes = n;
    this->_NumEdges = m;
    dis = new int[n];
    low = new int[n];
    visited = new bool[n];
    memset(visited, false, sizeof visited);
    memset(low, 0, sizeof low);
    memset(dis, 0, sizeof dis);
    adj = new vector<int>[n];
    _OddResult = _EvenResult = 0;
    _timer = 0;
}

BC::~BC() {
    delete[] dis;
    delete[] low;
    delete[] adj;
}

void BC::addEdges(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BC::printResult() {
    cout << _OddResult << " " << _EvenResult;
}

void BC::DFS(int u, int p) {
    dis[u] = low[u] = _timer++;
    visited[u] = true;
    int child = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            if (low[u] > dis[v]) {
                low[u] = dis[v];
                st.push({u, v});
            }
        } else {
            st.push({u, v});
            child++;
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (child >= 2 && u == p) {
                int tmp = 0;
                while(st.top() != pii(u, v)) {
                    if (!mark[st.top().first]) {
                        tmp++;
                        mark[st.top().first] = true;
                    }
                    if (!mark[st.top().second]) {
                        tmp++;
                        mark[st.top().second] = true;
                    }
                    st.pop();
                }
                st.pop();
                if (!mark[u]) tmp++;
                if (!mark[v]) tmp++;
                if (tmp % 2 == 0) _EvenResult++;
                else _OddResult++;
                mark = map<int, bool>();
            }
            if (u != p && low[v] >= dis[u]) {
                int tmp = 0;
                while(st.top() != pii(u, v)) {
                    if (!mark[st.top().first]) {
                        tmp++;
                        mark[st.top().first] = true;
                    }
                    if (!mark[st.top().second]) {
                        tmp++;
                        mark[st.top().second] = true;
                    }
                    st.pop();
                }
                st.pop();
                if (!mark[u]) tmp++;
                if (!mark[v]) tmp++;
                if (tmp % 2 == 0) _EvenResult++;
                else _OddResult++;
                mark = map<int, bool>();
            }
        }
    }
}

void BC::findBC() {
    for (int i = 0; i < _NumNodes; i++) {
        if (!visited[i]) {
            DFS(i, i);
            int tmp = 0;
            while(!st.empty()) {
                if (!mark[st.top().first]) {
                    tmp++;
                    mark[st.top().first] = true;
                }
                if (!mark[st.top().second]) {
                    tmp++;
                    mark[st.top().second] = true;
                }
                st.pop();
            }
            if (tmp % 2 == 0) _EvenResult++;
            else _OddResult++;
            mark = map<int, bool>();
        }
    }
}