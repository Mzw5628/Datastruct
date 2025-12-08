#include "stack.h"
#include <iostream>

namespace ds {

stack::stack()
    : len(0) { };
stack::~stack() { }

void stack::push(int x)
{
    arr[len] = x;
    ++len;
}

void stack::pop()
{
    --len;
}

bool stack::empty()
{
    return len == 0;
}

void stack::print()
{
    for (int i = 0; i < len; ++i) {
        std::cout<<arr[i]<<' ';
    }
    std::cout<<'\n';
}
int stack::size()
{
    return len;
}


}
