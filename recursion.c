#include <stdio.h>

// Recursion: A function that calls itself
// Recursion is a function that calls itself

void fun(int n) // tail recursion
{
    if (n == 0)
    {
        return;
    }
    else
    {
        printf("%d ", n);
        fun(n - 1);
    }
}
// head recursion
void fun1(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        fun1(n - 1);
        printf("%d ", n);
    }
}
// Tree recursion
void funC(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funC(n - 1);

        fun(n - 1);
    }
} // end of fun time 2^n time complexity Space complexity O(n)
// Indirect recursion
void funB(int n);
void funA(int n)
{
    if (n > 0)
    {

        printf("%d ", n);
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 0)
    {

        printf("%d ", n);
        funA(n / 2);
    }
}
// Nested recursion
int fun3(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return fun3(fun3(n + 11));
    }
}
// factorial recursion
int fun4(int n)
{
    if (n > 1)
    {
        return n * fun4(n - 1);
    }
    else
    {
        return 1;
    }
}
int exponent(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return m * exponent(m, n - 1);
    }
}
// we can write a more efficent exponent function
int exponent1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return exponent1(m * m, n / 2); // reduces no.of multiplications
    }
    else
    {
        return m * exponent1(m * m, (n - 1) / 2);
    }
}
// a function to get derivative of a function
double derivative(double (*f)(double), double x)
{
    double h = 0.00001;
    return (f(x + h) - f(x)) / h;
}
// a function to create a mathametical function of integer x
int factor(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factor(n - 1);
    }
}
void print_n_factorial(int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", factor(i));
    }
}
void print_n_natural_number(int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
}

void taylor_series(int n, int a, int b)
{
}

int main()
{
    printf("%d", exponent(2, 3));
    return 0;
}