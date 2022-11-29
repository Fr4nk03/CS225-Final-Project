#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

// Product node for adjacency list 
struct Product {
    Product(int label, int val, int pageRank) : label(label), pageRank(pageRank) {};
    int label;
    int pageRank;

    // Comparison function for unordered_map
    bool operator==(const Product& p) const {
        return label == p.label && pageRank == p.pageRank;
    }
};

// Hash function for unordered_map
class MyHashFunction {
    public:
        size_t operator()(const Product& p) const
        {
            return p.label;
        }
};

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
    private:
        unordered_map<Product, vector<Edge>, MyHashFunction> vertices;
};
