#pragma once
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

class Kruskal {
private:
    vector<piii> _Edges;
    int* _Root;
    int* _Level;
    int _NumNode;

public:
    Kruskal(int);
    ~Kruskal();
    void addEdge(int, int, int);
    void mergeRoot(int, int);
    int getRoot(int);
    int getSumSpanningTree();
};