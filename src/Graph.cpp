#include "Graph.h"

void Graph::addProduct(Product v) {
    v.id = vertices.size();
    vertices[v] = vector<Edge>();
}

void Graph::addEdge(Product from, Product to, string label, int weight) {
    vertices[from].push_back(Edge(label, to, weight));
}
