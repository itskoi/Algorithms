#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

class Tarjan {
private:
    vector<int>* adj;
    stack<int> st;
    int* low;
    int* dis;
    bool* onStack;
    int _NumNode;
    int _Timer;
    int _Even; // Number of SCC has even vertices
    int _Odd;  // Number of SCC has odd vertices
public:
    Tarjan(int);
    ~Tarjan();
    void addEdge(int, int);
    void findSCC();
    void DFS(int);
    void printResult();
};