#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("stack is full\n");
        return;
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}
int pop()
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        int x = top->data;
        struct Node *temp = top;
        top = top->next;
        free(temp);
        return x;
    }
}
void display()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}