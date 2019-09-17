#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

class APB {
private:
    vector<int>* _Adj;
    vector<int> _Low, _Dis;
    vector<int> AP;
    vector<pii> AB;
    int _NumNode, _NumEdges;
    int _Clock;
public:
    APB(int, int);
    ~APB();
    void addEdges(int, int);
    void DFS(int, int);
    void printResult();
    void debug();
};