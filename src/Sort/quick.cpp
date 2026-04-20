#include "sort.h"
namespace ds {
    // quick sort

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            ++i;
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right) {
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}
}