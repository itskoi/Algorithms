#include "BST.h"
#include <iostream>

using namespace std;

/*****************
*****> NODE <*****
*****************/

Node::Node(int val): _Data(val) {
    _Left = _Right = _Ancestor = nullptr;
}

void Node::setData(int val) {
    this->_Data = val;
}

void Node::setAncestor(Node* pNode) {
    this->_Ancestor = pNode;
}

void Node::setLeft(Node* pNode) {
    this->_Left = pNode;
}

void Node::setRight(Node* pNode) {
    this->_Right = pNode;
}

int Node::getData() {
    return this->_Data;
}

Node* Node::getAncestor() {
    return this->_Ancestor;
}

Node* Node::getLeft() {
    return this->_Left;
}

Node* Node::getRight() {
    return this->_Right;
}

/*****************
*****> BST <******
*****************/

BST::BST() {
    _Size = 0;
    _Root = new Node(-1);
}

BST::~BST() {

}

bool BST::isEmpty() {
    return _Size == 0;
}

int BST::getSize() {
    return _Size;
}

void BST::insert(int val) {
    if (this->isEmpty()) {
        _Root->setData(val);
    } else {
        Node* pCrawl = _Root;
        while(pCrawl != nullptr) {
            if (val > pCrawl->getData()) {
                if (pCrawl->getRight() == nullptr) {
                    pCrawl->setRight(new Node(val));
                    pCrawl->getRight()->setAncestor(pCrawl);
                    break;
                } else {
                    pCrawl = pCrawl->getRight();
                }

            }
            if (val <= pCrawl->getData()) {
                if (pCrawl->getLeft() == nullptr) {
                    pCrawl->setLeft(new Node(val));
                    pCrawl->getLeft()->setAncestor(pCrawl);
                    break;
                } else {
                    pCrawl = pCrawl->getLeft();
                }
            }
        }
    }
    _Size++;
}

Node* BST::search(int key) {
    Node* pCrawl = _Root;
    while(pCrawl != nullptr) {
        if (key == pCrawl->getData()) return pCrawl;
        if (key > pCrawl->getData()) {
            pCrawl = pCrawl->getRight();
        } else {
            pCrawl = pCrawl->getLeft();
        }
    }
    return nullptr;
}

void BST::erase(int key) {
    Node* delNode = search(key);
    if (delNode == nullptr) return;

    // delMode is a leaf
    if (!delNode->getLeft() && !delNode->getRight()) {
        Node* pDad = delNode->getAncestor();
        if (pDad->getLeft() == delNode) {
            pDad->setLeft(nullptr);
        } else {
            pDad->setRight(nullptr);
        }
        delete delNode;
        return;
    }

    // delNode has 1 child
    // Left
    if (delNode->getLeft() && !delNode->getRight()) {
        // if delNode is the root
        if (delNode == _Root) {
            _Root = delNode->getLeft();
            delete delNode;
        } else { // Just erase then replace by its child
            Node* pDad = delNode->getAncestor();
            if (pDad->getLeft() == delNode) {
                pDad->setLeft(delNode->getLeft());
            } else {
                pDad->setRight(delNode->getLeft());
            }
            delete delNode;
        }
        return;
    }
    // Right
    if (!delNode->getLeft() && delNode->getRight()) {
        // if delNode is the root
        if (delNode == _Root) {
            _Root = delNode->getRight();
            delete delNode;
        } else { // Just erase then replace by its child
            Node* pDad = delNode->getAncestor();
            if (pDad->getLeft() == delNode) {
                pDad->setLeft(delNode->getRight());
            } else {
                pDad->setRight(delNode->getRight());
            }
            delete delNode;
        }
        return;
    }

    // Difficult part !!! Node has 2 children
    // 2 ways: the right most in left child or the left most in right child
    // We use the first way: the right most in left child
    Node* pCrawl = delNode->getLeft();
    while(pCrawl->getRight() != nullptr) {
        pCrawl = pCrawl->getRight();
    }
    // Create a new KING
    Node* pReplace = new Node(pCrawl->getData());
    // Erase pCrawl (UPDATE) | Erase node with 1 child
    this->erase(pCrawl->getData());
    // make a link btw delNode's dad with pReplace
    Node* pDad = delNode->getAncestor();
    pReplace->setAncestor(pDad);
    if (pDad->getLeft() == delNode) {
        pDad->setLeft(pReplace);
    } else {
        pDad->setRight(pReplace);
    }
    // Being new node
    pReplace->setLeft(delNode->getLeft());
    pReplace->setRight(delNode->getRight());
    // delete delNode
    delete delNode;
}

void BST::print(Node* root) {
    // Oder: L M R
    if (root->getLeft()) print(root->getLeft());
    std::cout << root->getData() << " ";
    if (root->getRight()) print(root->getRight());
}

Node* BST::getRoot() {
    return _Root;
}
