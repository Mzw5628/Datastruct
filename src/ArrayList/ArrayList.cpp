#include "ArrayList.h"
#include <cstdio>

namespace ds {

ArrayList::ArrayList():size(0),maxSize(10)
{
    arr = new int[maxSize];
}

ArrayList::~ArrayList()
{
    delete[] arr;
}

void ArrayList::push(int x)
{
    if (size >= maxSize) {
        printf("The array is full.\n");
    } else {
        arr[size] = x;
        size++;
    }
}

void ArrayList::insert(int x, int pos)
{
    if (size >= maxSize) {
        printf("The array is full.\n");
    } else {
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = x;
    }
}

void ArrayList::remove(int pos)
{
    if (pos < 1 || pos > size) {
        printf("Input out of size");
    } else {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size] = 0;
        size--;
    }
}

bool ArrayList::search(int x)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;
}

void ArrayList::print()
{
    if (size <= 0) {
        printf("there is no number");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
}