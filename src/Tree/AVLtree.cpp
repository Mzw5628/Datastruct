#include "tree.h"
#include <cstdio>
namespace ds{

AVLtree::AVLtree()
{
    root = nullptr;
}

AVLNode* AVLtree::CreateNode(int data)
{
    AVLNode* p = new AVLNode();
    p->data = data;
    p->left = p->right = nullptr;
    p->h = max(geth(p->left), geth(p->right)) + 1;
    return p;
}

int AVLtree::max(int a, int b)
{
    return a > b ? a : b;
}

int AVLtree::geth(AVLNode* x)
{
    if (x == nullptr)
        return 0;
    else
        return x->h;
}

AVLNode* AVLtree::search(int data)
{
    AVLNode* p = root;
    while (p) {
        if (p->data == data) {
            printf("Find: %d in AVLtree\n", data);
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

// 四种调整
// 因为在结点x的左孩子的左子树中插入了新结点，导致x失衡，以x为根的子树变成最小失衡子树，对x进行一次右旋
AVLNode* AVLtree::LLrotation(AVLNode* x)
{ // LL
    // 右旋
    // y指向x的左孩子
    AVLNode* y = x->left;
    // y的右孩子变成x的左孩子
    x->left = y->right;
    // x变成了y的右边孩子
    y->right = x;
    // 由于此时x和y的子树都发生了变化 可能会导致他们的高度变化
    x->h = max(geth(x->left), geth(x->right)) + 1;
    y->h = max(geth(y->left), geth(y->right)) + 1;
    return y;
}

// 因为在结点x右孩子的右子树中插入了新结点，导致x失衡，以x为根的子树变成最小失衡子树，对x进行一次左旋
AVLNode* AVLtree::RRrotation(AVLNode* x)
{ // RR
    // 左旋
    // y指向x的右孩子
    AVLNode* y = x->right;
    // y的左孩子变成x的右孩子
    x->right = y->left;
    // x变成了y的左边孩子
    y->left = x;
    // 由于此时x和y的子树都发生了变化 可能会导致他们的高度变化
    x->h = max(geth(x->left), geth(x->right)) + 1;
    y->h = max(geth(y->left), geth(y->right)) + 1;
    return y;
}
// 因为在结点x的左孩子的右子树中插入了新结点，导致x失衡，以x为根的子树变成最小失衡子树，先对x的左子树进行一次左旋，再对x进行一次右旋
AVLNode* AVLtree::LRrotation(AVLNode* x)
{
    x->left = RRrotation(x->left);
    x = LLrotation(x);
    return x;
}
// 因为在结点x右孩子的左子树中插入了新结点，导致x失衡，以x为根的子树变成最小失衡子树，先对x的右子树进行一次右旋，再对x进行一次左旋
AVLNode* AVLtree::RLrotation(AVLNode* x)
{ // RL

    x->right = LLrotation(x->right);
    x = RRrotation(x);
    return x;
}

void AVLtree::insert(int a)
{
    root = insert(a, root);
}
AVLNode* AVLtree::insert(int a, AVLNode* p)
{ // 在以root为根的子树上插入数据a
    if (p == nullptr) {
        p = CreateNode(a);
        return p;
    }
    if (a < p->data) {
        p->left = insert(a, p->left);
        // 完成了在root的左子树中插入一个数据a，就有可能导致左子树高度增加1 如果原本左边比右边高1 ，那么插入后就可能会高2 导致root失衡
        if (geth(p->left) - geth(p->right) > 1) { // 左边比右边高 超过1 失衡：LL LR
            AVLNode* left = p->left;
            if (a < left->data) { // LL
                p = LLrotation(p);
            } else { // LR
                p = LRrotation(p);
            }
        }
    } else {
        p->right = insert(a, p->right);
        // 完成了在root的右子树中插入一个数据a，就有可能导致右子树高度增加1 如果原本右边比左边高1 ，那么插入后就可能会高2 导致root失衡
        if (geth(p->right) - geth(p->left) > 1) { // 右边比左边高 超过1 失衡：RR RL
            AVLNode* right = p->right;
            if (a > right->data) { // RR
                p = RRrotation(p);
            } else { // RL
                p = RLrotation(p);
            }
        }
    }
    p->h = max(geth(p->left), geth(p->right)) + 1; // 在以root为根的子树上插入数据a后 根结点root的高度可能会变 记得更新
    return p;
}
AVLNode* AVLtree::getRoot()
{
    return root;
}

void AVLtree::inorder()
{
    printf("各个节点的平衡因子：\n");
    inorder(root);
}
void AVLtree::inorder(AVLNode* p)
{
    if (p == nullptr)
        return;

    inorder(p->left);
    printf("%d,%d \n", p->data, geth(p->left) - geth(p->right));
    inorder(p->right);
}
}