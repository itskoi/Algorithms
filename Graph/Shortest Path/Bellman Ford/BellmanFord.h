#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

class BellmanFord {
private:
    vector<piii> _Edges;
    long long* _Dis;
    int _NumNode;
public:
    BellmanFord(int);
    ~BellmanFord();
    void addEdge(int, int, int);
    void getMinDis(int);
};