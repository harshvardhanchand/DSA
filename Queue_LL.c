#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        temp->data = data;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}
int dequeue()
{
    int data;
    struct Node *temp;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        temp = front;
        data = temp->data;
        front = front->next;
        free(temp);
        return data;
    }
}
void Display()
{
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    printf("%d", dequeue());
    return 0;
}