// balance factor =  height of left subtree - height of right subtree
// bf= {-1,0,1}
// in avl tree max balance factor is 2,-2
// when we are inserting in  an avl tree sometimes balance gets upset in order to mitigate that we must rotate
// avl trees mean height balanced binary tree
// rotation is done among three nodes only
// there are 4 types of rotation ll rr lr rl
// former two are only one step and latter two are second step
#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    int height;
};

class AVL
{
public:
    Node *root;

    AVL() { root = nullptr; }

    // Helper methods for inserting/deleting
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);

    // Insert
    Node *rInsert(Node *p, int key);

    // Traversal
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    Node *getRoot() { return root; }

    // Delete
    Node *Delete(Node *p, int key);
};

int AVL::NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node *AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p)
    {
        root = pl;
    }
    return pl;
}

Node *AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node *AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root)
    {
        root = plr;
    }
    return plr;
}

Node *AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p)
    {
        root = prl;
    }
    return prl;
}

Node *AVL::InPre(Node *p)
{
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}

Node *AVL::InSucc(Node *p)
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

Node *AVL::rInsert(Node *p, int key)
{
    Node *t;
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
// There are 6 types of deletion L1 L-1 L0 R1 R-1 R0 (1-LL RR 2- LR RL ,0 -Any one)
// deciding which deletion to go through is decided by child of unbalanced node

Node *AVL::Delete(Node *p, int key)
{
    if (p == nullptr)
    {
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        Node *q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    { // L1 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    { // L-1 Rotation
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    { // R-1 Rotation
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    { // R1 Rotation
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
    { // L0 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
    { // R0 Rotation
        return RRRotation(p);
    }

    return p;
}
// Height analysis for avl trees
//  max nodes = 2^h-1 (starting from h=1 , we can take zero also)
// min nodes = n(h-1) + n(h-2) +1
// for min height invert the above formula

int main()
{

    AVL tree;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.Inorder();
    cout << endl;

    tree.Delete(tree.root, 28);

    tree.Inorder();
    cout << endl;

    return 0;
}