#include <stdio.h>
#include <stdlib.h>

// create a doubly linked circular list
struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;
void create(int A[], int n)
{
    int i;
    struct node *temp, *t;
    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            head->next = head;
            head->prev = head;
        }
        else
        {
            t = head;
            while (t->next != head)
            {
                t = t->next;
            }
            t->next = temp;
            temp->prev = t;
            temp->next = head;
            head->prev = temp;
        }
    }
}
void display()
{
    struct node *t;
    t = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        do
        {
            printf("%d ", t->data);
            t = t->next;
        } while (t != head);
    }
}