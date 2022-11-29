#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

// Product node for adjacency list 
struct Product {
    Product(string label, int pageRank) : label(label), pageRank(pageRank) {};
    string label;
    int pageRank;
    int id;

    // Comparison function for map
    bool operator<(const Product& p) const {
        return id < p.id;
    }

    bool operator!=(const Product& p) const {
        return id != p.id;
    }
};

// // Hash function for unordered_map
// class MyHashFunction {
//     public:
//         size_t operator()(const Product& p) const {
//             return p.label;
//         }
// };

struct Edge {
    Edge(string label, Product dest, int weight) : label(label), dest(dest), weight(weight) {};
    string label;
    Product dest;
    int weight;
};

class Graph {
    public:
        Graph();
        void addProduct(Product v);
        void addEdge(Product from, Product to, string label, int weight);
        map<Product, vector<Edge>> getGraph();
        map<int, vector<Product>> getSCCs(vector<int> lowLink);

    private:
        map<Product, vector<Edge>> vertices;
};
