#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL) {}
};
class LL
{
public:
    Node *head;
    void insert(int val)
    {
        Node *in = new Node(val);
        if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = in;
        in->next = NULL;
    }
    void print()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << endl
             << endl;
    }
};

void swapNodes(Node *&head)
{
    Node *current = head;
    while (current && current->next)
    {
        // Save pointers to current and next nodes
        Node *currentNode = current;
        Node *nextNode = current->next;
        // Swap next pointers of current and next nodes
        currentNode->next = nextNode->next;
        nextNode->next = currentNode;
        // Update head if necessary
        if (currentNode == head)
        {
            head = nextNode;
        }
        // Update previous node's next pointer if it exists
        if (current != head)
        {
            Node *prevNode = head;
            while (prevNode->next != currentNode)
            {
                prevNode = prevNode->next;
            }
            prevNode->next = nextNode;
        }
        // Update current pointer
        current = currentNode->next;
    }
}
void rotateList(Node *&head, int k)
{
    // Find the length of the linked list
    int n = 0;
    Node *current = head;
    while (current)
    {
        ++n;
        current = current->next;
    }
    // Calculate the new starting position for the rotated linked list
    k %= n;
    if (k == 0)
    {
        return;
    }
    // Set the next pointer of the last node to the head of the linked list
    current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = head;
    // Set the head of the linked list to the node at the new starting position
    current = head;
    for (int i = 0; i < n - k - 1; ++i)
    {
        current = current->next;
    }
    head = current->next;
    // Set the next pointer of the node at the old starting position to nullptr
    current->next = nullptr;
}
void DeleteDuplicates(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
}

void Print(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << ", ";
        curr = curr->next;
    }
    cout << endl;
}

Node *addNodes(Node *num1, Node *num2)
{
    Node *v1 = num1;
    Node *v2 = num2;
    int c = 0;
    Node *tempHead = new Node(0);
    Node *temp = tempHead;
    while (c || v1 || v2)
    {
        c += v1 ? v1->val : 0;
        c += v2 ? v2->val : 0;
        temp->next = new Node(c % 10);
        temp = temp->next;
        c /= 10;
        if (v1)
        {
            v1 = v1->next;
        }
        if (v2)
        {
            v2 = v2->next;
        }
    }
    return tempHead->next;
}

int main(int argc, char const *argv[])
{

    Node *head = NULL;
    for (int i = 5; i >= 1; --i)
    {
        Node *temp = new Node(i);
        temp->next = head;
        head = temp;
    }
    Node *num2 = NULL;
    for (int i = 5; i >= 1; i--)
    {
        Node *temp = new Node(i);
        temp->next = num2;
        num2 = temp;
    }
    Print(head);
    Print(num2);
    // // swapNodes(head);
    // DeleteDuplicates(head);
    // Print(head);
    // Node *num1 = NULL;
    // Node *temp = new Node(1);
    // temp->next = num1;
    // temp->next = new Node(2);
    // temp->next = new Node(3);
    // num1 = temp;
    // Node *num2 = NULL;
    Node *sum = addNodes(head, num2);
    Print(sum);

    return 0;
}
