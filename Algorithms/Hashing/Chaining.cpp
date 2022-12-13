#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define SIZE 10

class HashTable
{
public:
    int val;
    HashTable()
    {
    }
    HashTable(int v)
    {
        this->val = v;
    }
    bool operator==(int k)
    {
        return val == k;
    }
};
class HashMap
{
    vector<HashTable> *table;

public:
    HashMap()
    {
        this->table = new vector<HashTable>[SIZE];
    }
    int HashFunc(int k)
    {
        return k % SIZE;
    }
    void Insert(int v)
    {
        int k = HashFunc(v);
        table[k].push_back(HashTable(v));
    }
    int Search(int v)
    {
        int k = HashFunc(v);
        int i = 0;
        for (auto num : table[k])
        {
            if (num.val == v)
            {
                return i;
            }
            i++;
        }
        return -1;
    }
    int Remove(int v)
    {
        int s = HashFunc(v);
        int index = Search(v);
        vector<HashTable>::iterator i;
        for (i = table[s].begin(); i != table[s].begin(); i++)
        {
            if (i->val == v)
            {
                break;
            }
        }
        if (i != table[s].end())
        {
            table[s].erase(i);
        }
    }
    void Print()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " ";
            for (auto num : table[i])
            {
                cout << num.val << " -> ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    system("Cls");
    HashMap Mp;
    cout << " --------------- After Inserting --------------- " << endl;
    Mp.Insert(24);
    Mp.Insert(52);
    Mp.Insert(91);
    Mp.Insert(67);
    Mp.Insert(48);
    Mp.Insert(8);
    Mp.Insert(43);
    Mp.Insert(3);
    Mp.Insert(839);
    Mp.Print();
    cout << " --------------- After Removing --------------- " << endl;
    Mp.Remove(43);
    Mp.Print();
    return 0;
}
