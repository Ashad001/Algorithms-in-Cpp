<<<<<<< HEAD
// Time Complexity: O(N!)
#include <iostream>
#include <vector>
using namespace std;

bool Check(vector<vector<int>> &arr, int row, int col)
{
    // Check column
    int i{0}, j{0};
    for (i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
        {
            return false;
        }
    }
    // Diagonals
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j] == 1)
=======
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
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
        {
            return false;
        }
    }
<<<<<<< HEAD
    for (i = row, j = col; i >= 0 && j < arr.size(); i--, j++)
    {
        if (arr[i][j] == 1)
=======
    for (i = row, j = col; i < grid.size() && j >= 0; i++, j--)
    {
        if (grid[i][j])
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
        {
            return false;
        }
    }
    return true;
}
<<<<<<< HEAD
int countQueens(vector<vector<int>> &arr, int row)
{
    if (row >= arr.size())
    {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (Check(arr, row, i) == 1)
        {
            arr[row][i] = 1;
            count += countQueens(arr, row + 1);
            arr[row][i] = 0;
        }
      
    }
    return count;
}

void totalNQueens(int n)
{
    vector<vector<int>> arr(n, vector<int>(n, 0));
    cout << countQueens(arr, 0);
=======

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
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
}

int main(int argc, char const *argv[])
{
<<<<<<< HEAD
    totalNQueens(5); // Checks how many queens can be placed in a 5 x 5 board

    return 0;
}


// Output: 10
=======
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
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
