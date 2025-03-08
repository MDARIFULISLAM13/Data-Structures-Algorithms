/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-03-2025
 * time : 22:53:49
 * Problem Name : Linked List insertion,deletion and Traversal
 *
 **/
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class List
{
private:
    node *head = NULL;
    node *tail = NULL;

public:
    // Insert;
    void push_back(int data)
    {
        node *new_node = new node(data);
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    void push_front(int data)
    {
        node *new_node = new node(data);
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            node *temp = head;
            new_node->next = temp;
            head = new_node;
        }
    }

    // Traversal
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    List li;

    li.push_front(3);
    li.push_back(4);
    li.push_back(5);
    li.push_front(2);

    li.print();

    return 0;
}