#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

class BC {
private:
    int _EvenResult;
    int _OddResult;
    int _NumNodes;
    int _NumEdges;
    int _timer;
    vector<int>* adj;
    stack<pii> st;
    map<int, bool> mark;
    int* low;
    int* dis;
    bool* visited;
public:
    BC(int, int);
    ~BC();
    void addEdges(int, int);
    void DFS(int, int);
    void printResult();
    void findBC();
};