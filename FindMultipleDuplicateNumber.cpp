#include <iostream>
#include <vector>
using namespace std;

vector<int> DuplicateNumber(vector<int> &nums)
{
    int start = 0;
    int end = nums.size();

    vector<int> out;
    while (start < end)
    {
        int index = nums[start] - 1;
        if (nums[start] != nums[index])
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
        if (nums[i] != i + 1)
            out.push_back(nums[i]);
    }
    return out;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 1,4,3,3};
    vector<int> ans = DuplicateNumber(arr);
    for (auto num : ans)
        cout << num << " , ";

    return 0;
}