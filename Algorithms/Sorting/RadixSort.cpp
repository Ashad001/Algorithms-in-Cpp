#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int getMax(vector<int> &arr)
{

    int MAX = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > MAX)
        {
            MAX = arr[i];
        }
    }
    return MAX;
}
void Display(vector<int> &arr)
{
    for (auto num : arr)
    {
        cout << num << ", ";
    }
    cout << endl;
}
void CountSort(vector<int> &arr, int ex)
{
    vector<int> count(10, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        count[(arr[i] / ex) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    vector<int> output(arr.size(), 0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[--count[(arr[i] / ex) % 10]] = arr[i];
    }
    for (int i = 0; i < output.size(); i++)
    {
        arr[i] = output[i];
    }
}
void RadixSort(vector<int> &arr)
{
    int mx = getMax(arr);

    for (int e = 1; mx / e > 0; e *= 10)
    {
        CountSort(arr, e);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1003,1,3,322,3,4432,13,4};
    Display(arr);
    CountSort(arr, 1);
    Display(arr);
    RadixSort(arr);
    Display(arr);

    return 0;
}
