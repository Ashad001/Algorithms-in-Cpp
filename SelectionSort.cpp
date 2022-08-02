#include <iostream>
#include <vector>
using namespace std;

int Min(vector<int> &arr, int start, int end)
{
    int min = INT_MAX; 
    int index = 0;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

void SelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int first = i;
        int last = Min(arr, first, arr.size());
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {5,4,3,21,1};
    SelectionSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";

    return 0;
}