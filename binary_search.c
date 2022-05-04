#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Binary_search(int A[],int key,int low,int high)
{
    if(low>high)// if low>high this means there is no element in list
    {
        return -1;
    }
    int mid = (low+high)/2; // rounds down
    if(A[mid]==key)
    {
        return mid;
    }
    else if(A[mid]>key)
    {
        return Binary_search(A,key,low,mid-1);
    }
    else
    {
        return Binary_search(A,key,mid+1,high);
    }
}
//binary search iterative
int Binary_search_iterative(int A[],int key,int low,int high)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]==key)
        {
            return mid;
        }
        else if(A[mid]>key)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}


int main()
{
    //binary search iterative
    int A[6] = {1,2,3,4,5,6};
    int key,i;
    printf("Enter the key to be searched\n");
    scanf("%d",&key);
    i = Binary_search_iterative(A,key,0,5);
    // best case for binary search is O(1)
    // worst case for binary search is O(log n) with base 2 where n  is even if n is odd we use n+1 for formula
    // average case for binary search is O(log n)
    if(i==-1)
    {
        printf("Key not found\n");
    }
    else
    {
        printf("Key found at index %d\n",i);
    }
    //binary search is a divide and conquer algorithm
    // e=i+1 // external height  i.e the node which is not part of the tree i.e unsuccesful search
    //E = I +2*N // I is interanl node N is total no .of nodes in the tree E is external nodes

    
    
    
    

    

   

}