#include "Graph.h"

void Graph::addVertex(Vertex v) {
    vertices[v] = vector<Edge>();
}

void Graph::addEdge(Vertex from, Vertex to, string label, int weight) {
    vertices[from].push_back(Edge(label, to, weight));
}
