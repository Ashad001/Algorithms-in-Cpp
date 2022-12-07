#include <iostream>
#include <vector>
#include <string>
using namespace std;

// PRIMS ALGORITHM

#define N 5

void printMST(vector<int> parent, vector<vector<int>> graph)
{
    cout << "Edge \t Weight \n";
    for (int i = 1; i < N; i++)
    {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
    cout << endl;
}

int MinKey(vector<int> key, vector<bool> setVal)
{
    int minVal = INT_MAX;
    int minIndex = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (!setVal[i] && key[i] < minVal)
        {
            minVal = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void Prims(vector<vector<int>> graph, int source = 0)
{
    vector<int> parent(N);
    vector<int> key(N, INT_MAX);
    vector<bool> setVal(N, false);

    key[source] = 0;
    parent[source] = -1;

    for (int i = 0; i < N - 1; i++)
    {
        int u = MinKey(key, setVal);
        setVal[u] = true;
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] && !setVal[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    Prims(graph, 0);

    return 0;
}
