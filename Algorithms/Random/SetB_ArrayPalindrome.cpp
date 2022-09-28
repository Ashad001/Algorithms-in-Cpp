#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Reverse(int num)
{
    int temp = 0;
    while (num != 0)
    {
        temp = temp * 10 + num % 10;
        num /= 10;
    }
    return temp;
}

bool Palindrome(vector<int> &arr, int row_S, int row_E)
{
    if (row_S >= row_E)
    {
        return true;
    }
    if (arr[row_S] == Reverse(arr[row_E]))
    {
        if (Palindrome(arr, row_S + 1, row_E - 1))
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    int size = 0;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << Palindrome(arr, 0, size - 1) << endl;
    return 0;
}

/*

4
134
21
12
431

*/