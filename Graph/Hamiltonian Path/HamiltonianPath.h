#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class HamiltonianPath {
private:
    vector<int> *adj;
    bool dp[10101][20] = {false};
    int _NumNode;

public:
    HamiltonianPath(int);
    void addEdge(int, int);
    bool checkHamPath();
};