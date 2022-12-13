#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

class Graph
{
    vector<int> *vertex;
    int s;

public:
    Graph(int SIZE = 6)
    {
        this->s = SIZE;
        this->vertex = new vector<int>[SIZE];
    }
    void AddEdge(int u, int v)
    {
        if (u >= s || v >= s)
        {
            cout << "vertex index not defined!" << endl;
            return;
        }
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }
    void PrintGraph()
    {
        cout << " ---------  Graph  --------- " << endl;
        for (int i = 0; i < vertex->size(); i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < vertex[i].size(); j++)
            {
                cout << vertex[i][j] << " | ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void RemoveEdge(int u, int v)
    {
        for (int i = 0; i < vertex[u].size(); i++)
        {
            if (vertex[u][i] == v)
            {
                vertex[u].erase(vertex[u].begin() + i);
            }
        }
        for (int i = 0; i < vertex[v].size(); i++)
        {
            if (vertex[v][i] == u)
            {
                vertex[v].erase(vertex[v].begin() + i);
            }
        }
    }
    void BFS(int source)
    {
        vector<bool> visited(vertex->size(), false);
        queue<int> q;
        visited[source] = true;
        q.push(source);
        while (!q.empty())
        {
            source = q.front();
            q.pop();
            cout << source << " -> ";
            for (auto e : vertex[source])
            {
                if (visited[e] == false)
                {
                    visited[e] = true;
                    q.push(e);
                }
            }
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    Graph g(6);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(1, 4);
    g.AddEdge(1, 0);
    g.AddEdge(4, 5);
    g.AddEdge(5, 3);
    g.AddEdge(5, 1);
    g.AddEdge(5, 0);
    g.AddEdge(1, 1);
    g.BFS(0);

    return 0;
}
