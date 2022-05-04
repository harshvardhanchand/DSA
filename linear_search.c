//boiler plate
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //linear search 
    int A[5] = {1,2,3,4,5};
    int key,i;
    printf("Enter the key to be searched\n");
    scanf("%d",&key);
    for(i=0;i<5;i++) // best case O(1) worst case O(n) average case O(n)
    {
        if(A[i]==key)
        {
            printf("Key found at index %d\n",i);
            break;
        }

    }
    if(i==5)
    {
        printf("Key not found\n");
    }
    //there are 2 methods to optimize linear search
    //1.Transposition i.e we assume the element to be searched has a higher probability of being serched again so we move it one step back in the array to ease the search
    //2.Move to front/end  i.e we take same assumption as above this time we move the element to be searched to the front or end of the array to ease the search
    return 0;
}