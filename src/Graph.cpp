#include "Graph.h"
#include "tarjan.h"
#include "utility.h"

Graph::Graph() {}

Graph::Graph() {}

void Graph::addProduct(Product v) {
    v.id = vertices.size();
    vertices[v] = vector<Edge>();
}

void Graph::addEdge(Product from, Product to, int label) {
    vertices[from].push_back(Edge(label, to));
}


void Graph::convertV2D(const string & filename, const int size) {
    V2D network = file_to_V2D(filename, size);
    for (size_t i = 0; i < network.size(); i++) {
        Product from(stoi(network[i][0])); Product to(stoi(network[i][1]));
        if (vertices.find(from) == vertices.end()) {
            addProduct(from);
        }
        if (vertices.find(to) == vertices.end()) {
            addProduct(to);
        }
        addEdge(from, to, from.label);
    }
}

map<Product, vector<Edge>> Graph::getGraph() {
    return vertices;
}

// map<int, vector<Product>> Graph::getSCCs() {
//     vector<int> lowLink = findSCCs(vertices);
//     map<int, vector<Product>> map;
//     auto it = vertices.begin();
//     for (unsigned int i = 0; i < lowLink.size(); i++) {
//         map[lowLink[i]].push_back(it->first);
//         it++;
//     }
//     return map;
// }
map<int, vector<Product>> Graph::getSCCs() {
    vector<int> lowLink = findSCCs(vertices);
    map<int, vector<Product>> map;
    auto it = vertices.begin();
    for (unsigned int i = 0; i < lowLink.size(); i++) {
        map[lowLink[i]].push_back(it->first);
        it++;
    }
    return map;
}
