#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &arr)
{
    int n = arr.size();
    vector<long long> temp(n + 1, 0);
    long long ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        temp[i + 1] = arr[i];
        
        temp[i + 1] = max(temp[i + 1], arr[i] + temp[i]);
        ans = max(ans, temp[i + 1]);
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    vector<int> arr;
    arr.push_back(-2);
    arr.push_back(1);
    arr.push_back(-3);
    arr.push_back(4);
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(-5);
    arr.push_back(4);

    cout << maxSubArray(arr) << endl;

    
    return 0;
}
