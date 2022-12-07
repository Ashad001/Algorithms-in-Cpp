#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using edge = pair<int, int>;

class Graph
{
public:
    vector<pair<int, edge>> GRAPH;
    vector<pair<int, edge>> MST;
    int *parent;
    int V;
    Graph(int V)
    {
        parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            this->parent[i] = i;
        }
        GRAPH.clear();
        MST.clear();
    }
    void AddWeightedEdge(int u, int v, int wt)
    {
        GRAPH.push_back(make_pair(wt, edge(u, v)));
    }
    int Find_Set(int i)
    {
        return (i == parent[i]) ? i : Find_Set(parent[i]);
    }
    void Union_Set(int u, int v)
    {
        parent[u] = parent[v];
    }
    void Kruskal()
    {
        int i = 0, uRep, vRep;
        sort(GRAPH.begin(), GRAPH.end());
        for (int i = 0; i < GRAPH.size(); i++)
        {
            uRep = Find_Set(GRAPH[i].second.first);
            vRep = Find_Set(GRAPH[i].second.second);
            if (uRep != vRep)
            {
                MST.push_back(GRAPH[i]);
                Union_Set(uRep, vRep);
            }
        }
    }
    void Print()
    {
        cout << "Edge: \t Weight" << endl;
        for (int i = 0; i < MST.size(); i++)
        {
            cout << MST[i].second.first << " - " << MST[i].second.second << " : " << MST[i].first << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(6);
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 4);
    g.AddWeightedEdge(2, 0, 4);
    g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 4);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 3);
    g.Kruskal();
    g.Print();
    return 0;
    return 0;
}
