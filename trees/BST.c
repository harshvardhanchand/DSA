#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
// In binary search tree
// Properties: For a  node, the value of the left child is less than the value of the parent node, and the value of the right child is greater than the value of the parent node.
// Searching: Searching in a binary search tree is done by comparing the value of the node with the value of the search key. If the value of the node is equal to the value of the search key, the node is found. If the value of the node is less than the value of the search key, the search key is searched in the right subtree. If the value of the node is greater than the value of the search key, the search key is searched in the left subtree.
// No duplicates
// Inorder gives sorted output
// creating a binary search tree takes O(n*log(n)) time
// n for inserion logn for searching as height of tree is log(n)
struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
} *root = NULL;
int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}
struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}
struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

void Insert(int data)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (data < t->data)
            t = t->lchild;
        else if (data > t->data)
            t = t->rchild;
        else
        {

            return;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    if (data < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
void Inorder(struct Node *t)
{
    if (t)
    {
        Inorder(t->lchild);
        printf("%d ", t->data);
        Inorder(t->rchild);
    }
}
struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (t->data == key)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}
// when we are deleting a node if it has no children then we can simply delete it,if it has one child then we can replace it with its child,if it has two children then we can replace it with its inorder successor.
struct Node *Rinsert(struct Node *p, int data)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = data;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    if (data < t->data)
    {
        p->lchild = Rinsert(t->lchild, data);
    }
    else if (data > t->data)
    {
        p->rchild = Rinsert(t->rchild, data);
    }
    return p;
}
struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    // Deletion of leaf node above
    // searching process
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
        if (Height(p->lchild) > Height(p->rchild))
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
    return p;
}
// Unlike Binary tree, Binary search tree is not a complete binary tree.
//  It can have nodes with no left child or no right child.
//  It can be generated only from pre order versus a combination of pre+inorder traversal or post+inorder traversal.
// In generating from pre order, the root is always the first element in the pre order traversal.
// left child is pushed into stack while right child is not pushed into stack.
void create(int pre[], int n)
{
    struct Stack *s = NULL;
    struct Node *t;
    int i = 0;
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = pre[i++];
    root->lchild = NULL;
    root->rchild = NULL;
    struct Node *p;
    p = root;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            push(s, p);
            p = t;
        }
        else
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            p = t;
        }
        }
}

int main()
{
    struct Node *temp;
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    Inorder(root);
    printf("\n");
}