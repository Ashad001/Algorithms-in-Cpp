#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define SIZE 128

class HashNode
{
public:
    int key;
    int val;
    HashNode(int k, int v)
    {
        this->key = k;
        this->val = v;
    }
    HashNode()
    {
        this->key = -1;
        this->val = 0;
    }
    bool operator==(int k)
    {
        return this->val == 0;
    }
};
class HashMap
{
private:
    vector<HashNode> MAP;

public:
    HashMap()
    {
        MAP = vector<HashNode>(SIZE);
    }
    int HashFunc(int k)
    {
        return k % SIZE;
    }
    int LinearProbing(int k, int i)
    {
        int Hash = HashFunc(k);
        return (Hash + i) % SIZE;
    }
    int Insert(int val)
    {
        int k;
        bool alreadyExist = false;
        int i = 0;
        while (!alreadyExist)
        {
            k = LinearProbing(val, i);
            if (MAP[k] == 0)
            {
                MAP[k].val = val;
                MAP[k].key = k;
                alreadyExist = true;
            }
            i++;
        }
    }
    int Search(int val)
    {
        int i = 0;
        while (1)
        {
            int key = LinearProbing(val, i);
            if (MAP[key].val == val)
            {
                return key;
            }
            if (i > SIZE)
            {
                break;
            }
            i++;
        }
        return -1;
    }
    void Remove(int val)
    {
        int index = Search(val);
        MAP[index].key = -1;
        MAP[index].val = 0;
    }
    void Print()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << MAP[i].key << ", " << MAP[i].val << endl;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    HashMap mp;
    cout << " ------------ After Inserting ------------" << endl;
    mp.Insert(1);
    mp.Insert(13);
    mp.Insert(8);
    mp.Insert(9);
    mp.Insert(11);
    mp.Insert(12);
    mp.Insert(7);
    mp.Print();
    cout << " ------------ After Removing ------------" << endl;
    mp.Remove(1);
    mp.Print();
    return 0;
}
