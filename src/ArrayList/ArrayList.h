#pragma once
#include <cstdio>

namespace ds {

class ArrayList {
public:
    ArrayList();
    ~ArrayList();

    void push(int x);
    void insert(int x, int pos);
    void remove(int x);
    int find(int x);
    void change(int x, int y);
    void print();

private:
    int* arr;
    int size;
    const int maxSize;
};

}