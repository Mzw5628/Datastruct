#include "ArrayList/ArrayList.h"
#include "Queue/queue.h"
#include "Stack/stack.h"
#include "linked_list/linked_list.h"
#include <iostream>


// 链表测试
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

// 栈测试
void stack_test()
{
    ds::stack st;
    st.push(3);
    st.push(5);
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(8);
    st.print();
    st.pop();
    st.pop();
    st.pop();
    st.print();
}
// 队列测试
void queue_test()
{
    ds::queue q(1000);
    for (int i = 0; i < 999; ++i) {
        q.push(i + 1);
    }
    for (int i = 0; i < 99; ++i) {
        q.pop();
    }
    for (int i = 0; i < 9; ++i) {
        q.push(1000);
    }
    q.print();
}

// 双向链表测试
void doubeList_test()
{
    ds::doublyList dlist;
    dlist.push_front(99);
    dlist.push_back(5);
    dlist.push_back(6);
    dlist.push_back(7);
    dlist.push_front(1);
    dlist.push_front(2);
    dlist.push_front(3);
    dlist.print();
    std::cout << dlist.size();
}

// 循环链表测试
void circleList_test()
{
    ds::circleList cList;
    cList.push_back(5);
    cList.push_back(6);
    cList.push_back(7);
    cList.push_front(1);
    cList.push_front(2);
    cList.push_front(3);
    cList.print(cList.size());
    cList.insert(50, 5);
    cList.print(cList.size());
    cList.remove(4);
    cList.print(cList.size());
    cList.print(15);
}

// 顺序表测试
void array_test()
{
    ds::ArrayList array;
    array.print();
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.push(6);
    array.push(7);
    array.print();
    array.insert(10, 0);
    array.print();
    array.remove(6);
    array.print();
    array.change(6, 99);
    array.print();
}

int main()
{
    // list_test();
    // stack_test();
    // queue_test();
    // doubeList_test();
    // circleList_test();
    array_test();
    return 0;
}
