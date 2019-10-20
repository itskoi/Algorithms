#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next[26];
    Node() {
        data = -1e9;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        } 
    }
};

class Trie {
private:
    Node *root = nullptr;

public:
    Trie();
    ~Trie();
    void addString(string, int);
    int query(string);
};

int main() {
    int N, Q;
    Trie* trie = new Trie();
    cin >> N >> Q;
    while(N--) {
        string str;
        int val; 
        cin >> str >> val;
        trie->addString(str, val);
    }
    while(Q--) {
        string str;
        cin >> str;
        cout << trie->query(str) << endl;
    }
    return 0;
}

Trie::Trie() {
    root = new Node();
}

Trie::~Trie() {
    delete root;
}

void Trie::addString(string str, int val) {
    Node* crawl = this->root;
    for (auto x : str) {
        int idx = x - 'a';
        if (crawl->next[idx] == nullptr) crawl->next[idx] = new Node();
        crawl = crawl->next[idx];
        crawl->data = max(crawl->data, val);
    }
}

int Trie::query(string str) {
    Node* crawl = this->root;
    for (auto x : str) {
        int idx = x - 'a';
        if (crawl->next[idx] == nullptr) return -1;
        crawl = crawl->next[idx];
    }
    return crawl->data;
}