#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int start, int mid , int end)
{
    int i = start, j = mid, k = 0;
    vector<int> merge(end - start);

    while(i < mid && j < end)
    {
        if(arr[i] < arr[j])
        {
            merge[k] = arr[i];
            i++;
        }
        else 
        {
            merge[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i < mid)
    {
        merge[k] = arr[i];
        k++;
        i++;
    }
    while(j < end)
    {
        merge[k] = arr[j];
        k++;
        j++;
    }
    for(int i = 0; i < merge.size(); i++)
    {
        arr[start + i] = merge[i];
    }

}

void MergeSort(vector<int> &arr, int start , int end)
{
    if(end - start == 1)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid, end);

    Merge(arr, start, mid, end);
};


int main(int argc, char const *argv[])
{
    vector<int> arr = {2,5,4,3,1};
    MergeSort(arr, 0, arr.size());
    for(auto nums : arr)
        cout << nums << " ";
    
    return 0;
}
