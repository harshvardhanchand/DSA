#include <stdio.h>
#include <stdlib.h>
// linked list stores data in a heap and unlike array is not contiguous in memory,i.e one element points to another element in a different location and so on

// structure of a node
struct node
{
    int data;
    struct node *next;
} *First = NULL;
void create(int A[], int n)
{
    int i;
    struct node *temp, *last;
    First = (struct node *)malloc(sizeof(struct node));
    First->data = A[0];
    First->next = NULL;
    last = First;
    for (i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void Recursive_Display(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Recursive_Display(p->next);
    }
}
// make a function to count nodes
int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
int Recursive_Count(struct node *p)
{
    if (p == NULL)
        return 0;
    return 1 + Recursive_Count(p->next);
}
int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int Recursive_Sum(struct node *p)
{
    if (p == NULL)
        return 0;
    return p->data + Recursive_Sum(p->next);
}
int max(struct node *p)
{
    int max = p->data;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int search(struct node *p, int key)
{
    int count = 0;
    while (p != NULL)
    {
        if (p->data == key)
            return count;
        count++;
        p = p->next;
    }
    return -1;
}
int recursive_search(struct node *p, int key)
{
    if (p == NULL)
        return -1;
    if (p->data == key)
        return 0;
    return 1 + recursive_search(p->next, key);
}

// bring to head
struct node *bring_to_head(struct node *p, int key)
{
    struct node *temp = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            temp->next = p->next;
            p->next = First;
            First = p;
            return temp;
        }
        temp = p;
        p = p->next;
    }
    return NULL;
}
void insert(struct node *p, int pos, int x)
{
    struct node *t;
    int i;
    if (pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));

        t->data = x;
        t->next = First;
        First = t;
    }
    else if (pos > 0 && pos < count(p))
    {
        p = First;
        for (i = 0; i < (pos - 1); i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
    else
    {
        printf("index invalid");
    }
}
void SortedInsert(struct node *p, int x)
{
    struct node *t;
    struct node *q = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (First == NULL)
    {
        First = t;
    }
    else
    {
        while (p->next != NULL && p->next->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == First)
        {
            t->next = First;
            First = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int delete (struct node *p, int index)
{
    struct node *q = NULL;
    int x = -1;
    int i;
    if (index < 1 || index > count(p))
    {
        printf("index invalid");
        return -1;
    }
    if (index == 1)
    {
        x = First->data;
        q = First;
        First = First->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < (index - 1); i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int check_if_sorted(struct node *p)
{
    struct
        int x = -32768;
    int i;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
int main()
{
    struct node *temp;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    Display(First);
    insert(First, 2, 11);
    max(First);
    search(First, 11);
    bring_to_head(First, 11);
    Display(First);
    delete (First, 2);
    Display(First);
    printf("\n");
    return 0;
}
