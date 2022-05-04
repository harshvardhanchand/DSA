//boiler plate
#include<stdio.h>
#include<stdlib.h>
//there are 3 parts of main memory
//code section where code is written
// stack  where array etc we write in main program is created,every variable is declared in stack
// heap is external to program i.e not directly accessible
void fun2(int i)
{
    int a;
}

void fun1()
{
    int x;
    fun2(x);
}
void main()
{
    int a;//these variables are in stack
    //first function is executed at top of stack
    // that means fun2 is executed first, its variables i and a are used first.
    int b;
    fun1();
}

