#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <stdlib.h>
#include <stack>
#include <quadmath.h>
#include <queue>
using namespace std;

#define SIZE 8

class Graph
{
public:
    unordered_map<int, list<int>> vertex;
    void add_vertex(int u, int v)
    {
        if (u > SIZE || v > SIZE)
        {
            cout << "Size Overflow" << endl;
            return;
        }
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }
    void print_graph()
    {
        cout << " --------- GRAPH ---------" << endl;

        for (auto v : vertex)
        {
            cout << v.first << " -> ";
            for (auto n : v.second)
                cout << n << " | ";

            cout << endl;
        }
        cout << endl;
    }
    bool BFS(int source, vector<bool> &vis)
    {
        queue<int> q;
        if (vis[source])
        {
            return false;
        }
        q.push(vertex[source].front());
        while (!q.empty())
        {
            int e = q.front();
            q.pop();
            cout << e << " -> ";
            vis[e] = true;
            for (auto n : vertex[e])
            {
                if (!vis[n])
                {
                    vis[n] = true;
                    q.push(n);
                }
            }
        }
        return true;
    }
    bool DFS(int s, vector<bool> &vis)
    {
        if (vis[s])
        {
            return false;
        }
        vis[s] = true;
        cout << s << " -> ";
        for (auto n : vertex[s])
        {
            if (DFS(n, vis) && !vis[n])
            {
                vis[n] = true;
                return true;
            }
        }
        return true;
    }
    int countDFS(int s, vector<bool> &vis)
    {
        if (vis[s])
        {
            return 0;
        }
        vis[s] = true;
        // cout << s << " -> ";
        int count = 1;
        for (auto n : vertex[s])
        {
            count += countDFS(n, vis);
        }
        return count;
    }

    void countGraphs()
    {
        int count = 0;
        vector<bool> vis(SIZE, false);
        for (int i = 0; i <= SIZE; i++)
        {
            if (DFS(i, vis))
            {
                count++;
            }
            cout << endl;
        }
        cout << "Total Graphs Are: " << count << endl;
    }
    int LargestComponent()
    {
        int count = INT_MIN;
        vector<bool> vis(SIZE, false);

        for (int i = 0; i <= SIZE; i++)
        {
            int n = countDFS(i, vis);
            if (n > count)
            {
                count = n;
            }
        }
        return count;
    }
    int ShortestPath(int source, int destination)
    {
        vector<bool> vis(SIZE, false);
        queue<pair<int, int>> q; // edge, distance(edges)
        q.push(make_pair(source, 0));
        vis[source] = true;
        while (!q.empty())
        {
            int e = q.front().first;
            int d = q.front().second;
            q.pop();
            if (e == destination)
            {
                return d;
            }
            for (auto v : vertex[e])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(make_pair(v, d + 1));
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Graph g;
    g.add_vertex(1, 2);
    g.add_vertex(1, 3);
    g.add_vertex(2, 4);
    g.add_vertex(3, 4);
    g.add_vertex(4, 5);
    g.add_vertex(4, 6);
    g.add_vertex(5, 6);
    g.add_vertex(7, 8);
    g.add_vertex(8, 6);
    // g.add_vertex(7, 7);
    // g.countGraphs();
    // vector<bool> vis(SIZE, 0);
    // g.BFS(1, vis);
    // cout << g.countDFS(0, vis);
    // cout << g.LargestComponent();
    cout << g.ShortestPath(1, 8);

    return 0;
}
