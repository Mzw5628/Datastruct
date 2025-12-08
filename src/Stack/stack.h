#pragma once
#include <iostream>
#define MAXSIZE 1000
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
    int arr[MAXSIZE];
    int len;
};
}