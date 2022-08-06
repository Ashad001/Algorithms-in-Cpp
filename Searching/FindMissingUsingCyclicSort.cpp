#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int start = 0;
    int end = nums.size();
    while (start < end)
    {
        int index = nums[start];
        if (nums[start] != nums[index] && nums[start] < end)
        {
            int temp = nums[start];
            nums[start] = nums[index];
            nums[index] = temp;
        }
        else
            start++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums[i])
            return i;
    }
    return nums.size();
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {1,0};
    int ans = missingNumber(arr);
    cout << ans;

    return 0;
}
