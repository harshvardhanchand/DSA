//boiler plate
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //merge arrays
    int A[5] = {1,2,3,4,5};
    int B[5] = {6,7,8,9,10};
    int C[10];
    int i=0,j=0,k=0;
    while(i<5 && j<5)  //compare and place lesser one first
    {
        if(A[i]<B[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    for(;i<5;i++) // for leftover element
    {
        C[k] = A[i];
        k++;
    }
    for(;j<5;j++)
    {
        C[k] = B[j];
        k++;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",C[i]);
    }
    printf("\n");
    return 0;

}