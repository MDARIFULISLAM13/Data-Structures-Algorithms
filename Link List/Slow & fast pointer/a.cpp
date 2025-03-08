/**
 *
 * Author : Md.Ariful Islam
 * Date : 09-03-2025
 * time : 00:01:10
 * Topic Name : Slow & fast pointer
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
    // Traversal
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

    void middle()
    {

        // this is basic Slow and fast pointer;slow move one time and first move 2 time;
        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "MIddle Element " << slow->data << endl;
    }
};
int main()
{
    List li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    li.print();
    li.middle();

    return 0;
}