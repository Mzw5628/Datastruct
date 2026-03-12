#pragma once
#include <cstdio>
namespace ds {

// 用数组存储的树,父母表示法,并查集
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
    void DFS(BTreeNode* r);
    void BFS(BTreeNode* r);
    BTreeNode* getRoot();

private:
    BTreeNode* root;
};

// BST二叉排序树
struct BSTreeNode {
    int data;
    BSTreeNode* left;
    BSTreeNode* right;
};

class BStree {
public:
    BStree();
    void insert(int data);
    BSTreeNode* search(int data);
    void remove(int data);
    void inOrder(BSTreeNode* r);
    BSTreeNode* getNode();

private:
    BSTreeNode* root;
};

// 平衡二叉树
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int h;
};

class AVLtree {
public:
    AVLtree();
    int max(int a, int b);
    int geth(AVLNode* x);
    AVLNode* CreateNode(int data);
    AVLNode* LLrotation(AVLNode* x);
    AVLNode* RRrotation(AVLNode* x);
    AVLNode* LRrotation(AVLNode* x);
    AVLNode* RLrotation(AVLNode* x);
    AVLNode* search(int data);
    void inorder();
    void insert(int data);
    AVLNode* getRoot();

private:
    AVLNode* insert(int data, AVLNode* root);
    void inorder(AVLNode* p);
    
    AVLNode* root;
};
}