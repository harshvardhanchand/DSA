//boiler plate
#include<stdio.h>
#include<stdlib.h>

//An abstract data type is a data structure that represents a set of objects.
//It has two parts: the data structure and the operations that can be performed on it.
//The data structure is the collection of objects.
//The operations are the functions that can be performed on the data structure.
//We are going to creata ADT of array

//Array ADT
struct Array
{
    int *data;
    int size;
    int length;
};
void display(struct Array A)
{
    int i;
    for(i=0;i<A.length;i++)
    {
        printf("%d ",A.data[i]);
    }
    printf("\n");
}
void insert(struct Array *A,int index,int value) // this insert  function increases length as it shifts the element present at the index one step foward
{
    if(index>=A->length)
    {
        printf("Index out of bound\n");
        return;
    }
    if(A->length==A->size)
    {
        A->size = A->size*2;
        A->data = (int*)realloc(A->data,A->size*sizeof(int));
    }
    int i;
    for(i=A->length-1;i>=index;i--)
    {
        A->data[i+1] = A->data[i];
    }
    A->data[index] = value;
    A->length++;
}
void delete(struct Array *A,int index) // this delete function decreases length as it shifts the element present at the index one step backward
{
    if(index>=A->length)  
    {
        printf("Index out of bound\n");
        return;
    }
    int i;
    for(i=index;i<A->length-1;i++)
    {
        A->data[i] = A->data[i+1];
    }
    A->length--;
}
void get(struct Array A,int index,int *value)
{
    if(index>=A.length)
    {
        printf("Index out of bound\n");
        return;
    }
    *value = A.data[index];
}
void set(struct Array *A,int index,int value)
{
    if(index>=A->length)
    {
        printf("Index out of bound\n");
        return;
    }
    A->data[index] = value;
}
void max(struct Array A,int *value)
{
    int i;
    *value = A.data[0];
    for(i=1;i<A.length;i++)
    {
        if(A.data[i]>*value)
        {
            *value = A.data[i];
        }
    }
}
void reverse(struct Array *A)
{
    int i,j;
    for(i=0,j=A->length-1;i<j;i++,j--)
    {
        int temp = A->data[i];
        A->data[i] = A->data[j];
        A->data[j] = temp;
    }
}
void leftrotate(struct Array *A,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int temp = A->data[0];
        int j;
        for(j=0;j<A->length-1;j++)
        {
            A->data[j] = A->data[j+1];
        }
        A->data[A->length-1] = temp;
    }
}
void rightrotate(struct Array *A,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int temp = A->data[A->length-1];
        int j;
        for(j=A->length-1;j>0;j--)
        {
            A->data[j] = A->data[j-1];
        }
        A->data[0] = temp;
    }
}
void check_if_sorted(struct Array A)
{
    int i;
    for(i=0;i<A.length-1;i++)
    {
        if(A.data[i]>A.data[i+1])
        {
            printf("Array is not sorted\n");
            return;
        }
    }
    printf("Array is sorted\n");
}
//create a function to insert in a sorted array by shifting elements not replacing
void insert_sorted(struct Array *A,int value)
{
    int i;
    for(i=0;i<A->length;i++)
    {
        if(A->data[i]>value)
        {
            break;
        }
    }
    insert(A,i,value);
}
 struct Array* Difference(struct Array *arr1,struct Array
 *arr2)
{
int i,j,k;
i=j=k=0;
struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));
while(i<arr1->length && j<arr2->length)
{
if(arr1->data[i]<arr2->data[j])
arr3->data[k++]=arr1->data[i++];
else if(arr2->data[j]<arr1->data[i])
{
j++;
}
else

{
i++;
  }
 for(;i<arr1->length;i++)
 arr3->length=k;
 arr3->size=k*2;
  return arr3;
}
}
 struct Array* Intersection(struct Array *arr1,struct Array
 *arr2)
{
int i,j,k;
i=j=k=0;
struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));
while(i<arr1->length && j<arr2->length)
{
if(arr1->data[i]<arr2->data[j])
i++;
else if(arr2->data[j]<arr1->data[i])
j++;
else if(arr1->data[i]==arr2->data[j])
{
arr3->data[k++]=arr1->data[i++];
}
j++;
}
arr3->length=k;
arr3->size=k*2;
return arr3;
}


struct Array* Union(struct Array *arr1,struct Array *arr2)
{

 
 int i,j,k;
 i=j=k=0;
 
struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));
while(i<arr1->length && j<arr2->length)
{
if(arr1->data[i]<arr2->data[j])
arr3->data[k++]=arr1->data[i++];
else if(arr2->data[j]<arr1->data[i])
    arr3->data[k++]=arr2->data[j++];
else
{
arr3->data[k++]=arr1->data[i++];
j++;
}
}
for(;i<arr1->length;i++)
arr3->data[k++]=arr1->data[i];
for(;j<arr2->length;j++)
arr3->data[k++]=arr2->data[j];
arr3->length=k;
arr3->size=k*2;
return arr3;
}









int main()
{
    struct Array A;
    printf("Enter size of array: ");
    scanf("%d",&A.size);
    A.data = (int * )malloc(A.size*sizeof(int));
    A.length = 0;//no elements in array as of now
    printf("Enter no. elements  of array: ");
    scanf("%d",&A.length);
    int i;
    for(i=0;i<A.length;i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d",&A.data[i]);
    }
    return 0;
    

    

}