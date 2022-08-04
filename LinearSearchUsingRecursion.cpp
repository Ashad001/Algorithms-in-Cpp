#include <iostream>
#include <vector>
using namespace std;

bool IsSort(vector<int> arr, int i)
{
    if (arr[i] <= arr[i + 1] && i == arr.size() - 2)
        return 1;

    if (arr[i] <= arr[i + 1])
    {
        return 1 && IsSort(arr, i + 1);
    }
    else
    {
        return 0;
    }
};

bool LinearSearch(vector<int> arr)
{
    return IsSort(arr, 0);
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {50,60,70,80,9};
    bool ans = LinearSearch(arr);
    cout << ans;

    return 0;
}
