#pragma once

class Node {
private:    
    int _Data;
    Node* _Ancestor;
    Node* _Left;
    Node* _Right;

public:
    Node(int val);
    void setData(int val);
    void setAncestor(Node *pNode);
    void setLeft(Node* pNode);
    void setRight(Node* pNode);
    int getData();
    Node* getAncestor();
    Node* getLeft();
    Node* getRight();
};

class BST {
private:
    Node* _Root;
    int _Size;

public:
    BST();
    ~BST();
    bool isEmpty();
    int getSize();
    void insert(int val);
    void erase(int key);
    Node* search(int key);
    Node* getRoot();
    void print(Node* root);
};