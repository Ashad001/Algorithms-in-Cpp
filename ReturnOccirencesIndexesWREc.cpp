#include <iostream>
#include <vector>
using namespace std;

vector<int> Occurences(vector<int> arr,int target, int index, vector<int> lst)
{
    if(index > arr.size())
    {
        return lst;
    }
    if(arr[index] == target)
    {
        lst.push_back(index);
    }
    return Occurences(arr, target, index+1, lst);
}



int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5,6,6,6};
    vector<int> lst;
    lst = Occurences(arr, 6, 0, lst);
    for(auto num : lst)
        cout << num << " ";
    
    return 0;
}

