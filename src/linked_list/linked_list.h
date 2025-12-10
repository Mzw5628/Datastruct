#pragma once
#include <iostream>

namespace ds {

// 该节点只有指向后续节点的指针
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

// 该节点有指向前后节点的指针
struct doublyNode {
    int data;
    doublyNode* pre;
    doublyNode* next;
    doublyNode(int x)
        : data(x)
        , pre(nullptr)
        , next(nullptr)
    {
    }
};

class doublyList {
public:
    doublyList();
    ~doublyList();
    void push_front(int x);
    void push_back(int x);
    bool empty() const;
    void print() const;
    int size() const;

private:
    doublyNode* head;
    doublyNode* tail;
    int len;
};

class circleList {
public:
    circleList();
    ~circleList();

    void push_back(int x);
    void push_front(int x);
    void insert(int x, int pos);
    void remove(int pos);
    void print(int length);
    bool empty();
    int size();

private:
    Node* head;
    Node* tail;
    int len;
};
} // namespace ds
