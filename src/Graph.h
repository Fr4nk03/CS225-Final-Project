#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

// Product node for adjacency list 
struct Product {
    Product(int label) : label(label) {};
    Product(int label, int pageRank) : label(label), pageRank(pageRank) {};
    int label; //product id
    int pageRank;
    int id; //used in tarjan's

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
    Edge(int label, Product dest) : label(label), dest(dest) {};
    int label;
    Product dest;
};

class Graph {
    public:
        Graph();
        void addProduct(Product v);
        void addEdge(Product from, Product to, int label);
        void convertV2D(const string & filename, const int size);
        map<Product, vector<Edge>> getGraph();
        // map<int, vector<Product>> getSCCs();

    private:
        map<Product, vector<Edge>> vertices;
};
