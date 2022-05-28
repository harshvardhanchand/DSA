#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q; // Queue stores addresses of nodes
};
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0; // circular in nature
    q->Q = (struct Node **)malloc(sizeof(struct Node *) * size);
}
void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
