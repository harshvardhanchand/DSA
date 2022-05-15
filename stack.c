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
int main()
{
    struct Stack s;
    create(&s);
    int choice, x, index;
    while (1)
    {
        printf("1.push\n2.pop\n3.peek\n4.display\n5.isEmpty\n6.isFull\n7.stackTop\n8.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed\n");
            scanf("%d", &x);
            push(&s, x);
            break;

        case 2:
            x = pop(&s);
            if (x != -1)
            {
                printf("popped element is %d\n", x);
            }
            break;

        case 3:
            printf("enter the index of element to be peeked\n");
            scanf("%d", &index);
            x = peek(s, index);
            if (x != -1)
            {
                printf("peeked element is %d\n", x);
            }
            break;
        }
    }
}