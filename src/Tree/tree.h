#pragma once
#include <cstdio>

namespace ds {

struct treeNode {
    char data;
    int parent;
};

class tree {

public:
    tree(char x);
    ~tree();
    int exist(char x);
    void insert(char x, char parent);
    void find_parent(char x);

private:
    treeNode* arr;
    int size;
};

}