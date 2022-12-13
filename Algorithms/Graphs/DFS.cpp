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
    Graph(int SIZE)
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
        for (int i = 0; i < this->s; i++)
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
    void DFS_recursive(int s) // INORDER TRAVERSAL
    {
        static vector<bool> vis(this->s, false);
        vis[s] = true;
        cout << s << " -> ";
        for (auto w : vertex[s])
        {
            if (!vis[w])
            {
                DFS_recursive(w);
            }
        }
    }

    void DFS_iterative(int s) // TOPOLOGY SORT
    {
        vector<bool> vis(this->s, false);
        stack<int> st;
        st.push(s);
        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            if (!vis[v])
            {
                cout << v << " -> ";
                vis[v] = true;
                for (auto w : vertex[v])
                {
                    if (!vis[w])
                    {
                        st.push(w);
                    }
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(12);
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(1, 7);
    g.AddEdge(1, 8);
    g.AddEdge(2, 3);
    g.AddEdge(2, 6);
    g.AddEdge(3, 4);
    g.AddEdge(3, 5);
    g.AddEdge(8, 9);
    g.AddEdge(9, 10);
    g.AddEdge(9, 11);
    g.PrintGraph();
    g.DFS_recursive(0);
    cout << endl;
    g.DFS_iterative(0);
    cout << endl;
    g.DFS_iterative(0);
    return 0;
}
