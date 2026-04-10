#include "tree.h"
#include <cstdio>

namespace ds {

BStree::BStree()
{
    root = nullptr;
}

void BStree::insert(int data)
{
    if (!root) {
        root = new BSTreeNode { data, nullptr, nullptr };
        return;
    }
    BSTreeNode* node = new BSTreeNode { data, nullptr, nullptr };
    BSTreeNode* p = root;
    BSTreeNode* pre = nullptr;
    while (p) {
        pre = p;
        if (data > p->data) {
            p = p->right;
        } else if (data < p->data) {
            p = p->left;
        } else {
            printf("this number: %d has existed\n", data);
            return;
        }
    }
    if (data > pre->data) {
        pre->right = node;
    } else {
        pre->left = node;
    }
};

BSTreeNode* BStree::search(int data)
{
    BSTreeNode* p = root;
    while (p) {
        if (p->data == data) {
            printf("Find: %d in BSTree\n", data);
            return p;
        }
        if (data > p->data)
            p = p->right;
        else
            p = p->left;
    }
    printf("there is no %d\n", data);
    return nullptr;
}

void BStree::remove(int data)
{
    BSTreeNode* p = root;
    BSTreeNode* pre = nullptr;
    while (p) {
        //查找要删除的结点p
        if (p->data == data)
            break;
        pre = p;
        if (data > p->data) {
            p = p->right;
        } else {
            p = p->left;
        }
    }

    // p不存在
    if (!p) {
        printf("there is no %d\n", data);
        return;
    }

    // 叶子结点
    else if (!p->left && !p->right) {
        if (!pre) {
            // 根节点
            root = nullptr;
        } else if (p == pre->right) {
            // p是右孩子
            pre->right = nullptr;
        } else {
            // p是左孩子
            pre->left = nullptr;
        }
        delete p;
        return;
    }

    // 一个孩子结点
    else if (!p->left || !p->right) {
        BSTreeNode* child = p->left ? p->left : p->right;

        if (!pre) {
            //根节点
            root = child;
        } else if (pre->left == p) {
            pre->left = child;
        } else {
            pre->right = child;
        }
        delete p;
        return;
    }

    // 两个孩子结点
    else {
        BSTreeNode* parent = p;
        BSTreeNode* child = p->right;

        while (child->left) {
            parent = child;
            child = child->left;
        }

        p->data = child->data;
        if (parent->left == child) {
            parent->left = child->right;
        } else {
            parent->right = child->right;
        }
        delete child;
    }
}

BSTreeNode* BStree::getNode()
{
    return root;
}
void BStree::inOrder(BSTreeNode* r)
{
    if (r == nullptr) {
        return;
    }

    inOrder(r->left);
    printf("%d ", r->data);
    inOrder(r->right);
}

void BStree::inOrder()
{
    inOrder(root);
}
}