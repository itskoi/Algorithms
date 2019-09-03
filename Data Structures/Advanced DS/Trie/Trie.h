#pragma once
#include <iostream>

class Node {
public:
    Node* _Next[26];
    bool _End;
    Node();
    ~Node();
};

class Trie {
private:
    Node* root = new Node();
public:
    ~Trie();
    void insert(std::string);
    bool find(std::string);
};