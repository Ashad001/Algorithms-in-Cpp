#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    vector<int> count(max + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        count[arr[i]]++;
    int j = 0;
    for (int i = 0; i < count.size(); i++)
        while (count[i]--)
            arr[j++] = i;
};

int main(int argc, char const *argv[])
{
    // note: the array must be non-negative
    //       and algorith is only efficient when the range of numbers is small
    vector<int> arr = {5, 4, 3, 2, 0};
    CountingSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";
    return 0;
}
