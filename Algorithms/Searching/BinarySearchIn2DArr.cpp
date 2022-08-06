#include <iostream>
#include <vector>
using namespace std;

vector<int> Search(vector<vector<int>> arr, int target)
{
    int row = 0;
    int col = arr.size() - 1;
    while(row <= arr.size() - 1 && col >= 0)
    {
        if(arr[row][col] == target)
            return {row, col};
        else if(arr[row][col] < target)
            row++;
        else 
            col--;
    }
    return {-1,-1};
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {2,6,8,10},
        {3,7,9,12},
        {4,13,16,20},
        {40,41,54,56}
    };
    int target = 15;
    vector<int> ans = Search(arr, target);
    cout << ans[0] << " " << ans[1] << endl;
    
    return 0;
}
