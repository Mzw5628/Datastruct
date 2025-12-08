#pragma once
#include <iostream>

namespace ds {

class queue {
public:
    queue();
    queue(int len);
    ~queue();
    void push(int x);
    void pop();
    void print();

private:
    int* arr;
    int front;
    int rear;
};
}