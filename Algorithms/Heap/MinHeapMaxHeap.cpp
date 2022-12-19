#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

class MinHeap
{
public:
    int *arr;
    int cap;
    int top;
    MinHeap(int cap)
    {
        this->top = -1;
        this->cap = cap;
        this->arr = new int[cap];
    }

    void PrintArray()
    {
        for (int i = 0; i < this->top; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
    int GetMIn()
    {
        return (top == -1) ? INT_MIN : arr[0];
    }
    void Insert(int val)
    {
        if (this->top == cap)
        {
            cout << "Heap Full" << endl;
            return;
        }
        arr[++top] = val;
        int i = top;
        while (i != 0 && arr[i] < arr[(i - 1) / 2])
        {
            int p = (i - 1) / 2;
            int temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            i = p;
        }
    }
    int LinearSearch(int val)
    {
        for (int i = 0; i < this->top; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    int DeleteMin()
    {
        if (top == -1)
        {
            cout << "Heap is empty!" << endl;
            return INT_MAX;
        }
        if (top == 0)
        {
            return arr[top--];
        }
        int ret = arr[0];
        int secondMin = arr[top-- - 1];
        // top--;
        arr[0] = secondMin;
        Heapify(0);
        return ret;
    }
    int Delete(int val)
    {
        int key = LinearSearch(val);
        if (key < 0)
        {
            cout << "Val not found !" << endl;
            return INT_MIN;
        }
        if (key != -1)
        {
            int ret = arr[key];
            arr[key] = INT_MIN;
            int curr = key;
            while (curr != 0 && arr[(curr - 1) / 2] > arr[curr])
            {
                int temp = arr[curr];
                arr[curr] = arr[(curr - 1) / 2];
                arr[(curr - 1) / 2] = temp;
                curr = (curr - 1) / 2;
            }
            DeleteMin();
            return ret;
        }
        return INT_MIN;
    }
    void Heapify(int i)
    {
        int curr{0}, left{0}, right{0};

        curr = i;
        left = (2 * i) + 1;
        right = (2 * i) + 2;
        if (left < this->top && arr[left] < arr[i])
        {
            curr = left;
        }
        if (right < this->top && arr[right] < arr[i])
        {
            curr = right;
        }
        if (i != curr)
        {
            int temp = arr[i];
            arr[i] = arr[curr];
            arr[curr] = temp;
            Heapify(curr);
        }
    }
};

class MaxHeap
{
public:
    int *arr;
    int top;
    int cap;
    MaxHeap(int n)
    {
        this->top = -1;
        this->cap = n;
        this->arr = new int[cap];
    }
    void PrintHeap()
    {
        for (int i = 0; i < top; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
    int LinearSearch(int val)
    {
        int ret = -1;
        for (int i = 0; i < top; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    int GetMax()
    {
        return (top == -1) ? INT_MIN : arr[0];
    }
    void Insert(int val)
    {
        if (top == -1)
        {
            arr[++top] = val;
            return;
        }
        arr[++top] = val;
        int curr = top;
        int p = (curr - 1) / 2;
        while (curr != 0 && arr[curr] > arr[(curr - 1) / 2])
        {
            int temp = arr[curr];
            arr[curr] = arr[(curr - 1) / 2];
            arr[(curr - 1) / 2] = temp;
            curr = (curr - 1) / 2;
        }
        return;
    }
    int DeleteMax()
    {
        if (top == -1)
        {
            cout << "Heap is empty !" << endl;
            return INT_MIN;
        }
        if (top == 0)
        {
            return arr[top--];
        }
        int ret = arr[0];
        arr[0] = arr[top-- - 1];
        Heapify(0);

        return ret;
    }
    int Delete(int val)
    {
        int key = LinearSearch(val);
        if (key < 0)
        {
            cout << val << " not in heap!" << endl;
            return INT_MIN;
        }
        int ret = arr[key];
        arr[key] = INT_MIN;
        int curr = key;
        int p = (curr - 1) / 2;
        while (curr != 0 && arr[p] > arr[curr])
        {
            int temp = arr[curr];
            arr[curr] = arr[p];
            arr[p] = temp;
            p = (curr - 1) / 2;
            curr = p;
        }
        DeleteMax();
        return ret;
    }
    void Heapify(int i)
    {
        int curr = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < top && arr[left] > arr[curr])
        {
            curr = left;
        }
        if (right < top && arr[right] > arr[curr])
        {
            curr = right;
        }
        if (i != curr)
        {
            int temp = arr[i];
            arr[i] = arr[curr];
            arr[curr] = temp;
            i = curr;
            Heapify(i);
        }
    }
    void HeapSort()
    {
        int size = top;
        int s = top;
        for (int i = 0; i < s; i++)
        {
            int max = DeleteMax();
            arr[s - i - 1] = max;
        }
        top = s;
    }
};

// class Node
// {
// public:
//     static int key;
//     int data;
//     Node *left;
//     Node *right;
//     Node(int key, int d)
//     {
//         this->key = key;
//         this->data = d;
//         this->left = this->right = NULL;
//     }
// };
// int Node::key = 0;

// class MaxHeap
// {
// public:
//     Node *root;
//     MaxHeap()
//     {
//         this->root = NULL;
//     }
//     void InsertM(int val)
//     {
//         this->root = insert(root, val);
//     }
//     Node *insert(Node *root, int val)
//     {
//         if (root == NULL)
//         {
//             cout << Node::key << "< ";
//             return new Node(Node::key, val);
//         }
//         if (val < root->data)
//         {
//             root->left = insert(root->left, val);
//         }
//         else if (val > root->data)
//         {
//             root->right = insert(root->right, val);
//         }
//         return root;
//     }
//     vector<int> postOrderIterative()
//     {
//         vector<int> postOrderList;
//         if (root == NULL)
//             return postOrderList;
//         stack<Node *> S;
//         S.push(root);
//         Node *prev = NULL;
//         while (!S.empty())
//         {
//             auto current = S.top();
//             if (prev == NULL || prev->left == current || prev->right == current)
//             {
//                 if (current->left)
//                     S.push(current->left);
//                 else if (current->right)
//                     S.push(current->right);
//                 else
//                 {
//                     S.pop();
//                     postOrderList.push_back(current->key);
//                 }
//             }

//             else if (current->left == prev)
//             {
//                 if (current->right)
//                     S.push(current->right);
//                 else
//                 {
//                     S.pop();
//                     postOrderList.push_back(current->key);
//                 }
//             }
//             else if (current->right == prev)
//             {
//                 S.pop();
//                 postOrderList.push_back(current->key);
//             }
//             prev = current;
//         }
//         return postOrderList;
//     }
// };

int main(int argc, char const *argv[])
{
    cout << "<->-<-->-<-->-<--> MIN-HEAP <-->-<-->-<-->-<->" << endl;
    MinHeap heap(10);
    heap.Insert(36);
    heap.Insert(33);
    heap.Insert(42);
    heap.Insert(10);
    heap.Insert(14);
    heap.Insert(19);
    heap.Insert(27);
    heap.Insert(44);
    heap.Insert(26);
    heap.Insert(31);
    cout << "INSERTING: ";
    heap.PrintArray();
    cout << "Deleting 42: ";
    heap.Delete(42);
    heap.PrintArray();
    cout << "<->-<-->-<-->-<--> MAX-HEAP <-->-<-->-<-->-<->" << endl;
    MaxHeap mheap(10);
    mheap.Insert(35);
    mheap.Insert(33);
    mheap.Insert(42);
    mheap.Insert(10);
    mheap.Insert(14);
    mheap.Insert(19);
    mheap.Insert(27);
    mheap.Insert(44);
    mheap.Insert(26);
    mheap.Insert(31);
    cout << "INSERTING: ";
    mheap.PrintHeap();
    mheap.Delete(35);
    cout << "Deleting 35: ";
    mheap.PrintHeap();
    mheap.HeapSort();
    cout << "Sorted Heap: ";
    mheap.PrintHeap();

    return 0;
}
