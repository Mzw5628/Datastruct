#include "linked_list/linked_list.h"

int main() {
    ds::LinkedList list; 
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();
    return 0;
}
