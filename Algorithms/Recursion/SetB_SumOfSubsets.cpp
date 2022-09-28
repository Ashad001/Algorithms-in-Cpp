#include <iostream>
#include <vector>
using namespace std;

vector<int> subArray(vector<int> &arr, int index)
{

    vector<int> output;
    for (int i = index; i < arr.size(); i++)
    {
        output.push_back(arr[i]);
    }
    return output;
}
int SumOfSubsets(vector<int> arr)
{
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool Subset(vector<int> &arr, vector<int> &output,int i , int target)
{
    if(i == arr.size())
    {
        return false;
    }
    if(SumOfSubsets(output) == target)
    {
        return true;
    }
    if(i < arr.size())
    {
        output.push_back(arr[i]);
        arr = subArray(arr, 1);
        return 0 || Subset(arr, output, i + 1, target);
    }
    


}

int main(int argc, char const *argv[])
{
    int size = 0;
    cin >> size;
    vector<int> arr(size);
    vector<int> output(size, 0);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int search;
    cin >> search;

    cout << Subset(arr, output, 0, search);

    return 0;
}
/*

7
8
6
7
5
3
10
9
15

*/