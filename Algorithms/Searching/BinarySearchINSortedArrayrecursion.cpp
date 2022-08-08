#include <iostream>
#include <vector>
using namespace std;

int Search(vector<int> arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    if(start > end)
        return -1;
    if(arr[mid] == target)
        return mid;
    if(arr[start] <= arr[mid])
    {
        if(target < arr[mid] && target >= arr[start])
            return Search(arr, target, start, mid - 1);
        else
            return Search(arr, target, mid + 1, end);
    }
    else
    {
        if(target > arr[mid] && target <= arr[end])
            return Search(arr, target, mid + 1, end);
        else 
            return Search(arr, target, start, mid - 1);
    }



}


int main(int argc, char const *argv[])
{
    vector<int> arr = {5,6,1,2,3,4};
    cout << Search(arr, 5, 0, arr.size());
    return 0;
}
