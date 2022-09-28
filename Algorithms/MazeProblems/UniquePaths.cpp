#include <iostream>
#include <vector>
using namespace std;

int Paths(vector<vector<int>> &arr, int r, int c)
{
    if(r == arr.size() && c == arr[0].size())
    {
        return 1;
    }
    if(arr[r][c] == 1)
    {
        return 0;
    }
    
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

}

int main(int argc, char const *argv[])
{

    return 0;
}
