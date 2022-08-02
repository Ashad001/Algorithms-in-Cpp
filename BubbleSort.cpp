#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool check = false;
        for (int j = 1; j < arr.size() - i; j++)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                check = true;
            }
            if(!check)
            {
                i = arr.size();
                break;
            }
        }
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {5,4,3,2,0};
    arr = BubbleSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ", ";

    return 0;
}
