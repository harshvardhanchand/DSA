#include <stdio.h>
#include "Chains.h"
#include <stdlib.h>

int hash(int key)
{
    return key % 10;
}
void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}
int main()
{
    struct Node *H[10];
    struct Node *temp;
    int i;
    for (i = 0; i < 10; i++)
    {
        H[i] = NULL;
    }
    Insert(H, 5);
    Insert(H, 3);
    Insert(H, 7);
    temp = Search(H[hash(7)], 7);
    printf("%d\n", temp->data);
    temp = Search(H[hash(3)], 3);
    printf("%d\n", temp->data);
    return 0;
}
