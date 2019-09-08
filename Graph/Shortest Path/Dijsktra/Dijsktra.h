#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, long long> pii;
class Dijsktra {
private:
    vector<pii>* _Adj;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    long long* _Dis;
    int _NumNode;

public:
    Dijsktra(int);
    ~Dijsktra();
    void addEdge(int, int, int);
    void getMinDis(int);
};
