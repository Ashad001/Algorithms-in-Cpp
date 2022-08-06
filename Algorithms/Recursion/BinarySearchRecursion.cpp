#include <iostream>
#include <vector>
using namespace std;

int Search(vector<int> arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (start <= end)
    {
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            return Search(arr, target, start, mid - 1);
        else
            return Search(arr, target, mid + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5, 7};
    int ans = Search(arr, 5, 0, 6);
    cout << ans;

    return 0;
}
