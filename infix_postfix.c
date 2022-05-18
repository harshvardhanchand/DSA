#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Node
{
    int data;
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
char pop()
{
    struct Node *temp;
    char x = -1;
    if (top == NULL)
    {
        printf("stack is empty\n");
        return x;
    }
    else
    {
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}
int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    postfix = (char *)malloc(sizeof(char) * 100);
    int len = strlen(infix);
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

// compilers convert infix to postfix and then evaluate the postfix expression using stack left to right order,precedence is used to decide order of  parethesias
int eval(char *postfix)
{
    int i = 0;
    int x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i]);
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return top->data;
}
int main()
{
    char *infix = "(A+B)*(C+D)";
    push('#');
    char *postfix = InToPost(infix);
    printf("%s\n", postfix);
    printf("%d\n", eval(postfix));
    return 0;
}
