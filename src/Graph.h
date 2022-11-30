#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

struct Product {
    Product(string label) : label(label) {};
    Product(string label, int pageRank) : label(label), pageRank(pageRank) {};
    string label; //product id
    int pageRank;
    int id; //used in tarjan's

    // Comparison function for map
    bool operator<(const Product& p) const {
        return label < p.label;
    }

    bool operator==(const Product& p) const {
        return label == p.label;
    }

    bool operator!=(const Product& p) const {
        return !(*this == p);
    }
};

struct Edge {
    Edge(int label, Product dest) : label(label), dest(dest) {};
    int label;
    Product dest;

    bool operator!=(const Edge& e) const {
        return dest != e.dest;
    }

    bool operator==(const Edge& e) const {
        return dest == e.dest;
    }
};

class Graph {
    public:
        Graph();
        bool addProduct(Product v);
        bool addProduct(string str);
        void addEdge(Product from, Product to, int label);
        void convertV2D(const string & filename, const int size);
        void fileToGraph(string filename);
        map<Product, vector<Edge>> getGraph();
        // map<int, vector<Edge>> getGraph();
        map<int, vector<Product>> getSCCs();

    private:
        map<Product, vector<Edge>> vertices;
        map<int, vector<Edge>> check;
};
