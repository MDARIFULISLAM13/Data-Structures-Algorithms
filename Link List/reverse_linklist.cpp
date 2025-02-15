#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int id;
    string name;
    node *next_node;

    node(int id, string name)
    {
        this->id = id;
        this->name = name;
        this->next_node = NULL;
    }
};
class arif
{
private:
    node *head;
    node *tail;

public:
    arif()
    {
        head = tail = NULL;
    }

    void push_back(int id, string name)
    {
        node *new_node = new node(id, name);

        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next_node = new_node;
            tail = new_node;
        }
    }
    void push_front(int id, string name)
    {

        node *new_node = new node(id, name);
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next_node = head;
            head = new_node;
        }
    }
    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next_node != tail)
            {
                temp = temp->next_node;
            }

            delete tail;
            tail = temp;
            tail->next_node = NULL;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        node *temp = head;
        head = head->next_node;
        delete temp;
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->id << " " << temp->name << endl;
            temp = temp->next_node;
        }
    }

    void insert(int num, int id, string name)
    {

        node *new_node = new node(id, name);

        node *temp = head;

        while (temp->id != num && temp != NULL)
        {
            temp = temp->next_node;
        }
        if (temp == NULL)
        {
            return;
        }

        new_node->next_node = temp->next_node;
        temp->next_node = new_node;
    }
    // reverse a link list

    void reverse()
    {
        node *pre = NULL;

        node *next = NULL;
        while (head != tail)
        {
            pre = head;
            head = head->next_node;
            pre->next_node = next;
            next = pre;
        }
        head->next_node = next;
    }
};

int main()
{
    arif ar;
    ar.push_back(3, "a");
    ar.push_back(5, "b");
    ar.push_back(6, "c");
    ar.push_front(2, "A");
    ar.push_front(1, "B");
    ar.insert(3, 4, "D");
    ar.print();
    ar.reverse();
    ar.print();

    return 0;
}