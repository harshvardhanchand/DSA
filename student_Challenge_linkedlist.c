#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// There are 3 methods to find middle node in linked list
// 1. using two pointers 2. using one pointer 3. using recursion
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

void middle1(struct node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    int index = (int)ceil(length / 2.0);
    struct node *q = First;
    int i;
    for (i = 0; i < index - 1; i++)
    {
        q = q->next;
    }
    printf("middle element is %d", q->data);
}
void middle2(struct node *p)
{
    struct node *q = First;
    while (q->next != NULL && q->next->next != NULL)
    {
        q = q->next->next;
        p = p->next;
    }
    printf("middle element is %d", p->data);
}
// another method uses stack we will come back to it later