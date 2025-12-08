#pragma once
#include <iostream>

namespace ds {

struct Node {
    int val;
    Node* next;
    
    Node(int v)
        : val(v)
        , next(nullptr)
    {
    }
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void push_front(int x);
    void push_back(int x);
    bool empty() const;
    void print() const;
    int size() const;

private:
    Node* head;
    Node* tail;
    int len;
};

} // namespace ds
