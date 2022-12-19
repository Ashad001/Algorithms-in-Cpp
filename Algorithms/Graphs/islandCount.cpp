#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int r, int c)
{
    if (grid[r][c] == 'W')
    {
        return false;
    }
    if (visited[r][c] || r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
    {
        return false;
    }
    visited[r][c] = true;

    if (r < grid.size() - 1)
        DFS(grid, visited, r + 1, c);
    if (r > 0)
        DFS(grid, visited, r - 1, c);
    if (c < grid[0].size() - 1)
        DFS(grid, visited, r, c + 1);
    if (c > 0)
        DFS(grid, visited, r, c - 1);

    return true;
}

int islandCount(std::vector<std::vector<char>> grid)
{
    // todo
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
    int count{0};
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (DFS(grid, visited, i, j) == true)
            {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<char>> grid{
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'L', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'L', 'L', 'W', 'W', 'W'}};
    cout << islandCount(grid);
    return 0;
}
