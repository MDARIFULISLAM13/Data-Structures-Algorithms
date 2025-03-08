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
    node *head;
    node *tail;

public:
    List()
    {
        head = new node(1);
        node *second = new node(2);
        node *third = new node(3);
        node *fourth = new node(4);
        node *fifth = new node(5);
        node *sixth = new node(6);
        node *seventh = new node(7);

        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = fifth;
        fifth->next = sixth;
        sixth->next = seventh;
        seventh->next = third;
    }
    // cycle detection
    void cycle()
    {
        node *slow = head;
        node *fast = head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "Found Cycle\n";
                //Which position start cycle
                slow = head;
                while (slow != fast)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                cout << slow->data << endl;

                return;
            }
        }
        cout << "NO Cycle Found\n";
    }
};

int main()
{
    List li;
    li.cycle();

    return 0;
}
