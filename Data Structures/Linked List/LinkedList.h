#pragma once

class Node {
private:
    int _Data;
    Node* _Next;
public:
    Node();
    ~Node();
    void setData(int val);
    void setLink(Node* link);
    int getData();
    Node* getLink();
};

class LinkedList {
private:
    Node* _pHead;
    Node* _pPrevTail;
    Node* _pTail;
    int _Size;
public:
    LinkedList();
    ~LinkedList();
    void insert(int val);
    void deleteKey(int key);
    void printList();
};