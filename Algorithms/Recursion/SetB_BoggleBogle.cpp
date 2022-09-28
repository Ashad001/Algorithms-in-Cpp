#include <iostream>
#include <vector>
#include <string>
using namespace std;


#define N 10

int isFound(vector<string> &arr, string search, int row, int col)
{
    int i = 0, j = 0;
    bool check = false;
    int score = 0;
    for (i = col; i < N; i++)
    {
        if (arr[row][i] == search[j])
        {
            j++;
            check = true;
        }
        else
        {
            break;
        }
        if (!check)
        {
            // score = 0;
            j = 0;
        }
        if (j == search.size() - 1)
        {
            score += 1000;
            break;
        }
    }
    i = 0, j = 0;
    check = false;
    for (i = row; i < N ; i++)
    {
        if (arr[i][col] == search[j])
        {
            j++;
            check = true;
        }
        else
        {
            break;
        }
        if (j == search.size())
        {
            score += 1000;
            break;
        }
        if (!check)
        {
            j = 0;
            // if (score > 1000)
            // {
            //     score -= 1000;
            // }
            // else
            // {
            //     score = 0;
            // }
        }

    }
    // cout << score << endl;
    return score;
}

int Boggle(vector<string> &arr, string search, int row, int col)
{

    int score = 0;
    // if (isFound(arr, search, row, col))
    // {
    //     score = isFound(arr, search, row, col);
    // }

    if (row == N && col == N )
    {
        return 0;
    }

    score = isFound(arr, search, row , col);

    if (col == N - 1 && row < N - 1)
    {
        score += Boggle(arr, search, row + 1, 0);
        // return 0;
    }
    if (col < N - 1)
    {
        // cout << row << ", " << col << " -> " << score << endl;
        score += Boggle(arr, search, row, col + 1);
    }

    // score = isFound(arr, search, row, col);
    return score;
}


  
int main(int argc, char const *argv[])
{
    vector<string> Puzzle{
        "TCJOOCKAXL",
        "PROPERHYIE",
        "PROPERVPPP",
        "PMLTXIRHWR",
        "RLTHTFLROO",
        "LMGGREPORP",
        "XCUGFCMOEE",
        "BKTJAWJLRR",
        "MVDVFGCVMN",
        "PROEPROPER"};

    string search = "PROPER";

    cout << Boggle(Puzzle, search, 0,0) << endl;

    return 0;
}
