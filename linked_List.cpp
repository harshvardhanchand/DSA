#include <iostream>
using namespace std;

// make a template class of node
template <class T>
class node
{
public:
    T data;
    node *next;
};

template <class T>
class linked_list
{
private:
    node<T> *first;

public:
    linked_list()
    {
        first = NULL;
    }
    linked_list(T A[], int size);
    ~linked_list();
    void print();
    void insert(int index, T data);
    void delete_node(int index);
    int length();
};
linked_list<int>::linked_list(int A[], int size)
{
    first = NULL;
    for (int i = 0; i < size; i++)
    {
        insert(i, A[i]);
    }
}
linked_list<int>::~linked_list()
{
    node<int> *temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}
void linked_list<int>::print()
{
    node<int> *temp = first;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void linked_list<int>::insert(int index, int data)
{
    node<int> *temp = first;
    node<int> *new_node = new node<int>;
    new_node->data = data;
    new_node->next = NULL;
    if (index == 0)
    {
        new_node->next = first;
        first = new_node;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void linked_list<int>::delete_node(int index)
{
    node<int> *temp = first;
    if (index == 0)
    {
        first = first->next;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}
int linked_list<int>::length()
{
    node<int> *temp = first;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
