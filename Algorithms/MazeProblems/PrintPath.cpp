#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void PrintPathDiagonal(string ans, int r, int c)
{
    if (r == 1 && c == 1)
    {
        cout << ans << endl;
        return;
    }
    if (c > 1 && r > 1)
    {
        PrintPathDiagonal(ans + 'M', r - 1, c - 1);
    }
    if (c > 1)
    {
        PrintPathDiagonal(ans + 'R', r, c - 1);
    }
    if (r > 1)
    {
        PrintPathDiagonal(ans + 'D', r - 1, c);
    }
}

void PrintPath(string ans, int r, int c)
{
    if (r == 1 && c == 1)
    {
        cout << ans << endl;
        // ans = "";
        return;
    }
    if (c > 1)
    {
        PrintPath(ans + 'R', r, c - 1);
    }
    if (r > 1)
    {
        PrintPath(ans + 'D', r - 1, c);
    }
}

void PrintPathWRestrictions(string ans, vector<vector<bool>> maze, int r, int c)
{
    if (r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }
    if (maze[r][c] == 1)
    {
        return;
    }
    if (c < maze.size() - 1 && !maze[r][c])
    {
        PrintPathWRestrictions(ans + 'R', maze, r, c + 1);
    }
    if (r < maze.size() - 1 && !maze[r][c])
    {
        PrintPathWRestrictions(ans + 'D', maze, r + 1, c);
    }
}

int main(int argc, char const *argv[])
{

    // PrintPathDiagonal("", 3, 3);
    vector<vector<bool>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 0}};
    PrintPathWRestrictions("", arr, 0, 0);

    return 0;
}
