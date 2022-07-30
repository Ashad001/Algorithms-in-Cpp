#include <iostream>
#include <vector>
using namespace std;

int Ceiling(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
            end = mid - 1;
        else
            return mid;
    }
    return start;

}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,4,6,8,9,20};
    int target = 5;
    int ans = Ceiling(arr, target);
    cout << ans;

    
    return 0;
}
