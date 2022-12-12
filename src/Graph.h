//version 3: map with pair<Product, vector<Edge>>

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <ranges> //need to find in the vector of pairs
#include <algorithm>

using namespace std;

class Product {
    public: 
        Product(string label) : label(label) {
            id = -1;
        };
        Product(string label, double pageRank) : label(label), pageRank(pageRank) {
            id = -1;
        };
        Product(const Product& p)
        {
            label = p.label;
            pageRank = p.pageRank;
            id = p.id;
        }
        int id; //used in tarjan's

        string label; //product id used in PageRank
        double pageRank;
        double newPR = 0;
        double PageRank() const { return pageRank; }
        void set_PageRank(double PageRank) { pageRank = PageRank; }

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
    Edge(Product* from, Product* to) : from(from), to(to) {};
    mutable Product* from;
    mutable Product* to;

    bool operator!=(const Edge& e) const {
        return !(*this == e);
    }

    bool operator==(const Edge& e) const {
        return from == e.from && to == e.to;
    }
};

class Graph {
    public:
        Graph();
        void addPair(string str1, string str2);
        void fileToGraph(string filename);
        map<string, pair<Product*, vector<Edge>>>& getGraph();
        map<int, vector<Product*>> getSCCs();
        void printSCCs();
        void setID();
        void print();

        //pageRank
        void ComputePageRanks(double damping_factor, int num_iterations);
    
    private:
        map<string, pair<Product*, vector<Edge>>> vertices;
};