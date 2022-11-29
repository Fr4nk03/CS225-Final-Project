#include "Graph.h"
#include "tarjan.h"

Graph::Graph() {}

void Graph::addProduct(Product v) {
    v.id = vertices.size();
    vertices[v] = vector<Edge>();
}

void Graph::addEdge(Product from, Product to, string label, int weight) {
    vertices[from].push_back(Edge(label, to, weight));
}

map<Product, vector<Edge>> Graph::getGraph() {
    return vertices;
}

map<int, vector<Product>> Graph::getSCCs(vector<int> lowLink) {
    vector<int> lowLink = findSCCs(vertices);
    map<int, vector<Product>> map;
    auto it = vertices.begin();
    for (unsigned int i = 0; i < lowLink.size(); i++) {
        map[lowLink[i]].push_back(it->first);
        it++;
    }
}
