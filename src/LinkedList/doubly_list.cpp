#include "linked_list.h"
#include <cstdio>
namespace ds {
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
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int doublyList::size() const
{
    return len;
}

}