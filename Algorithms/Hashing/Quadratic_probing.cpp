#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define SIZE 17
#define PRIME 11

class HashVal
{
public:
    int val;
    HashVal(int data = -1)
    {
        this->val = data;
    }
    bool operator!=(int num)
    {
        return val != num;
    }
};
class DoubleHashing
{
    int Hash1(int val)
    {
        return val % SIZE;
    }
    int Hash2(int val)
    {
        return PRIME - (val % PRIME);
    }
    int HashFunc(int val, int i)
    {
        return (Hash1(val) + (i * Hash2(val))) % SIZE;
    }

public:
    HashVal *Hash;
    int curr;
    DoubleHashing()
    {
        this->curr = 0;
        Hash = new HashVal[SIZE];
    }
    void Insert(int val)
    {
        if (curr == SIZE)
        {
            cout << val << " not added, Table is Full !" << endl;
            return;
        }

        int i = 0;
        while (true)
        {
            int key = HashFunc(val, i);
            if (Hash[key].val == -1)
            {
                Hash[key].val = val;
                break;
            }
            i++;
        }
        this->curr++;
    }
    int Search(int val)
    {
        int i = 0;
        while (true)
        {
            int key = HashFunc(val, i);
            if (Hash[key].val == val)
            {
                return key;
            }
            i++;
        }
    }
    void Remove(int val)
    {
        int index = Search(val);
        Hash[index].val = -1;
    }
    void PrintDoubleHash()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " -> ";
            cout << Hash[i].val;
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "----------- After Inserting -----------" << endl;
    DoubleHashing DH;
    DH.Insert(1);
    DH.Insert(2);
    DH.Insert(3);
    DH.Insert(4);
    DH.Insert(8);
    DH.Insert(9);
    DH.Insert(10);
    DH.Insert(11);
    DH.Insert(13);
    DH.Insert(21);
    DH.Insert(11);
    DH.Insert(133);
    DH.Insert(13);
    DH.Insert(15);
    DH.Insert(16);
    DH.Insert(188);
    DH.Insert(124);
    DH.Insert(166);
    DH.PrintDoubleHash();
    cout << "----------- After Removing -----------" << endl;
    DH.Remove(124);
    DH.PrintDoubleHash();

    return 0;
}
