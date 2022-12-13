
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define SIZE 8

class HashNode
{
public:
    int val;
    HashNode *next;
    HashNode(int data = 0)
    {
        this->val = data;
        this->next = NULL;
    }
};
class HashTable
{
public:
    HashNode **Hash;
    HashTable()
    {
        Hash = new HashNode *[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            Hash[i] = NULL;
        }
    }
    int HashFunc(int val)
    {
        return (val % SIZE);
    }
    void Insert(int val)
    {
        HashNode *insert = new HashNode(val);
        int k = HashFunc(val);
        if (Hash[k] == NULL)
        {
            Hash[k] = insert;
            return;
        }
        HashNode *temp = Hash[k];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        insert->next = NULL;
        temp->next = insert;
    }
    void PrintHashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            HashNode *temp = Hash[i];
            cout << i << " --> ";
            while (temp != NULL)
            {
                cout << temp->val << " -> ";
                temp = temp->next;
            }
            cout << "END " << endl;
        }
    }
    int Search(int val)
    {
        int key = HashFunc(val);
        HashNode *temp = Hash[key];
        int i = 0;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                return i;
            }
            i++;
            temp = temp->next;
        }
        return -1;
    }
    void Remove(int val)
    {
        int index = Search(val);
        int key = HashFunc(val);
        if (index != -1)
        {
            HashNode *temp = Hash[key];
            if (index == 0)
            {
                Hash[key] = Hash[key]->next;
            }
            else
            {
                for (int i = 0; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next = temp->next->next;
                }
                else
                {
                    temp->next = NULL;
                }
            }
        }
        else
        {
            cout << "NO SUCH VALUE FOUND IN HASHTABLE!" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    HashTable hashmap;
    cout << " ---------------- After Inserting ----------------" << endl;
    hashmap.Insert(1);
    hashmap.Insert(11);
    hashmap.Insert(21);
    hashmap.Insert(2);
    hashmap.Insert(4);
    hashmap.Insert(5);
    hashmap.Insert(46);
    hashmap.Insert(15);
    hashmap.Insert(143);
    hashmap.Insert(1343);
    hashmap.Insert(1342);
    hashmap.Insert(1142);
    hashmap.PrintHashTable();
    cout << " ---------------- After Removing ----------------" << endl;
    hashmap.Remove(46);
    hashmap.PrintHashTable();
    return 0;
}
