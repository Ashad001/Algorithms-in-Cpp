#include <iostream>
#include <vector>
using namespace std;

int Check(vector<int> arr, int target)
{
    return arr.size();
}


int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int ans = Check(arr, 6);
    cout << ans;
    
    return 0;
}