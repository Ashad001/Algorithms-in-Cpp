#include <iostream>
#include <vector>
using namespace std;

int OrderAgnosticBS(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    bool isAsc = arr[start] < arr[end];
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (isAsc)
        {
            if (arr[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            if (arr[mid] < target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;

    
}

int main(int argc, char const *argv[])
{
    vector<int> input = {9,8,7,6,5,4,3,2,1};
    int ans = OrderAgnosticBS(input, 9);
    cout << ans;

    return 0;
}
