// sparse matrix  is a matrix where majority of elements  are zero
// there are 2 methods
// 1.Coordinate lists/3-coulumm method
// 2.Compressed sparse row
// Coordinate lists/3-coulumm method: we use 2D array to store the data consisting of row and column and element value
// Compressed sparse row: we use 1D array to store the data consisting of row and column and element value.
#include<stdio.h>
#include<stdlib.h>
struct Element
{
    int row;
    int col;
    int value;
};
struct SparseMatrix
{
    int rows;
    int cols;
    int size;//no.of non-zero elements
    struct Element *data;
};

void create_sparse_matrix(struct SparseMatrix *A)
{
    printf("Enter number of rows and columns: ");
    scanf("%d%d",&A->rows,&A->cols);
    printf("Enter number of non-zero elements: ");
    scanf("%d",&A->size);
    A->data = (struct Element *)malloc(A->size*sizeof(struct Element));
    printf("Enter row and column of non-zero elements: ");
    int i;
    for(i=0;i<A->size;i++)
    {
        scanf("%d%d",&A->data[i].row,&A->data[i].col);
        printf("Enter value of non-zero element %d: ",i);
        scanf("%d",&A->data[i].value);
    }
}
void display_sparse_matrix(struct SparseMatrix *A)
{
    int i,j,k=0;
    for(i=0;i<A->rows;i++)
    {
        for(j=0;j<A->cols;j++)
        {
            if(k<A->size)
            {
                if(A->data[k].row==i && A->data[k].col==j)
                {
                    printf("%d ",A->data[k].value);
                    k++;
                }
                else
                {
                    printf("0 ");
                }
                printf("\n");
            }
        }
    }
}
struct SparseMatrix *add_sparse_matrix(struct SparseMatrix *A,struct SparseMatrix *B)
{
    struct SparseMatrix *C = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    int i,j,k;
    i=j=k=0;
    if(A->rows!=B->rows && A->cols!=B->cols)
    {
        printf("Addition not possible\n");
        return NULL;
    }
   

    C->data = (struct Element *)malloc((A->size+ B->size)*sizeof(struct Element));
    while(i<A->size && j<B->size)
    {
        if(A->data[i].row<B->data[j].row)//data is added row wise in 3 column representation
        {
            C->data[k++]= A->data[i++];
        }
        else if(A->data[i].row>B->data[j].row)
        {  
            C->data[k++]= B->data[j++];
        }
        else
        {
            if(A->data[i].col<B->data[j].col) // then column wise
            {
                C->data[k++]= A->data[i++];
            }
            else if(A->data[i].col>B->data[j].col)
            {
                C->data[k++]= B->data[j++];
            }
            else
            {
                C->data[k]= A->data[i];  // for same row and column
                C->data[k++].value =+   B->data[j++].value;
            }
        }
    }
    for(;i<A->size;i++)
    {
        C->data[k++]= A->data[i];
    }
    for(;j<B->size;j++)
    {
        C->data[k++]= B->data[j];
    }
    C->rows = A->rows;
    C->cols = A->cols;
    C->size = k;
    
    return C;
}

int main()
{
    struct SparseMatrix *A,*B,*C;
    A = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    B = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    C = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
    create_sparse_matrix(A);
    create_sparse_matrix(B);
    C = add_sparse_matrix(A,B);
    display_sparse_matrix(C);
    return 0;
}
           