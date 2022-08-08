#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
};
struct Node *Head;
void Insert(int data, int n)
{
    Node *temp1 = new Node;
    temp1->Data = data;
    temp1->Next = NULL;
    if(n == 1)
    {
        temp1->Next = Head;
        Head = temp1;
        return;
    }
    Node *temp2 = Head;
    for(int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->Next;
    }
    temp1->Next = temp2->Next;
    temp2->Next = temp1;
}
void Print()
{
    Node *temp = Head;
    while(temp != NULL)
    {
        cout << temp->Data << " " ;
        temp = temp->Next;
    }
    cout << endl;
}
void Delete(int n)
{
    Node *temp1 = Head;
    if(n == 1)
    {
        Head = temp1->Next;
        delete temp1;
        return;
    }
    for(int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->Next;
    }
    Node *temp2 = temp1->Next;
    temp1->Next = temp2->Next;
    delete temp2;

}

int main(int argc, char const *argv[])
{
    Head = NULL;
    Insert(5,1);
    Insert(4,2);
    Insert(3,3);
    Insert(1,4);
    Print();
    Delete(3);
    Print();
    
    return 0;
}

