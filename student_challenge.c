#include<stdio.h>
#include<stdlib.h>
//to find missing element in a sorted array assuming a uniform pattern(A.P or G.P)
// There is another method find sum of series for n and then subtract by the sum of numbers but this cannot be used for multiple missing
void find_missing(int A[],int n)
{
    int B[10];
    int k=0;
    int a = A[0];
    int d = A[1]-A[0];
    int r = A[1]/A[0];
    int i;
    if(r==(A[2]/A[1]))
    {
        for(i=1;i<n;i++)
        {
            if(A[i]/A[i-1] !=r)
            {
                B[k++]=A[i]/r;

            }
            
        }
    }
    else if(A[2]-A[1]==d)
    {
        for(i=1;i<n;i++)
        {
            if(A[i]-A[i-1]!=d)
            {
                B[k++]=  A[i] -d ;
            }
        }
        
    }
    else
    {
        printf("pattern cannot match ap or gp");
        
    }
    for(i=0;i<=k;i++)
    {
        printf("%d",B[i]);
        printf("\n");
    }




}
//duplicates in a sorted array 
// to print duplicates and count them
//Hash table is used like we have to find duplicates in a sorted array let array be A={1,2,3,4,5,6,7,8,8,9,10} make a array B={0,0,0,0,0,0,0,0,0,0} size is the biggest element in A increment the value of B[i] each time you come across a duplicate  
//check for more than 1 duplicate 
void find_duplicate_unsorted(int A[],int n)
{
    
    int i;
    int j;
    for(i=0;i<n-1;i++)
    {
        int count =0;
        if(A[i] != -1)//to prevent from counting same element twice
        {
            for(j=i+1;j<n;j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                    A[j]=-1; 
                }

            }
            if(count>1)
            {
                printf("%d %d",A[i],count);
                printf("\n");
          
            }
        }
    }
}

//OR we can use hash table to do it in n time instead of n^2 time
//finding a pair  with a sum k
//Hash table is used like we have to find a pair with a sum k
//to make a hash table of size n
//for each element in A
void find_pair_with_sum(int A[],int n,int k,int L)
{
    int i;
    int j;
    int B[L];
    for(i=0;i<L+1;i++)
    {
        B[i]=0;
    }
    for(i=0;i<n;i++)
    {
        B[A[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(B[k-A[i]]>0) // checks if there is a pair with sum k-A[i]
        {
            printf("%d %d",A[i],k-A[i]);
            printf("\n");
        }
    }
}

      
       


    



int main()
{
    //int A[] ={1,2,4,16,64,128,256,512};
    // printf("%d \n",find_missing(A,8));
    //find_missing(A,8);
    int A[] ={1,2,3,4,5,6,7,8,8,8,9,10};
    duplicate_sorted(A,12);




    



    return 0;
}