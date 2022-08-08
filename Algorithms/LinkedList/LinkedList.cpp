#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{}
    int value; 
    Node *next;
    public:
    Node(int val)
    {
        this->value = val;
    }
    Node(int val, Node *next)
    {
        this->value = val;
        this->next = next;
    }
    void InsertFirst(Node **head, int val)
    {
        Node *temp = new Node(val);
        temp->next = NULL;
        head = temp;
        if()

    }
};


int main(int argc, char const *argv[])
{

    
    return 0;
}
