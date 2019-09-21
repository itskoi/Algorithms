#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

class Kosaraju {
private:
    vector<int>* adj;
    vector<int>* radj;
    stack<int> st;
    bool* visited;
    int _NumNode;
    int _Count; // Temporary variable to count num of vectices in SCC
    int _Odd; // Number of SCC has odd vertices
    int _Even; // Number of SCC has even vertices
public:
    Kosaraju(int);
    ~Kosaraju();
    void addEdge(int, int);
    void findSCC();
    void dfs(int);
    void reachable(int);
    void printResult();
};