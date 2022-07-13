#include <stdio.h>
#include <stdlib.h>

// Program to remove duplicates in a singly linked list
struct node
{
    int data;
    struct node *next;
} *First = NULL;
void create(int A[], int n)
{
    int i;
    struct node *temp, *t;
    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;
        if (First == NULL)
        {
            First = temp;
        }
        else
        {
            t = First;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }
}
void display()
{
    struct node *t;
    t = First;
    if (First == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        do
        {
            printf("%d ", t->data);
            t = t->next;
        } while (t != NULL);
    }
}
void remove_duplicates()
{
    struct node *t, *temp;
    t = First;
    while (t->next != NULL)
    {
        temp = t;
        while (temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        t = t->next;
    }
}
int main()
{
    int A[] = {1, 1, 1, 2, 3, 4, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    display();
    remove_duplicates();
    printf("\n");
    display();
    return 0;
}
