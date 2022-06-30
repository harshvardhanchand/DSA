#include <iostream>

#define N 100
using namespace std;

// MEMOIZATION is a technique which saves time in recursion
//  it stores data of previous calc in an array
//  Therefore reducing time complexity in recursion

int lookup_table[N];

int fib_mem(int n)
{
    if (lookup_table[n] == 0)
    {
        if (n <= 2)
            lookup_table[n] = n;
        else
            lookup_table[n] = fib_mem(n - 1) + fib_mem(n - 2);
    }
    return lookup_table[n];
}
int main()
{

    cout << fib_mem(5) << "\n";
    cout << fib_mem(6) << "\n";
}