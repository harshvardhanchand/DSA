#include <stdio.h>
#include <stdlib.h>
// In a singly linked list a node has pointer towards its next location
//  In a doubly linked list a node has pointer foward as well as backward
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *first = NULL;
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
