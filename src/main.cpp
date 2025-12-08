#include "Stack/stack.h"
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
int main() {
    // list_test();
    stack_test();
    return 0;
}
