#include "linked_list.h"
#include <cstdio>

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

// 循环链表
circleList::circleList()
    : head(nullptr)
    , tail(nullptr)
    , len(0)
{
}

circleList::~circleList()
{
    if (head == nullptr)
        return;
    //处理尾指针
    tail->next = nullptr;

    Node* temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
    len = 0;
}

void circleList::push_back(int x)
{
    Node* p = new Node(x);
    if (tail == nullptr) {
        tail = head = p;
        head->next = tail;
        tail->next = head;
    } else {
        p->next = head;
        tail->next = p;
        tail = p;
    }
    len++;
}

void circleList::push_front(int x)
{
    Node* p = new Node(x);
    if (head == nullptr) {
        head = tail = p;
        head->next = tail;
        tail->next = head;
    } else {
        p->next = head;
        tail->next = p;
        head = p;
    }
    len++;
}

void circleList::insert(int x, int pos)
{
    if (pos < 1 || pos > len)
        return;
    if (pos == 1) {
        push_front(x);
        return;
    } else if (pos == len) {
        push_back(x);
        return;
    } else {
        Node* p = new Node(x);
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
        len++;
    }
};

void circleList::remove(int pos)
{
    if (pos < 1 || pos > len)
        return;

    Node* pre = head;
    if (pos == 1) {
        head = head->next;
        tail->next = head;
        delete pre;
    } else {
        for (int i = 1; i < pos - 1; i++) {
            // n为要删除的节点的前一个节点
            pre = pre->next;
        }
        Node* temp = pre->next;
        if (temp == tail)
            tail = pre;

        pre->next = temp->next;
        delete temp;
    }
    len--;
};

void circleList::print(int length)
{
    if (head == nullptr)
        return;
    Node* first = head;
    for (int i = 0; i < length; i++) {
        printf("%d ", first->val);
        first = first->next;
    }
    printf("\n");
}

bool circleList::empty()
{
    return len == 0;
}

int circleList::size()
{
    return len;
}

}