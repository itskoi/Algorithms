#pragma once

class Disjoint {
    private:
        int* _Root = nullptr;
        int* _Rank = nullptr;
    public:
        Disjoint(int);
        ~Disjoint();
        int getRoot(int);
        void merge(int, int);
        bool find(int, int);
};