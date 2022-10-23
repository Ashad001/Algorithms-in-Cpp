<<<<<<< HEAD
// Time Complexity : O(8^(n^2))
// There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from
=======
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        for (auto num : row)
        {
            if (num)
                cout << "K ";
            else
                cout << "x ";
        }
        cout << endl;
    }
    cout << endl;
}
bool IsValid(vector<vector<int>> &arr, int row, int col)
{
    if (row >= 0 && row < arr.size() && col >= 0 && col < arr.size())
    {
        return true;
    }
    return false;
}
bool IsSafe(vector<vector<int>> &arr, int row, int col)
{
    if (IsValid(arr, row - 2, col - 1) == 1)
    {
        if (arr[row - 2][col - 1] == 1)
            return false;
    }
    if (IsValid(arr, row - 2, col + 1) == 1)
    {
        if (arr[row - 2][col + 1] == 1)
            return false;
    }
    if (IsValid(arr, row + 1, col + 2) == 1)
    {
        if (arr[row + 1][col + 2] == 1)
            return false;
    }
    if (IsValid(arr, row - 1, col + 2) == 1)
    {
        if (arr[row - 1][col + 2] == 1)
            return false;
    }
    if (IsValid(arr, row + 2, col - 1) == 1)
    {
        if (arr[row + 2][col - 1] == 1)
            return false;
    }
    if (IsValid(arr, row + 2, col + 1) == 1)
    {
        if (arr[row + 2][col + 1] == 1)
            return false;
    }
    if (IsValid(arr, row + 1, col - 2) == 1)
    {
        if (arr[row + 1][col - 2] == 1)
            return false;
    }
    if (IsValid(arr, row - 1, col - 2) == 1)
    {
        if (arr[row - 1][col - 2] == 1)
            return false;
    }
    return true;
}

void Knight(vector<vector<int>> &board, int row, int col, int knights)
{
<<<<<<< HEAD
    if (knights == 0) // If all knights are places than show the board
=======
    if (knights == 0)
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
    {
        Display(board);
        return;
    }
    if (row == board.size() - 1 && col == board.size())
    {
<<<<<<< HEAD
        return; // out of bounds
    }
    if (col == board.size())
    {
        Knight(board, row + 1, 0, knights); // switching rows
=======
        return;
    }
    if (col == board.size())
    {
        Knight(board, row + 1, 0, knights);
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
        return;
    }
    if (IsSafe(board, row, col))
    {
<<<<<<< HEAD
        board[row][col] = true; // Placing the knight
        Knight(board, row, col + 1, knights - 1);
        board[row][col] = false; // Backtraking
=======
        board[row][col] = true;
        Knight(board, row, col + 1, knights - 1);
        board[row][col] = false;
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
    }
    Knight(board, row, col + 1, knights);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr =
        {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    // Display(arr);
    Knight(arr, 0, 0, 5);

    return 0;
}
