#include <iostream>
#include <vector>
using namespace std;


int LinearSearch(vector<int> arr, int target, int index)
{
    if(index == arr.size())
        return -1;
    if(arr[index] == target)
        return index;
    else 
        return LinearSearch(arr, target, index+1);
};



int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5,6};
    cout << LinearSearch(arr, 4, 0);

    return 0;
}
