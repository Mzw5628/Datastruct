#include "linked_list.h"

namespace ds {

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

}
