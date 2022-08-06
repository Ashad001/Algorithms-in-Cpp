#include <iostream>
#include <vector>
using namespace std;

void Sort(vector<int> &arr, int r, int c)
{
    if (r == 0)
        return;
    if (r > c)
    {
        if (arr[c] > arr[c + 1])
        {
            int temp = arr[c];
            arr[c] = arr[c + 1];
            arr[c + 1] = temp;
        }
        Sort(arr, r, c + 1);
    }
    else
        Sort(arr, r - 1, 0);
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 3, 4, 2, 6, 7, 9, 8};
    Sort(arr, arr.size() - 1, 0);
    for (auto num : arr)
        cout << num << " ";

    return 0;
}
