#include "Trie.h"
#include <iostream>

Node::Node()
{
    _End = false;
    for (int i = 0; i < 26; i++)
    {
        _Next[i] = nullptr;
    }
}

Node::~Node()
{
    for (int i = 0; i < 26; i++)
    {
        if (_Next[i] != nullptr)
        {
            delete _Next[i];
        }
    }
}

Trie::~Trie()
{
    delete this->root;
}

void Trie::insert(std::string str)
{
    Node *pCrawl = this->root;
    for (auto ch : str)
    {
        int idx = ch - 'a';
        if (pCrawl->_Next[idx] == nullptr)
        {
            pCrawl->_Next[idx] = new Node();
        }
        pCrawl = pCrawl->_Next[idx];
    }
    pCrawl->_End = true;
}

bool Trie::find(std::string str)
{
    Node *pCrawl = this->root;
    for (auto ch : str)
    {
        int idx = ch - 'a';
        if (pCrawl->_Next[idx] == nullptr)
        {
            return false;
        }
        pCrawl = pCrawl->_Next[idx];
    }
    return pCrawl->_End;
}