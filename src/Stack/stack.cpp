#include "stack.h"
#include <iostream>

#define MAX_SIZE 1000
namespace ds {

stack::stack()
    : arr(nullptr),len(0) { };
stack::~stack() { }

void stack::push(int x)
{
    if (len == MAX_SIZE) {
        std::cout<<"Stack is full\n";
    }
    arr[len] = x;
    ++len;
}

void stack::pop()
{
    if (len == 0) {
        std::cout<<"Stack is empty\n";
    }
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
