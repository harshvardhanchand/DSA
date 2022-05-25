#include <stdio.h>
#include <stdlib.h>
// Three towers of Hanoi, the problem is to move all the disks from one tower to another tower.Large disk  cannot be on top of smaller disk.
//  Only one disk can be taken at a time
// it takes 2^n-1 moves to move all the disks from one tower to another tower
void TOH(int n, int A, int B, int C)
{
    if (n == 1)
    {
        printf("Move disk 1 from %d to %d\n", A, C);
        return;
    }
    TOH(n - 1, A, C, B);
    printf("Move disk %d from %d to %d\n", n, A, C);
    TOH(n - 1, B, A, C);
}
int main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d", &n);
    TOH(n, 1, 2, 3);
    return 0;
}