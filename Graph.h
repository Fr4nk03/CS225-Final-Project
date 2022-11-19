#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Edge {
    Edge(string label, Vertex dest, int weight) : label(label), dest(dest), weight(weight) {};
    string label;
    Vertex dest;
    int weight;
};

//node for adjacency list 
struct Vertex {
    Vertex(string label, int val, int pageRank) : label(label), val(val), pageRank(pageRank) {};
    string label;
    int val, pageRank;
};

class Graph {
    public:
        Graph() = default;
        void addVertex(Vertex v);
        void addEdge(Vertex from, Vertex to, string label, int weight);
    private:
        unordered_map<Vertex, vector<Edge>> vertices;
};
