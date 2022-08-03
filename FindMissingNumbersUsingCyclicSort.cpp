#include <iostream>
#include <vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> out;
    int start = 0;
    int end = nums.size();
    while (start < end)
    {
        int index = nums[start] - 1;
        if (nums[start] !=  nums[index])
        {
            int temp = nums[start];
            nums[start] = nums[index];
            nums[index] = temp;
        }
        else 
        {
            start++;
        }
    }
    
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
        {
            out.push_back(i+1);
            j++;
        }
    }
    return out;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,1};
    vector<int> out = findDisappearedNumbers(arr);
    for(auto num : out)
        cout << num << " , ";
        

    return 0;
}
