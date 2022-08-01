#include <iostream>
#include <vector>
using namespace std;

int Floor(vector<vector<int>> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    if(target < arr[start][0])
        return arr[start][0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if(target < arr[mid][0])
            end = mid - 1;
        else if(target > arr[mid][0])
            start = mid + 1;
        else 
            return mid;
    }
    return end;
}
vector<int> Search(vector<vector<int>> arr, int target)
{
    int floor = Floor(arr, target);
    int start = 0;
    int end = arr[floor].size() - 1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(target > arr[floor][mid])
            start = mid + 1;
        else if(target < arr[floor][mid])
            end = mid - 1;
        else
            return {floor, mid};
    }
    return {-1 , -1};
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<int> ans = Search(arr, 9);
    cout << "[ " << ans[0] << " , " << ans[1] << " ]" << endl;

    
    return 0;
}
