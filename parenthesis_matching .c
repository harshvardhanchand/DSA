#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
} *top = NULL;
void push(char x)
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
int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char str[100];
    printf("enter the expression with parenthesis\n");
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (isEmpty())
            {

                return 0;
            }
            else
            {
                pop();
            }
        }
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] == '[')
        {
            push(str[i]);
        }
        else if (str[i] == ']')
        {
            if (isEmpty())
            {

                return 0;
            }
            else
            {
                pop();
            }
        }
        i++;
    }
    while (str[i] != '\0')
    {
        if (str[i] == '{')
        {
            push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (isEmpty())
            {

                return 0;
            }
            else
            {
                pop();
            }
        }
        i++;
    }

    if (isEmpty())
    {
        printf("parenthesis are matching\n");
    }
    else
    {
        printf("parenthesis are not matching\n");
    }
}