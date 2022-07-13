// A heap is a complete binary tree
// A complete binary tree when all elements are stored in array without space
// Node at index : i
// Node at left child:2*i
// Node at right child: 2*(i) +1
// Duplicates are allowed as it is not a search tree
// Heaps height is logn
// MAX HEAP that is descendants should be lower in value than offspring
// MIN HEAP is the exact opposite of max heap
// Heapsort works on the principle of inserting into heap and deletion from heap and storing it into an array in both ascending and descending order
// In case of max heap remove root from heap replace root with inorder predecessor then make it into a heap again remove root,till heap is empty
// store deleted elements in the same array and you get a sorted array
// Heapify is the process of converting bst into a heap
// Heap is used to create priority queue
// O(n*logn) creating heap O(n) heapify
// Priority queue: number itself is priority larger the number higher priority , smaller number:higher priority
// min heap insertion- logn insertion deletion logn smaller number
// max-heap
#include <iostream>
#include <vector>

using namespace std;
// Lecture based
void InsertA(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Insert(vector<int> &vec, int key)
{
    // Insert key at the end
    auto i = vec.size();
    vec.emplace_back(key);

    // Rearrange elements: O(log n)
    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    vec[i] = key;
}

void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void CreateHeap(vector<int> &vec, int A[], int n)
{
    // O(n log n)
    for (int i = 0; i < n; i++)
    {
        Insert(vec, A[i]);
    }
}

void createHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertInplace(A, i);
    }
}
int Delete(int A[], int n)
{
    int x = A[0]; // Max element
    A[0] = A[n - 1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < n - 1)
    {
        // Compare left and right children
        if (A[j] < A[j + 1])
        {
            j = j + 1;
        }

        // Compare parent and largest child
        if (A[i] < A[j])
        {
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            break;
        }
    }
    return x;
}

void Heapify(int A[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        int j = 2 * i + 1; // Left child for current i

        while (j < n - 1)
        {
            // Compare left and right children of current i
            if (A[j] < A[j + 1])
            {
                j = j + 1;
            }

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}

template <class T>
void Print(T &vec, int n, char c)
{
    cout << c << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main()
{

    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40}; // H used to demonstrate heap sort
    int i;
    Print(b, sizeof(b) / sizeof(b[0]), 'b');

    vector<int> v;
    CreateHeap(v, b, sizeof(b) / sizeof(b[0]));
    Print(v, v.size(), 'v');

    cout << "Inplace Insert" << endl;
    createHeap(b, sizeof(b) / sizeof(b[0]));
    Print(b, sizeof(b) / sizeof(b[0]), 'b');
    for (i = 2; i <= 7; i++)
    {
        InsertA(H, i);
    }
    for (i = 7; i > 1; i--)
    {
        Delete(H, i);
    }
    for (i = 1; i <= 7; i++)
    {
        printf("%d", H[i]);
    }
    printf("\n");

    return 0;
}