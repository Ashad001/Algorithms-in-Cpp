#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &arr)
{
    for(int i = 0; i < arr.size() - 1; i++)
    {
        for(int j = i + 1; j > 0; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else 
            {
                break;
            }

        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {5,4,3,21,1};
    InsertionSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";

    return 0;
}
