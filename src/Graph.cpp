#include "Graph.h"
#include "tarjan.h"
#include "utility.h"
// #include <iterator>

Graph::Graph() {}

bool Graph::addProduct(Product v) {
    if (vertices.find(v) == vertices.end()) {
        vertices[v] = vector<Edge>();
        return true;
    }
    // std::cout << "Product already exists" << std::endl;
    return false;
}

bool Graph::addProduct(string str) {
    return addProduct(Product(str));
}

bool Graph::addEdge(Product from, Product to, int label) {
    if (std::find(vertices[from].begin(), vertices[from].end(), Edge(label, to)) == vertices[from].end()) {
        vertices[from].push_back(Edge(label, to));
        return true;
    }
    std::cout << "Edge already exists" << std::endl;
    return false;
}

// void Graph::convertV2D(const string & filename, const int size) {
//     V2D network = file_to_V2D(filename, size);
//     for (size_t i = 0; i < network.size(); i++) {
//         cout << "ln: " + to_string(i) << endl;
//         Product from(stoi(network[i][0])); Product to(stoi(network[i][1]));
//         // cout << "REACH ln21 " + to_string(from.label) + " " + to_string(to.label) << endl;
//         // cout << to_string(vertices.find(from) == vertices.end()) << endl;
//         cout << to_string(from == to) << endl;
//         if (vertices.find(from) == vertices.end()) {
//             addProduct(from);
//             cout << "ln24: " + to_string(from.label) << endl;
//         }
//         // if (vertices.find(to) == vertices.end()) {
//         //     addProduct(to);
//         // }
//         cout << "REACH ln33 " + to_string(from.label) << endl;
//         addEdge(from, to, from.label);
//     }
// }

map<Product, vector<Edge>> Graph::getGraph() {
    return vertices;
}

map<int, vector<Product>> Graph::getSCCs() {
    vector<int> lowLink = findSCCs(*this);
    // cout << "executed" << endl;
    map<int, vector<Product>> map;
    auto it = vertices.begin();
    for (unsigned int i = 0; i < lowLink.size(); i++) {
        map[lowLink[i]].push_back(it->first);
        it++;
    }
    return map;
}

void Graph::fileToGraph(string filename) {
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        string from;
        string to;
        for (unsigned int i = 0; i < line.size(); i++) {
            if (line[i] == '\t') {
                from = line.substr(0, i);
                to = line.substr(i + 1);
                break;
            }
        }
        addProduct(from);
        addProduct(to);
        addEdge(Product(from), Product(to), 0);
    }
}

void Graph::setID(Product p, int id) {
    auto it = vertices.find(p);
    Product newP = it->first;
    vector<Edge> vec = it->second;
    newP.id = id;
    vertices.erase(it);
    vertices.insert(make_pair(newP, vec));
}