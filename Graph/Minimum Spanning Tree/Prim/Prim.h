#pragma once
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

class Prim {
private:
    vector<pii>* adj;
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    int _NumNode;
    bool* _Marked;    
public:
    Prim(int);
    ~Prim();
    void addEdge(int, int, int);
    void findMinSpanTree();
};