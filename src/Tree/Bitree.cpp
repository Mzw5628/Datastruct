#include "tree.h"
#include <cstdio>
#include <queue>
#include <stack>

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
    perOrderBT(r->left); // 在此为中序遍历
    perOrderBT(r->right); // 在此为后序遍
}

void BTree::DFS(BTreeNode* r)
{
    std::stack<BTreeNode*> st;
    BTreeNode* node = nullptr;
    if (r == nullptr)
        return;
    st.push(r);

    while (!st.empty()) {
        node = st.top();
        printf("%c ", node->data);
        st.pop();
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
}

void BTree::BFS(BTreeNode* r)
{
    std::queue<BTreeNode*> q;
    BTreeNode* node = nullptr;
    if (r == nullptr)
        return;

    q.push(r);
    while (!q.empty()) {
        node = q.front();
        printf("%c ",node->data);
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}
}