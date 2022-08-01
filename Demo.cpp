#include <iostream>
#include <vector>
using namespace std;

int Check(vector<int> arr, int target)
{
    return arr.size();
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,4,4};
    int start = INT_MIN;
    int end = 0;
    for (int i = 0; i < nums.size() ; i++)
    {
        if (nums[i] >= start)
            start = nums[i];
        end += nums[i];
    }
    cout << start << " " << end << endl;

    return 0;
}