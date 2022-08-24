#include <iostream>
#include <vector>
using namespace std;

int CountRotation(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] > arr[mid + 1] && mid < end)
            ans = mid;
        if(arr[mid] < arr[mid - 1] && mid > start)
            ans = mid - 1;
        if(arr[mid] >= arr[start])
            start = mid + 1;
        else 
            end = mid - 1;
    }
    if(ans == 0)
        ans = -1;
    return arr[ans + 1];
}

int main(int argc, char const *argv[])
{
    vector<int> input = {3,4,5,1,2};
    int ans = CountRotation(input);
    cout << ans << endl;
    
    return 0;
}
