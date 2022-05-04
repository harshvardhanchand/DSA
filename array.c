//array is a special type of variable which can store multiple values of same type
//boiler plate
#include<stdio.h>
#include<stdlib.h>
// arrays are vector in C
int A[5];//array of 5 integers has garbage values
int B[5] = {1,2,3,4,5};//array of 5 integers with values 1,2,3,4,5
int C[5] = {1,2,3};//array of 5 integers with values 1,2,3 and other values are garbage
// memory of variable is not assigned at compile time but at run time, so we can't use sizeof()
// to find size of array there is a formula for address of array i.e is the address of first element of array  + size of data type*i 
int main()
{
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};//3x4 matrix
    int *B[3];//pointer to 3 arrays,another way of creating 2D array with fixed rows
    int **C; //helps create  2D array with variable rows and columns 
    int i,j;
    for(i=0;i<3;i++)
    {
        B[i] = (int*)malloc(4*sizeof(int));//allocate memory for each array
        for(j=0;j<4;j++)
        {
            B[i][j] = i*j;
        }
    }
    C = (int**)malloc(3*sizeof(int*));//allocate memory for 3 pointers
    for(i=0;i<3;i++)
    {
        C[i] = (int*)malloc(4*sizeof(int));//allocate memory for each array
        for(j=0;j<4;j++)
        {
            C[i][j] = i*j;
        }
    }
    
    //printing arrays
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    //free memory
    for(i=0;i<3;i++)
    {
        free(B[i]);
    }

    free(C);
    // row major formula for n dimension array is n*sizeof(type)*i + sizeof(type)*j
    //Type A[d1][d2][d3][d4]
    // A[i1][i2][i3][i4] = Lo +[i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4]*sizeof(type)
    return 0;
}