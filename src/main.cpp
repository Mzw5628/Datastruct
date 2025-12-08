#include "Queue/queue.h"
#include "Stack/stack.h"
#include "linked_list/linked_list.h"

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
int main()
{
    // list_test();
    // stack_test();
    queue_test();
    return 0;
}
