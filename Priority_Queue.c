// priority queue we simply take elements and assign them a numerical value. and then we group by the value in different queue or we can make element itself high priority
#include <stdio.h>
#include <stdlib.h>

// implement a priority queue using array(element it self is priority)
void create(int *array, int size);
void enqueue(int *array, int size, int data);
int dequeue(int *array, int size);
void display(int *array, int size);

void create(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = -1;
    }
}
void enqueue(int *array, int size, int data)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == -1)
        {
            array[i] = data;
            break;
        }
    }
}
int dequeue(int *array, int size)
{
    int i, min, min_index;
    min = array[0];
    min_index = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] != -1)
        {
            if (array[i] < min)
            {
                min = array[i];
                min_index = i;
            }
        }
    }
    array[min_index] = -1;
    return min;
}
void display(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] != -1)
        {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}
int main()
{
    int array[5];
    create(array, 5);
    enqueue(array, 5, 1);
    enqueue(array, 5, 2);
    enqueue(array, 5, 3);
    enqueue(array, 5, 4);
    enqueue(array, 5, 5);
    display(array, 5);
    printf("%d\n", dequeue(array, 5));
    display(array, 5);
    return 0;
}