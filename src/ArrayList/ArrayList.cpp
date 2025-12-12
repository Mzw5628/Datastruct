#include "ArrayList.h"
#include <cstdio>

namespace ds {

ArrayList::ArrayList()
    : size(0)
    , maxSize(10)
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

void ArrayList::remove(int x)
{
    int i = find(x);
    if (i == -1) {
        return;
    } else {
        for (int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    }
}

int ArrayList::find(int x)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    printf("there is no %d in data\n", x);
    return -1;
}

void ArrayList::change(int x, int y)
{
    int pos = find(x);
    if (pos != -1) {
        arr[pos] = y;
    }
}

void ArrayList::print()
{
    if (size <= 0) {
        printf("there is no number\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
}