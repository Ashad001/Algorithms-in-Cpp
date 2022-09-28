#include <iostream>
#include <vector>
using namespace std;
bool check(vector<vector<int>> &grid, int row, int col)
{
    // Check row
    int i{0}, j{0};
    for (j = 0; j < col; j++)
    {
        if (grid[row][j])
            return false;
    }
    // Check Diagonals

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j])
        {
            return false;
        }
    }
    for (i = row, j = col; i < grid.size() && j >= 0; i++, j--)
    {
        if (grid[i][j])
        {
            return false;
        }
    }
    return true;
}

bool NQueen(vector<vector<int>> &grid, int col)
{
    if (col >= grid.size())
    {
        return true;
    }
    for (int i = 0; i < grid.size(); i++)
    {
        if (check(grid, i, col))
        {
            grid[i][col] = 1;
            if (NQueen(grid, col + 1))
            {
                return true;
            }
            grid[i][col] = 0; // Backtrack
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    bool val = NQueen(arr, 0);
    if (val == 1)
    {
        for (auto row : arr)
        {
            for (auto num : row)
            {
                cout << num << ", ";
            }
            cout << endl;
        }
    }

    return 0;
}
