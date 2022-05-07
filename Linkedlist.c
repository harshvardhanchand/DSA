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

int main()
{
    struct node *temp;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    Display(First);
    printf("\n");
    return 0;
}
