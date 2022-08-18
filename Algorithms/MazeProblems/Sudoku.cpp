#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Display(vector<vector<int>> &arr)
{
    for(auto row : arr)
    {
        for(auto num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &arr, int row, int col, int num)
{
    // For Rows!
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[row][i] == num)
        {
            return false;
        }
    }
    // For Column
    for (auto row : arr)
    {
        if (row[col] == num)
        {
            return false;
        }
    }
    // For 3x3 Sub Square Matrix
    int sqt = int(sqrt(arr.size()));
    int newRow = row - row % sqt;   // Sqrt of a nxn matrix
    int newCol = col - col % sqt;
    for (int i = newRow; i < newRow + sqt; i++)
    { 
        for (int j = newCol; j < newCol + sqt; j++)
        {
            if (arr[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool Solver(vector<vector<int>> &arr)
{
    int row = -1;
    int col = -1;
    
    bool check = true;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[i][j] == 0)
            {
                row = i;
                col = j;
                check = false;
                break;
            }
        }
        if(!check)
        {
            break;
        }
    }
    if(check)
    {
        return true;
    }
    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(arr, row, col, num) == true)
        {
            arr[row][col] = num;
            if(Solver(arr) == true)
            {
                return true;
            }
            else
            {
                arr[row][col] = 0;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {8, 2, 3, 0, 0, 1, 5, 0, 0},
        {6, 7, 0, 5, 8, 0, 2, 1, 0},
        {7, 1, 0, 0, 0, 4, 0, 3, 0},
        {0, 4, 0, 7, 9, 0, 6, 0, 0},
        {5, 0, 0, 0, 0, 6, 7, 0, 0},
        {9, 0, 0, 8, 0, 2, 0, 0, 5},
        {0, 8, 0, 9, 0, 0, 0, 7, 6},
        {0, 0, 0, 0, 1, 0, 0, 8, 0}};

    if(Solver(arr))
    {
        Display(arr);
    }
    else
    {
        cout << "Sudoku cant be solved" << endl;
    }
    

    // cout << isSafe(arr, 8, 5, 5) << endl;

    return 0;
}
