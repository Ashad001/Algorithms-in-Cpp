#include <iostream>
#include <vector>
using namespace std;


int DuplicateNumber(vector<int> &nums)
{
    int start = 0;
    int end = nums.size();
    while (start < end)
    {
        int index = nums[start] - 1;
        if (nums[start] != nums[index] && nums[start] < end)
        {
            int temp = nums[start];
            nums[start] = nums[index];
            nums[index] = temp;
        }
        else if(nums[start] == nums[index] && start != index)
            return nums[start];
        else 
            start++;
    }
   
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {1,3,4,2,2};
    int ans = DuplicateNumber(arr);
    cout << ans;

    return 0;
}