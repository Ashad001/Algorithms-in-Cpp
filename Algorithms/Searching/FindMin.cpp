#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &nums)
{
    int ans = INT_MIN;
    int start = 0;
    int end = nums.size() - 1;
    if (end = 0 || nums[end] > nums[start])
    {
        return nums[0];
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] < nums[mid - 1] && mid > start)
        {
            return nums[mid + 1];
        }
        if (nums[mid] > nums[mid + 1] && mid < end)
        {
            return nums[mid];
        }
        if (nums[start] < nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return INT_MAX;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2};
    cout << findMin(arr);

    return 0;
}
