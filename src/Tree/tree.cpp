#include "tree.h"
#include <cstdio>

namespace ds {
tree::tree(char x)
{
    arr = new treeNode[100];
    arr[0].data=x;
    arr[0].parent = -1;
    size=1;
}

tree::~tree()
{
    delete[] arr;
}

int tree::exist(char x)
{
    for (int i = 0; i < size; i++) {
        if (arr[i].data == x)
            return i;
    }
    return -1;
}

void tree::insert(char x, char parent)
{
    arr[size].data = x;
    arr[size].parent = exist(parent);
    size++;
};

void tree::find_parent(char x)
{
    int i = exist(x);
    if (i == -1) {
        printf("%c is root Node\n", x);
    } else {
        int parent_id = arr[i].parent;
        char ch = arr[parent_id].data;
        printf("%c `s parents are %c\n", x, ch);
    }
}
};