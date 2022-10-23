#include <iostream>
#include <vector>
using namespace std;

void Display(vector<int> &arr)
{
    for(auto num : arr)
    {
        cout << num << ", ";
    }
    cout << endl;
}

void InsertionSort(vector<int> &arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        Display(arr);
    }

}


int main(int argc, char const *argv[])
{
    vector<int> arr = {1,5,3,2,7,4};
    InsertionSort(arr);
    Display(arr);
    
    return 0;
}
