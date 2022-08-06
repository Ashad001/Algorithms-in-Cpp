#include <iostream>
#include <vector>
using namespace std;

int index = 0;
void Sort(vector<int> &arr, int max, int start, int end)
{
    if (end == 0)
        return;
    if (start < end)
    {
        if (arr[start] > arr[max])
        {
            Sort(arr, start, start + 1, end);
        }
        else
        {
            Sort(arr, max, start + 1, end);
        }
    }

    else
    {
        int temp = arr[max];
        arr[max] = arr[end - 1];
        arr[end - 1] = temp;
        Sort(arr, 0, 0, end - 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 4, 6, 1, 3, 7, 9};
    Sort(arr, 0, 0, arr.size());
    cout << endl;
    for (auto nums : arr)
    {
        cout << nums << " ";
    }

    return 0;
}
