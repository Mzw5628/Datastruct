#include "tree.h"
#include <cstdio>

namespace ds {
BTree::BTree()
{
    // 创建结点
    BTreeNode* A = new BTreeNode { 'A', nullptr, nullptr };
    BTreeNode* B = new BTreeNode { 'B', nullptr, nullptr };
    BTreeNode* C = new BTreeNode { 'C', nullptr, nullptr };
    BTreeNode* D = new BTreeNode { 'D', nullptr, nullptr };
    BTreeNode* E = new BTreeNode { 'E', nullptr, nullptr };
    BTreeNode* F = new BTreeNode { 'F', nullptr, nullptr };
    BTreeNode* G = new BTreeNode { 'G', nullptr, nullptr };

    // 连接关系
    A->left = B;
    A->right = C;

    B->left = D;
    B->right = E;

    C->right = F;

    E->left = G;

    // 返回根结点
    root = A;
}
BTreeNode* BTree::getRoot()
{
    return root;
}
void BTree::perOrderBT(BTreeNode* r)
{
    if (r == nullptr) {
        return;
    }
    printf("%c", r->data); // 该语句在此为先序遍历
    perOrderBT(r->left);        // 在此为中序遍历
    perOrderBT(r->right);       // 在此为后序遍
}
}