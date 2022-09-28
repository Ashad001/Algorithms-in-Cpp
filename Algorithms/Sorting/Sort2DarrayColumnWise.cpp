#include <iostream>
#include <vector>
using namespace std;

#define N 5
bool isValid(int row, int col)
{
    if (row < 0 || row >= N - 1 || col < 0 || col >= N - 1)
    {
        return false;
    }
    return true;
}
void Display(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    };
}
void Solve(vector<vector<int>> &arr, vector<vector<int>> &ans, int row, int col, int steps)
{
    if (row == 2 && col == 2)
    {
        ans[row][col] = steps;
        Display(ans);
        cout << endl;
        return;
    }
    if (arr[row][col] == 0)
    {
        return;
    }

    --arr[row][col];
    ans[row][col] = steps;
    if (isValid(row, col) && arr[row][col] != 0)
    {
        Solve(arr, ans, row + 1, col, steps + 1);
        Solve(arr, ans, row, col + 1, steps + 1);
    }
    ans[row][col] = 0;
    ++arr[row][col];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {2, 3, 3, 3, 1},
        {0, 2, 1, 2, 1},
        {2, 2, 0, 2, 1},
        {1, 2, 1, 2, 1},
        {2, 2, 2, 3, 1},
    };
    vector<vector<int>> ans(N, vector<int>(N, 0));
    Solve(arr, ans, 0, 0, 1);

    return 0;
}
