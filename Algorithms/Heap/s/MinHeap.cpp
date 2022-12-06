#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap
{
    inline int Parent(int i)
    {
        return (i - 1) / 2;
    }
    inline int left(int i)
    {
        return 2 * i + 1;
    }
    inline int right(int i)
    {
        return 2 * i + 2;
    }

public:
    int *arr;
    int size;
    int cap;
    MinHeap(int cap)
    {
        this->size = 0;
        this->cap = cap;
        this->arr = new int[cap];
    }
    int Search(int val)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    int GetMin()
    {
        return (size == 0) ? INT_MAX : arr[0];
    }
    void printHeap()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return this->size;
    }
    void Insert(int i)
    {
        if (size == this->cap)
        {
            cout << "heap full " << endl;
            return;
        }
        arr[size] = i;
        int s = size++;
        while (s != 0 && arr[s] < arr[Parent(s)])
        {
            swap(&arr[s], &arr[Parent(s)]);
            s = Parent(s);
        }
    }
    int ExtractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            return arr[--size];
        }
        int base = arr[0];
        arr[0] = arr[size-- - 1];
        Heapify(0);
        return base;
    }
    void Heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int curr = i;
        if (l < size && arr[l] < arr[i])
        {
            curr = l;
        }
        if (r < size && arr[r] < arr[curr])
        {
            curr = r;
        }
        if (i != curr)
        {
            swap(arr[i], arr[curr]);
            Heapify(curr);
        }
    }
};

int main(int argc, char const *argv[])
{
    MinHeap hp(7);
    hp.Insert(5);
    hp.Insert(1);
    hp.Insert(346);
    hp.Insert(34);
    hp.Insert(25);
    hp.Insert(24);
    hp.Insert(3);
    hp.Insert(2);
    hp.printHeap();
    hp.ExtractMin();
    hp.printHeap();
    
    return 0;
}
