#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//Product node for adjacency list 
struct Product {
    Product(string label, int val, int pageRank) : label(label), val(val), pageRank(pageRank) {};
    string label;
    int val, pageRank;
};

struct Edge {
    Edge(string label, Product dest, int weight) : label(label), dest(dest), weight(weight) {};
    string label;
    Product dest;
    int weight;
};



class Graph {
    public:
        Graph() = default;
        void addProduct(Product v);
        void addEdge(Product from, Product to, string label, int weight);
    private:
        unordered_map<Product, vector<Edge>> vertices;
};
