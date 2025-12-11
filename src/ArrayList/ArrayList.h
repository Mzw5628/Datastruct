#pragma once
#include <cstdio>

namespace ds {

class ArrayList {
public:
    ArrayList();
    ~ArrayList();

    void push(int x);
    void insert(int x, int pos);
    void remove(int pos);
    bool search(int x);
    void print();

private:
    int* arr;
    int size;
    const int maxSize;
};

}