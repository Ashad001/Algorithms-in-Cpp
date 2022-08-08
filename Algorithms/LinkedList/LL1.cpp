#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *Next;
};
void Insert(Node **Head, int n)
{
    Node *temp = new Node;
    temp->Data = n;
    temp->Next = NULL;
    if (Head != NULL)
    {
        temp->Next = *Head;
    }
    *Head = temp;
}
void Print(Node *Head)
{
    cout << "List is: ";
    while (Head != NULL)
    {
        // cout << Head->Data << " " ;
        printf("%d ", Head->Data);
        Head = Head->Next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Node *Head = NULL;
    int n;
    cout << "Enter Numbers: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter any number: " << endl;
        cin >> x;
        Insert(&Head, x);
        Print(Head);
    }

    return 0;
}
