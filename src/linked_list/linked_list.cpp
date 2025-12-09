#include "linked_list.h"

namespace ds {

// 链表
LinkedList::LinkedList()
    : head(nullptr)
    , tail(nullptr)
    , len(0)
{
}

LinkedList::~LinkedList()
{
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void LinkedList::push_front(int x)
{
    Node* n = new Node(x);
    n->next = head;
    head = n;
    if (tail == nullptr)
        tail = n;
    ++len;
}

void LinkedList::push_back(int x)
{
    Node* n = new Node(x);
    if (head == nullptr)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }
    ++len;
}

bool LinkedList::empty() const
{
    return head == nullptr;
}

void LinkedList::print() const
{
    Node* cur = head;
    while (cur) {
        std::cout << cur->val << ' ';
        cur = cur->next;
    }
}

int LinkedList::size() const
{
    return len;
}

// 双向链表
doublyList::doublyList()
    : head(nullptr)
    , tail(nullptr)
    , len(0)
{
}

doublyList::~doublyList()
{
    while (head != nullptr) {
        doublyNode* next = head->next;
        delete head;
        head = next;
    }
}

void doublyList::push_front(int x)
{
    doublyNode* p = new doublyNode(x);
    // 防止最开始head为nullptr的情况，添加if
    if (head) {
        p->next = head;
        p->pre = head->pre;
        head->pre = p;
        head = p;
        len++;

    } else {
        head = tail = p;
        len++;
    }
}

void doublyList::push_back(int x)
{
    doublyNode* p = new doublyNode(x);
    // 防止最开始tail为nullptr的情况，添加if
    if (tail) {
        p->next = tail->next;
        p->pre = tail;
        tail->next = p;
        tail = p;
        len++;

    } else {
        tail = head = p;
        len++;
    }
}

bool doublyList::empty() const
{
    return len == 0;
}

void doublyList::print() const
{
    doublyNode* front = head;
    while (front) {
        std::cout << front->data << ' ';
        front = front->next;
    }
    std::cout << '\n';
}

int doublyList::size() const
{
    return len;
}

}