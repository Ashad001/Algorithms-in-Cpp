#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void BackTracking(string ans, vector<vector<bool>> arr, int r, int c)
{
    if (r == arr.size() - 1 && c == arr[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }
    if (arr[r][c] == 1)
    {
        return;
    }
    if (r < arr.size() - 1 && !arr[r][c])
    {
        arr[r][c] = !arr[r][c];
        BackTracking(ans + 'D', arr, r + 1, c);
        arr[r][c] = !arr[r][c];
    }
    if (c < arr[0].size() - 1 && !arr[r][c])
    {
        arr[r][c] = !arr[r][c];
        BackTracking(ans + 'R', arr, r, c + 1);
        arr[r][c] = !arr[r][c];
    }
    if (r > 0 && !arr[r][c])
    {
        arr[r][c] = !arr[r][c];
        BackTracking(ans + 'U', arr, r - 1, c);
        arr[r][c] = !arr[r][c];
    }
    if (c > 0 && !arr[r][c])
    {
        arr[r][c] = !arr[r][c];
        BackTracking(ans + 'L', arr, r, c - 1);
        arr[r][c] = !arr[r][c];
    }
}

void PrintPaths(string ans, vector<vector<bool>> arr, int r, int c, vector<vector<int>> path, int step)
{
    if (r == arr.size() - 1 && c == arr[0].size() - 1)
    {
        path[r][c] = step;
        for (auto row : path)
        {
            for (auto col : row)
                cout << col << " , ";
            cout << endl;
        }
        cout << ans << endl;
        return;
    }
    if (arr[r][c])
    {
        return;
    }
    arr[r][c] = !arr[r][c];
    path[r][c] = step;
    if (r < arr.size() - 1)
    {
        PrintPaths(ans + 'D', arr, r + 1, c, path, step + 1);
    }
    if (c < arr[0].size() - 1)
    {
        PrintPaths(ans + 'R', arr, r, c + 1, path, step + 1);
    }
    if (r > 0)
    {
        PrintPaths(ans + 'U', arr, r - 1, c, path, step + 1);
    }
    if (c > 0)
    {
        PrintPaths(ans + 'L', arr, r, c - 1, path, step + 1);
    }
    arr[r][c] = !arr[r][c];
    path[r][c] = 0;
}


int main(int argc, char const *argv[])
{
    vector<vector<bool>> arr = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    vector<vector<int>> path = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    PrintPaths("", arr, 0, 0, path, 1);

    return 0;
}
