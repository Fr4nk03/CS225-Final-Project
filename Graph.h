#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    string label;
    Vertex dest;
    int weight;
};

//node for adjacency list 
struct Vertex {
    string label;
    int val, pageRank;
    vector<Edge> edges;
};

class Graph {
    public:
        void addVertex(Vertex v);
        void addEdge(Vertex from, Vertex to, string label, int weight);
    private:
        vector<Vertex> vertices;
};
