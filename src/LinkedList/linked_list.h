#pragma once

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

// 链表
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

// 带头结点的链表
class LinkedListWithHead {
public:
    LinkedListWithHead();
    void insert_head(int x);
    void insert_rear(int x);
    // 在数据x后插入k
    void insert(int x, int k);
    Node* search(int x);
    void remove(int x);
    // 把数据x变成k
    void change(int x, int k);

    void print();

private:
    Node* Head;
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

// 双向链表
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

// 循环链表
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
