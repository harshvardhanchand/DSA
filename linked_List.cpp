#include <iostream>
using namespace std;
// make a template  class of linked list with all its functions
template <typename T>
class linked_list
{
private:
    struct node
    {
        T data;
        node *next;
    };
    node *head;
    node *tail;
    int size;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~linked_list()
    {
        node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_back(T data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void push_front(T data)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
        size--;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int get_size()
    {
        return size;
    }
    T get_data(int index)
    {
        node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void set_data(int index, T data)
    {
        node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }
    void insert(int index, T data)
    {
        node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        node *new_node = new node;
        new_node->data = data;
        new_node->next = temp->next;
        temp->next = new_node;
        size++;
    }
    void erase(int index)
    {
        node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        size--;
    }
    void reverse()
    {
        node *temp = head;
        node *temp2 = NULL;
        while (temp != NULL)
        {
            temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next = head;
            head = temp2;
            temp = temp->next;
        }
        tail = temp2;
    }
    void sort()
    {
        node *temp = head;
        node *temp2 = NULL;
        while (temp != NULL)
        {
            temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp->data > temp2->data)
                {
                    T temp_data = temp->data;
                    temp->data = temp2->data;
                    temp2->data = temp_data;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
};
