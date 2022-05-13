#include <stdio.h>
#include <stdlib.h>
// In a singly linked list a node has pointer towards its next location
//  In a doubly linked list a node has pointer foward as well as backward
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *first = NULL, *second = NULL;
void create(int A[], int n)
{
    struct node *temp, *last;
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;
    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}
int length(struct node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
void insert(struct node *p, int index, int data)
{
    struct node *t;
    int i;
    if (index < 0 || index > length(p))
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = data;

        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
        return;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = data;
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}
void delete (struct node *p, int index)
{
    struct node *t;
    int i;
    if (index < 0 || index > length(p))
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        t = first;
        first = first->next;
        first->prev = NULL;
        free(t);
        return;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = p->next;
        p->next = t->next;
        if (t->next != NULL)
        {
            t->next->prev = p;
        }
        free(t);
    }
}
void reverse(struct node *p)
{
    struct node *t;
    while (p != NULL)
    {
        t = p->prev;
        p->prev = p->next;
        p->next = t;
        p = p->prev;
    }
    first = p->next;
}
void reverse_2(struct node *q, struct node *p)
{
    if (p)
    {
        reverse_2(p, p->next);
        printf("%d ", p->data);
    }
    else
    {
        first = q;
    }
}

int main()

{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    display(first);
    insert(first, 3, 11);
    display(first);
    return 0;
}