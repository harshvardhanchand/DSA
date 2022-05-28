#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int size;
    int *array;
};

void create(struct Stack *s)
{
    printf("enter the size of stack\n");
    scanf("%d", &s->size);
    s->array = (int *)malloc(s->size * sizeof(int));
    s->top = -1;
}
void display(struct Stack s)
{
    int i;
    for (i = s.top; i >= 0; i--)
    {
        printf("%d\n", s.array[i]);
    }
}
void push(struct Stack *s, int x)
{
    if (s->top == s->size - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        s->top++;
        s->array[s->top] = x;
    }
}
int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        int x = s->array[s->top];
        s->top--;
        return x;
    }
}
int peek(struct Stack s, int index)
{
    int x = -1;
    if (s.top - index + 1 < 0)
    {
        printf("stack is empty\n");
    }
    else
    {
        x = s.array[s.top - index + 1];
    }
    return x;
}
int isEmpty(struct Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Stack s)
{
    if (s.top == s.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stackTop(struct Stack s)
{
    if (s.top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    else
    {
        return s.array[s.top];
    }
}