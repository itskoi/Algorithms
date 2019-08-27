#include "LinkedList.h"
#include <iostream>

// Node declaration

Node::Node() {
    _Data = 0;
    _Next = nullptr;
}

Node::~Node() {

}

void Node::setData(int val) {
    _Data = val;
}

void Node::setLink(Node* link) {
    _Next = link;
}

int Node::getData() {
    return _Data;
}

Node* Node::getLink() {
    return _Next;
}

// Linked list declaration

LinkedList::LinkedList() {
    _pHead = new Node();
    _pTail = new Node();
    _pPrevTail= new Node();
    _Size = 0;
}

LinkedList::~LinkedList() {
    while(_pHead != nullptr) {
        Node* pCrawl = _pHead;
        _pHead = _pHead->getLink();
        delete pCrawl;
    }
}

void LinkedList::insert(int val) {
    // Initialize for new node
    Node* pCrawl = new Node();
    pCrawl->setData(val);
    pCrawl->setLink(nullptr);

    // Add node to linked list
    if (!_Size) {
        _pHead = _pTail = _pPrevTail = pCrawl;
    } else {
        _pTail->setLink(pCrawl);
        _pPrevTail = _pTail;
        _pTail = pCrawl;
    }
    _Size++;
}

void LinkedList::deleteKey(int key) {
    Node* pCrawl = _pHead;
    while(pCrawl != nullptr) {
        Node *delNode = pCrawl->getLink(); // pCrawl --> delNode -->
        if (delNode->getData() == key) { // The delnode has been found
            pCrawl->setLink(delNode->getLink());
            delete delNode;
            return;
        }
        pCrawl = delNode;
    }
}

void LinkedList::printList() {
    Node* pCrawl = _pHead;
    while(pCrawl != nullptr) {
        std::cout << pCrawl->getData() << " ";
        pCrawl = pCrawl->getLink();
    }
    std::cout << std::endl;
}
