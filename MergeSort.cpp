#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Merge(vector<int> &first, vector<int> &second)
{
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> mix(first.size() + second.size());
    while (i < first.size() && j < second.size())
    {
        if (first[i] < second[j])
        {
            mix[k] = first[i];
            i++;
        }
        else
        {
            mix[k] = second[j];
            j++;
        }
        k++;
    }

    // it may be possible that one of the arrays is not complete
    // copy the remaining elements
    while (i < first.size())
    {
        mix[k] = first[i];
        i++;
        k++;
    }

    while (j < second.size())
    {
        mix[k] = second[j];
        j++;
        k++;
    }

    return mix;
};

vector<int> MergeSort(vector<int> &arr)
{
    if (arr.size() == 1)
        return arr;
    int mid = arr.size() / 2;
    vector<int> right;
    right.assign(arr.begin(), arr.end() - mid);
    right = MergeSort(right);

    vector<int> left;
    left.assign(arr.begin() + (mid), arr.end());
    left = MergeSort(left);

    return Merge(right, left);
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {5, 4, 3, 2, 1};
    vector<int> ans = MergeSort(arr);
    for (auto nums : ans)
    {
        cout << nums << " ";
    }

    return 0;
}
