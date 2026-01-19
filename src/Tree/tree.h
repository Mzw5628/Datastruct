#pragma once
#include <cstdio>

namespace ds {

// 用数组存储的树
struct arrayTreeNode {
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
    arrayTreeNode* arr;
    int size;
};

// BtreeNode二叉树结点
struct BTreeNode {
    char data;
    BTreeNode* left;
    BTreeNode* right;
};

class BTree {
public:
    BTree();

    void perOrderBT(BTreeNode* r);
    BTreeNode* getRoot();
private:
    BTreeNode* root;
};

}