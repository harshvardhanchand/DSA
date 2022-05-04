#include <stdio.h>

// Recursion: A function that calls itself
// Recursion is a function that calls itself

void fun(int n)//tail recursion
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
//head recursion
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
//Tree recursion
void funC(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        funC(n-1);
        
        fun(n-1);
    }
}//end of fun time 2^n time complexity Space complexity O(n)
//Indirect recursion
void funB(int n);
void funA(int n)
{
    if(n>0)
    {
        
        printf("%d ",n);
        funB(n-1);
    }
}
void funB(int n)
{
    if(n>0)
    {
        
        printf("%d ",n);
        funA(n/2);
    }
}
//Nested recursion
int fun3(int n)
{
    if(n>100)
    {
        return n-10;
    }
    else
    {
        return fun3(fun3(n+11));
    }
}
//factorial recursion
int fun4(int n)
{
    if(n>1)
    {
        return n*fun4(n-1);
    }
    else
    {
        return 1;
    }
    
}
int exponent(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return m*exponent(m,n-1);
        

    }
    
}
// we can write a more efficent exponent function
int exponent1(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return exponent1(m*m,n/2); //reduces no.of multiplications
    }
    else
    {
        return m*exponent1(m*m,(n-1)/2);
    }
    
}
int taylor_series(int n,int x)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return 1+ taylor_series()

    }

}

int main()
{
    printf("%d",exponent(2,3));
    return 0;
}