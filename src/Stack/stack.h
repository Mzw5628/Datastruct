#pragma once
#include <iostream>
namespace ds {

class stack {

public:
    stack();
    ~stack();
    void push(int x);
    void pop();
    bool empty();
    void print();
    int size();

private:
    int *arr;
    int len;
};
}