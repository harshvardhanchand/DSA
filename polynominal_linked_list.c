#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
void create_new_node(struct node **start, int coeff, int exp)
{
    struct node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = coeff;
        temp->exp = exp;
        temp->next = NULL;
        *start = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        r = (struct node *)malloc(sizeof(struct node));
        r->coeff = coeff;
        r->exp = exp;
        r->next = NULL;
        temp->next = r;
    }
}
void print_polynomial(struct node *start)
{
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->coeff);
        printf("x^%d ", temp->exp);
        printf("+ ");

        temp = temp->next;
    }
}
struct node *add_polynomial(struct node *start1, struct node *start2)
{
    struct node *temp1, *temp2, *temp3;
    temp1 = start1;
    temp2 = start2;
    temp3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            create_new_node(&temp3, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            create_new_node(&temp3, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else
        {
            create_new_node(&temp3, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        create_new_node(&temp3, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        create_new_node(&temp3, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
    return temp3;
};
long eval(struct node *p, int x)
{
    struct node *temp;
    long result = 0;
    temp = p;
    while (temp != NULL)
    {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    int n;
    int i;
    printf("enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int coeff, exp;
        printf("enter coefficient and exponent of term %d: in descending order ", i + 1);
        scanf("%d %d", &coeff, &exp);
        create_new_node(&start1, coeff, exp);
    }
    printf("\n");
    printf("enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int coeff, exp;
        printf("enter coefficient and exponent of term %d: in descending order ", i + 1);
        scanf("%d %d", &coeff, &exp);
        create_new_node(&start2, coeff, exp);
    }
    printf("\n");
    printf("first polynomial: ");
    print_polynomial(start1);
    printf("\n");
    printf("second polynomial: ");
    print_polynomial(start2);
    printf("\n");
    struct node *temp;
    temp = add_polynomial(start1, start2);
    printf("sum of polynomials: ");
    print_polynomial(temp);
    printf("\n");
    printf("enter x: ");
    int x;
    scanf("%d", &x);
    printf("value of polynomial at %d: %ld", x, eval(temp, x));
}