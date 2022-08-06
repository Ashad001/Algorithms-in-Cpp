#include <iostream>
#include <vector>
using namespace std;

int FindLargestElement(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start != end)
    {
        int mid = (start + end) / 2;
        if(arr[mid] < arr[mid + 1])
            start = mid + 1;
        else if(arr[mid] > arr[mid + 1])
            end = mid;
    }
    return arr[start];

}


int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5,6,4,3,2,1};
    int ans = FindLargestElement(arr);
    cout << ans;

    
    return 0;
}
