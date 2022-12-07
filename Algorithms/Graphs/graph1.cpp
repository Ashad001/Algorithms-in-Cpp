#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int DestinationID;
    int weight;
    Edge(int ID = 0, int w = 0)
    {
        this->DestinationID = ID;
        this->weight = w;
    }
};
class Vertex
{
public:
    int SourceID;
    string SourceName;
    list<Edge> edgeList;
    Vertex(int ID = 0, string name = "")
    {
        this->SourceID = ID;
        this->SourceName = name;
    }
};
class Graph
{
public:
    vector<Vertex> vertices;
};

int main(int argc, char const *argv[])
{

    return 0;
}
