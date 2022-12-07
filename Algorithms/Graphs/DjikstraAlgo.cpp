#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define V 9

int GetMinDistance(vector<int> Dist, vector<bool> setVal)
{
    int minVal = INT_MAX, minIndex = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (!setVal[i] && Dist[i] < minVal)
        {
            minVal = Dist.at(i);
            minIndex = i;
        }
    }
    return minIndex;
}
void PrintSolution(vector<int> DIST)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << DIST[i] << endl;
    }
    cout << endl;
}
vector<int> Dijkstra(vector<vector<int>> grp, int src)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> setVal(V, false);
    dist[src] = 0; // Distance to Itself
    for (int i = 0; i < V; i++)
    {
        int e = GetMinDistance(dist, setVal);
        setVal[e] = true;
        for (int v = 0; v < V; v++)
        {
            if (!setVal[v] && grp[e][v] && dist[e] != INT_MAX && dist[e] + grp[e][v] < dist[v])
            {
                dist[v] = dist[e] + grp[e][v];
            }
        }
    }
    return dist;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    vector<int> ans = Dijkstra(graph, 0);
    PrintSolution(ans);

    return 0;
}
