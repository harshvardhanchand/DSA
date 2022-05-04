#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Polynominal is represented using two column method
// no.of non zero terms  is represented by no.of columns
struct Term
{
    int coeff;
    int exp;
};
struct Polynomial
{
    int no_of_terms;
    struct Term *terms;
};
struct Polynomial *create_polynomial(int no_of_terms)
{
    struct Polynomial *polynomial = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    polynomial->no_of_terms = no_of_terms;
    polynomial->terms = (struct Term *)malloc(no_of_terms * sizeof(struct Term));
    printf("Enter coeff and exp of terms: ");
    int i;
    for(i=0;i<no_of_terms;i++)
    {
        scanf("%d%d",&polynomial->terms[i].coeff,&polynomial->terms[i].exp);
    }
    return polynomial;
}
int evaluate_polynomial(struct Polynomial *polynomial,int x)
{
    int i,result=0;
    for(i=0;i<polynomial->no_of_terms;i++)
    {
        result += polynomial->terms[i].coeff * pow(x,polynomial->terms[i].exp);
    } 
    return result;
}
struct Polynomial *add_polynomial(struct Polynomial *polynomial1,struct Polynomial *polynomial2)
{
    struct Polynomial *polynomial3 = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    int i,j,k;
    i=j=k=0;
    while(i<polynomial1->no_of_terms && j<polynomial2->no_of_terms)
    {
        if(polynomial1->terms[i].exp == polynomial2->terms[j].exp)
        {
            polynomial3->terms[k].coeff = polynomial1->terms[i].coeff + polynomial2->terms[j].coeff;    
            polynomial3->terms[k].exp = polynomial1->terms[i].exp;
            i++;
            j++;
            k++;
        }
        else if(polynomial1->terms[i].exp > polynomial2->terms[j].exp)
        {
            polynomial3->terms[k].coeff = polynomial1->terms[i].coeff;
            polynomial3->terms[k].exp = polynomial1->terms[i].exp;
            i++;
            k++;
        }
        else
        {
            polynomial3->terms[k].coeff = polynomial2->terms[j].coeff;
            polynomial3->terms[k].exp = polynomial2->terms[j].exp;
            j++;
            k++;
        }
    }
    while(i<polynomial1->no_of_terms)
    {
        polynomial3->terms[k].coeff = polynomial1->terms[i].coeff;
        polynomial3->terms[k].exp = polynomial1->terms[i].exp;
        i++;
        k++;
    }
    while(j<polynomial2->no_of_terms)
    {
        polynomial3->terms[k].coeff = polynomial2->terms[j].coeff;
        polynomial3->terms[k].exp = polynomial2->terms[j].exp;
        j++;
        k++;
    }
    polynomial3->no_of_terms = k;
    return polynomial3;
}
void print_polynomial(struct Polynomial *polynomial)
{
    int i;
    for(i=0;i<polynomial->no_of_terms;i++)
    {
        if(polynomial->terms[i].coeff != 0)
        {
            if(polynomial->terms[i].exp == 0)
            {
                printf("%d",polynomial->terms[i].coeff);
            }
            else if(polynomial->terms[i].exp == 1)
            {
                printf("%dX",polynomial->terms[i].coeff);
            }
            else
            {
                printf("%dX^%d",polynomial->terms[i].coeff,polynomial->terms[i].exp);
            }
            if(i != polynomial->no_of_terms - 1)
            {
                printf(" + ");
            }
        }
    }
}