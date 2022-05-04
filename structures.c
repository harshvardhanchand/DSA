#include<stdio.h>
#include<stdlib.h>
struct Card
{
    int face;
    int shape;
    int color;

};


int main()
{
    struct Card deck[52];
    // size will be 52 *6 bytes
    struct Card r={1,2,3};
    struct Card *p=&r;
    p->face=4;//p->face is same as (*p).face  
    struct Card *q;
    q= (struct Card *)malloc(sizeof(struct Card));//variable of structure is created in heap
   q->color=5;
    q->face=6;
    q->shape=7;


    return 0;
}

