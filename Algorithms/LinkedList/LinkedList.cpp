#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int val, Node *node = NULL)
    {
        this->data = val;
        this->next = node;
    }
};

class LinkedList
{

    Node *head;

public:
    bool isEmpty()
    {
        return head == NULL;
    }
    void pop_front()
    {
        Node *temp = head;
        if (head != NULL)
            head = head->next;
        delete temp;
    }
    void pop_back()
    {
        Node *temp2 = head;
        for (int i = 0; i < Count() - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp2->next = NULL;
    }
    void push_front(int val)
    {
        head = new Node(val, head);
    }
    void push_back(int val)
    {
        if (head == NULL)
        {
            head = new Node(val, head);
        }
        else
        {
            Node *temp1 = new Node(val, NULL);
            Node *temp2 = head;
            for (int i = 0; i < Count() - 1; i++)
            {
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
        }
    }
    void ShowAll()
    {
        if (head == NULL)
        {
            cout << "List Empty" << endl;
        }
        for (auto *temp = head; temp != NULL; temp = temp->next)
        {
            if (temp == head)
                cout << "[ ";
            if (temp->next != NULL)
            {
                cout << temp->data << ", ";
            }
            else
            {
                cout << temp->data << " ]";
            }
        }
        cout << endl;
    }
    int Count()
    {
        int count = 0;
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            count++;
        }
        return count;
    }
    void Insert(int i, int val)
    {
        Node *insert = new Node(val);
        if (head == NULL && i == 0)
        {
            head = insert;
        }
        if (i == 0)
        {
            insert->next = head;
            head = insert;
        }
        else if (head != NULL && i <= Count())
        {
            Node *temp2 = head;
            for (int j = 0; j < i - 1; j++)
            {
                temp2 = temp2->next;
            }
            insert->next = temp2->next;
            temp2->next = insert;
        }
        else
        {
            cout << "Error: Index out of bound!" << endl;
        }
    }
    void Assign(int i, int val)
    {
        Node *assign = new Node(val);
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else if (head != NULL && i <= Count())
        {
            Node *temp = head;
            for (int j = 0; j < i - 1; j++)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next->next;
            assign->next = temp2;
            temp->next = assign;
        }
    }
    // LinkedList SubList(int start, int end)
    // {
    //     LinkedList HEAD;
    //     if (start > end || end > this->Count())
    //         return HEAD;

    //     Node *temp = this->head;
    //     for (int i = 0; i < start - 1; i++)
    //     {
    //         temp = temp->next;
    //     }
    //     HEAD.head = temp;
    //     Node *temp1 = HEAD.head;
    //     Node *temp2 = HEAD.head;
    //     for(int i = 0; i < end - 1; i++)
    //     {
    //         temp2 = temp2->next;
    //     }
    //     temp2->next = NULL;
    //     temp1 = temp2;
    //     temp2 = HEAD.head; 
    //     return HEAD;
    // }
};

int main(int argc, char const *argv[])
{
    LinkedList list;
    list.push_back(7);  // [7]
    list.push_front(5); // [5,7]
    list.push_front(6); // [6,5,7]
    list.push_back(9);  // [6,5,7,9]
    list.ShowAll();

    list.Insert(1, 8); // [6,8,5,7,9]
    // list.ShowAll();
    // list.Assign(2, 2); // [8,5,2,9,5];
    list.ShowAll();
    // LinkedList sub = list.SubList(2,3);
    // sub.ShowAll();

    return 0;
}
