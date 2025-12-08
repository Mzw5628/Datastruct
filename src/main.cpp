#include "linked_list/linked_list.h"

void list_test()
{
    ds::LinkedList list; 
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();

}
int main() {
    list_test();
    return 0;
}
