#include <iostream>
#include <vector>
using namespace std;

int FindMissing(vector<int> nums)
{
    int start = 0;
    int end = nums.size();
    while(start < end)
    {
        if(nums[start] > 0)
        {
            int index = nums[start] - 1;
            if(nums[start] != nums[index]  && nums[start] < end)
            {
                int temp = nums[start];
                nums[start] = nums[index];
                nums[index] = temp;
            }
            else
                start++;
        }
        else
            start++;
    } 
    for(int i = 0; i < end; i++)
    {
        if(nums[i] != i + 1)
        {
            return i+1;
        }
    }
    return nums.size() + 1;
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2};
    int ans = FindMissing(nums);
    cout << ans << endl;
    
    return 0;
}
