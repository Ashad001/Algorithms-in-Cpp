#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val, Node *next = NULL)
    {
        this->data = val;
        this->next = next;
    }
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *Head;

public:
    LinkedList()
    {
        Head = NULL;
    }
    LinkedList(Node *cNode)
    {
        this->Head = cNode;
    }
    Node GetHead()
    {
        return *Head;
    }
    Node *GetNode(int index)
    {
        Node *temp = Head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    void Display()
    {
        Node *temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void AddNodeToLast(int val)
    {
        if (Head == NULL)
        {
            Head = new Node(val, NULL);
            return;
        }
        else
        {
            Node *temp = Head;
            Node *insert = new Node(val, NULL);
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            insert->next = temp->next;
            temp->next = insert;
        }
    }
    void AddFirst(int val)
    {
        if (Head == NULL)
        {
            Head = new Node(val);
            return;
        }
        Node *insert = new Node(val);
        insert->next = Head;
        Head = insert;
    }
    void DisplayEvenly()
    {
        Node *temp = Head;
        Node *even = NULL;
        Node *odd = NULL;
        if (temp->data % 2 == 0)
        {
            even = temp;
            temp = temp->next;
        }
        else
        {
            odd = temp;
            temp = temp->next;
        }
        Node *curr = temp;
        Node *new_head = curr;
        Display();
        while (curr != NULL)
        {
            if (even->data % 2 == 0)
            {
                curr->next = even;
                even = even->next;
            }
            else
            {
                curr->next = odd;
                odd = odd->next;
            }
            curr = curr->next;
        }
        Head = new_head;
        Display();
    }
    void Update(int index, int val)
    {
        Node *temp = Head;
        Node *update = new Node(val, Head);
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = update;
        update->next = temp2;
    }
    Node *InsertThroughRecursion(int index, int val, Node *curr)
    {
        if (curr == NULL)
        {
            return NULL;
        }
        if (index == 0)
        {
            Node *insert = new Node(val, curr);
            return insert;
        }
        curr->next = (InsertThroughRecursion(index - 1, val, curr->next));
        return curr;
    }
    void RemoveDups()
    {
        Node *temp = Head;
        while (temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
};
bool TheVanillaTriangle(LinkedList List)
{
    Node *Prev = List.Head;
    Node *Next = List.Head;
    while (1)
    {
        if (Prev == NULL && Next == NULL)
        {
            return false;
        }
        Next = Next->next->next;
        if (Prev == Next)
        {
            return true;
        }
        Prev = Prev->next;
    }
}

Node *MergeList(Node *list1, Node *list2)
{
    Node *head = new Node();
    Node *temp = head;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    temp->next = (list1 != NULL) ? list1 : list2;

    return head->next;
}

Node *Middle(Node *head)
{
    Node *temp = NULL;
    while (head != NULL && head->next != NULL)
    {
        if (temp == NULL)
        {
            temp = head;
        }
        else
        {
            temp = temp->next;
        }
        head = head->next->next;
    }
    Node *mid = temp->next;
    temp->next = NULL;
    return mid;
}
Node *MergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = Middle(head);
    Node *left = MergeSort(head);
    Node *right = MergeSort(mid);

    return MergeList(left, right);
}

Node *Reverse(Node *Head)
{
    Node *temp = Head;
    Node *prev = NULL;
    Node *Next = temp->next;
    while (temp != NULL)
    
    {
        temp->next = prev;
        prev = temp;
        temp = Next;
        if (Next != NULL)
        {
            Next = Next->next;
        }
    }
    Head = prev;
    return Head;
}

bool isPalindrome(Node *head)
{
    Node *temp = head;
    Node *mid = Middle(head);
    Node *tempMid = mid;
    mid = Reverse(mid);
    while (mid != NULL && temp != NULL)
    {
        if (temp->data != mid->data)
        {
            Reverse(tempMid);
            return false;
        }
        temp = temp->next;
        mid = mid->next;
    }
    temp->next = Reverse(tempMid);
    return true;
}

Node *MinMax(Node *head)
{
    Node *temp = head;
    Node *mid = Middle(head);
    Node *tempMid = mid;
    mid = Reverse(mid);
    LinkedList list;
    list.Head = mid;
    list.Display();
    Node *output = new Node;
    Node *tempOut = output;
    while(temp != NULL && mid != NULL)
    {
        tempOut = temp;
        temp = temp->next;
        tempOut = tempOut->next;
        tempOut = mid;
        mid = mid->next;
        tempOut = tempOut->next;
    }
    temp->next = Reverse(tempOut);

    return output->next;

}

int main(int argc, char const *argv[])
{
    LinkedList list;
    list.AddFirst(6);
    list.AddFirst(5);
    list.AddFirst(4);
    list.AddFirst(3);
    list.AddFirst(2);
    list.AddFirst(1);
    list.Display();

    Node *newNode = MinMax(list.Head);
    LinkedList newList;
    newList.Head = newNode;
    newList.Display();
    // Node *newNode = MergeSort(list.Head);
    // LinkedList newList;
    // newList.Head = newNode;
    // list.Display();
    // cout << isPalindrome(list.Head) << endl;
    // list.Display();
    // list.Head = Reverse(list.Head);
    // list.Display();

    // Node *mid = Middle(list.Head);
    // LinkedList midlis;
    // midlis.Head = mid;
    // midlis.Display();

    // LinkedList list2;
    // list2.AddFirst(5);
    // list2.AddFirst(3);
    // list2.AddFirst(1);
    // list2.AddFirst(0);
    // list2.AddFirst(-1);

    // list2.Display();
    // LinkedList mergedList = MergeList(list.Head, list2.Head);
    // mergedList.Display();

    return 0;
}
