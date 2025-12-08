#include "queue.h"

using namespace std;

namespace ds {

const int MAXSIZE = 1000;

queue::queue()
    : front(0)
    , rear(0)
{
    arr = new int[MAXSIZE];
}

queue::queue(int len)
    : front(0)
    , rear(0)
{
    arr = new int[len];
}

queue::~queue()
{
    delete[] arr;
}

void queue::push(int x)
{
    arr[rear] = x;
    rear = (rear + 1) % MAXSIZE;
}

void queue::pop()
{
    front = (front + 1) % MAXSIZE;
}

void queue::print()
{
    while (front != rear) {
        std::cout << arr[front] << ' ';
        front = (front + 1) % MAXSIZE;
    }
    cout << '\n';
}

}