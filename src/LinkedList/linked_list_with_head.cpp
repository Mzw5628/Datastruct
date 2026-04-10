#include "linked_list.h"
#include <cstdio>

namespace ds {

LinkedListWithHead::LinkedListWithHead()
{
    Head = new Node(0);
}

void LinkedListWithHead::insert_head(int x)
{
    Node* p = new Node(x);
    p->next = Head->next;
    Head->next = p;
}

void LinkedListWithHead::insert_rear(int x)
{
    Node* temp = Head;
    while (temp->next) {
        temp = temp->next;
    }
    Node* p = new Node(x);
    p->next = nullptr;
    temp->next = p;
}

void LinkedListWithHead::insert(int x, int k)
{
    Node* pos = search(x);
    if (pos != nullptr) {
        Node* p = new Node(k);
        p->next = pos->next;
        pos->next = p;
    }
}

Node* LinkedListWithHead::search(int x)
{
    Node* p = Head;
    while (p && p->val != x) {
        p = p->next;
    }

    if (p == nullptr) {
        printf("there is no %d in the List\n", x);
        return nullptr;
    } else {
        return p;
    }
}

void LinkedListWithHead::remove(int x)
{
    Node* p = Head;
    while (p->next && p->next->val != x) {
        p = p->next;
    }
    if (p->next != nullptr) {
        Node* temp = p->next;
        p->next = temp->next;
        delete temp;
    } else {
        printf("there is no %d in the List\n", x);
    }
}

void LinkedListWithHead::change(int x, int k)
{
    Node* p = search(x);
    if (p != nullptr) {
        p->val = k;
    }
}

void LinkedListWithHead::print()
{
    Node* p = Head->next;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

}