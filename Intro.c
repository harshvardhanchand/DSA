//boiler plate with int main

#include<stdio.h>
#include<stdlib.h>
//there are 3 parts of main memory
//code section where code is written
// stack  where array etc we write in main program is created,every variable is declared in stack
// heap is external to program i.e not directly accessible
//create a structure rectangle with two variables length and breadth
//create a function area which takes a structure as argument and returns area of rectangle
//create a function perimeter which takes a structure as argument and returns perimeter of rectangle
//create a function display which takes a structure as argument and displays area and perimeter of rectangle
struct Rectangle
{
    int length;
    int breadth;
};
int area(struct Rectangle r)
{
    return r.length*r.breadth;
}
int perimeter(struct Rectangle r)
{
    return 2*(r.length+r.breadth);
}
void display(struct Rectangle r)
{
    printf("Area of rectangle is %d\n",area(r));
    printf("Perimeter of rectangle is %d\n",perimeter(r));
}
void initiliaze(struct Rectangle *r)
{
    printf("Enter length and breadth of rectangle\n");
    scanf("%d%d",&r->length,&r->breadth);
}

// above code is close to a class we can get in c
// at top of stack function which is executed first is there
// as soon as main function is called stack is created
// Stack is executed in reverse order top to bottom and record is deleted from stack
//Heap is not ordered and is not in reverse order
// int*P is in stack
//p = new int[5 ] or use malloc is allocated in heap
// free(p) in c delete[]p


int main()
{
    // pointer is used to generally access heap memory,parameter passing,accessing resources
    //pointer is a variable which stores address of a variable
    //malloc calloc realloc are used to create heap memory
    printf("Hello World\n");
    return 0;
}