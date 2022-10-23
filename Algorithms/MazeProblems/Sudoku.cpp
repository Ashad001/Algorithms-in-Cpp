#include <iostream>
<<<<<<< HEAD
#include <span>
#include <vector>
using namespace std;

void Display(_SPAN_<_SPAN_<int>> &arr)
=======
#include <vector>
using namespace std;

void Display(vector<vector<int>> &arr)
>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
{
    for (auto row : arr)
    {
        for (auto num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

<<<<<<< HEAD
// bool isSafe(vector<vector<int>> &board, int row, int col)
// {
//     for(int i = 0; i < board.size(); i++)
//     {
//         if(board[row][i] == )   
//     }

// }

// void Sudoku(vector<vector<int>> &board, int row, int col)
// {
//     if (row >= board.size() - 1 && col >= board[0].size() - 1)
//     {
//         Display(board);
//         return;
//     }
//     if (col == board[0].size() - 1)
//     {
//         Sudoku(board, row + 1, 0);
//     }
//     for (int i = 1; i <= 9; i++)
//     {
//         if (board[row][col] == 0)
//         {
//             if (isSafe(board, row, col) == 1)
//             {
//                 board[row][col] = i;
//                 Sudoku(board, row, col + 1);
//                 board[row][col] = 0;
//             }
//         }
//         else
//         {
//             Sudoku(board, row , col + 1);
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr =
    {
        {1,2,3,4},
        {5,6,7,8},
        {1,2,3,4}
    };

    Display(arr);
=======
bool isSafe(vector<vector<int>> &board, int row, int col)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(board[row][i] == )   
    }

}

void Sudoku(vector<vector<int>> &board, int row, int col)
{
    if (row >= board.size() - 1 && col >= board[0].size() - 1)
    {
        Display(board);
        return;
    }
    if (col == board[0].size() - 1)
    {
        Sudoku(board, row + 1, 0);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (board[row][col] == 0)
        {
            if (isSafe(board, row, col) == 1)
            {
                board[row][col] = i;
                Sudoku(board, row, col + 1);
                board[row][col] = 0;
            }
        }
        else
        {
            Sudoku(board, row , col + 1);
        }
    }
}

int main(int argc, char const *argv[])
{

>>>>>>> 4f492d9ad04ff8a3d4eac73ae67f5d6969be98f9
    return 0;
}
