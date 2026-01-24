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
    BSTreeNode* pre;
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

void BStree::search(int data)
{
    BSTreeNode* p = root;
    while (p) {
        if (p->data == data) {
            printf("Find: %d in BSTree\n", data);
            return;
        }
        if (data > p->data)
            p = p->right;
        else
            p = p->left;
    }
    printf("there is no %d\n", data);
}

void BStree::remove(int data)
{
    BSTreeNode* p = root;
    BSTreeNode* pre = p;
    while (p) {
        if (p->data == data) {
            if (p->left == p->right) {
                if (data > pre->data) {
                    pre->right = nullptr;
                } else {
                    pre->left = nullptr;
                }
                delete p;
                return;
            }

            if (data > pre->data) {
                pre->right = p->left;
                p->left->right = p->right;
            } else {
                pre->left = p->right;
                p->right->left = p->left;
            }

            delete p;
            return;
        }
        if (data > p->data) {
            pre = p;
            p = p->right;
        } else {
            pre = p;
            p = p->left;
        }
    }
    printf("there is no %d\n", data);
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
}