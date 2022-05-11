#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;
void create_list(int A[], int n)
{
    int i;
    struct node *temp, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head; // single node which points to itself i.e circular node
    last = head;
    for (i = 1; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
int Length(struct node *p)
{
    int len = 0;
    while (p->next != p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
        /* code */
    } while (p != head);
    printf("\n");
}
void recursive_display(struct node *p)
{
    if (p->next != head)
    {
        printf("%d ", p->data);
        recursive_display(p->next);
    }
    else
    {
        printf("%d ", p->data);
        printf("\n");
    }
}
void insert(int pos, int x)
{
    struct node *temp, *p;
    int i;
    if (pos == 1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        if (head == NULL)
        {
            head = temp;
            head->next = head;
        }

        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    }
    else
    {
        p = head;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = p->next;
        p->next = temp;
    }
}
int Delete(struct node *p, int pos)
{
    struct node *q;
    int i, x;
    if (pos <= 0 || pos > Length(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}