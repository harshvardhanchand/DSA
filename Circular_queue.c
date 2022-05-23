// Circular queue implementation is just a normal queue just with a condition that front and rear should be same when queue is empty.
//  Array is not circular front and rear pointers are moving circularly
// front and rear are pointing to 0 instead of -1 and first insertion will take place at 1 instead of 0 as front should always remain empty
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear; // they are not traditional address pointers,they are indexes
    int size;
    int *array;
};
void create(struct Queue *q, int size)
{
    q->front = 0;
    q->rear = 0;
    q->size = size;
    q->array = (int *)malloc(sizeof(int) * size);
}
void enqeue(struct Queue *q, int data)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->array[q->rear] = data;
    }
}
int dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        int data = q->array[q->front];
        return data;
    }
}
void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.array[i]);
        i = (i + 1) % q.size;

    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);
    enqeue(&q, 1);
    enqeue(&q, 2);
    enqeue(&q, 3);
    Display(q);
    printf("%d\n", dequeue(&q));
    return 0;
}