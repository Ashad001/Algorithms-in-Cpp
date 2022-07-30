#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else 
        {
            end = mid - 1;
        }
    }
    return -1;
    
;}

int main(int argc, char const *argv[])
{
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    int ans = BinarySearch(input, 10);
    cout << ans;
    
    return 0;
}
