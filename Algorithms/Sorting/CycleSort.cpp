#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void CycleSort(vector<int> &arr)
{
    
    int start = 0;
    int end = arr.size();
    while (start < end)
    {
        int index = arr[start] - 1;
        if (arr[start] !=  arr[index])
        {
            int temp = arr[start];
            arr[start] = arr[index];
            arr[index] = temp;
        }
        else
        {
            start++;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {3,5,2,1,4};
    CycleSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";

    return 0;
}
