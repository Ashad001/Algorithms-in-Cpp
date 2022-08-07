#include <iostream>
#include <vector>
using namespace std;

void HeapSort(vector<int> &arr, int low, int high)
{
    if(low >= high)
        return;
    int start = low;
    int end = high;
    int mid = start + (end - start) / 2;
    int pivot = arr[mid];

    while(start <= end)
    {
        while(arr[start] < pivot)
            start++;
        while(arr[end] > pivot)
            end--;
        
        if(start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    HeapSort(arr, low, end);
    HeapSort(arr, start, high);
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2,9,3,2};
    HeapSort(arr, 0, arr.size() - 1);
    for(auto nums : arr)
        cout << nums << " ";


    return 0;
}
