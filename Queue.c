// Queue is a logical data structure operating on a principle called FIFO.
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
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->array = (int *)malloc(sizeof(int) * size);
}

void enqueue(struct Queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear++;
        q->array[q->rear] = data;
    }
}
int dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->front++;
        int data = q->array[q->front];

        return data;
    }
}
void display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.array[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    display(q);
    printf("%d\n", dequeue(&q));
    return 0;
}
// Drawbacks
// 1.We cannot access the space of deleted elements as insertion is done from rear end
// 2.If we front == rear but queue is not empty, we cannot enqueue or dequeue
// Solutions
// 1.If front == rear we reset pointers to -1