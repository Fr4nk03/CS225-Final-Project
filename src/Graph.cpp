#include "Graph.h"
#include "tarjan.h"
#include "utility.h"
// #include <iterator>

Graph::Graph() {}

<<<<<<< HEAD
bool Graph::addProduct(Product v) {
    v.id = vertices.size();
    if (vertices.find(v) == vertices.end()) {
        vertices[v] = vector<Edge>();
        return true;
=======
void Graph::addProduct(Product v) {
    // v.id = vertices.size();
    // vertices[v] = vector<Edge>();
    if (check.find(v.label) != check.end()) {
        check.insert(pair<int, vector<Edge>>(v.label, vector<Edge>()));
>>>>>>> 4d2905cac319353873d990521a17c7b5ae377bc9
    }
    // std::cout << "Product already exist" << endl;
    return false;
}

bool Graph::addProduct(string str) {
    return addProduct(Product(str));
}

void Graph::addEdge(Product from, Product to, int label) {
<<<<<<< HEAD
    if (std::find(vertices[from].begin(), vertices[from].end(), Edge(label, to)) == vertices[from].end()) {
        vertices[from].push_back(Edge(label, to));
    }
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
=======
    // vertices[from].push_back(Edge(label, to));
    check[from.label].push_back(Edge(label, to));
}


void Graph::convertV2D(const string & filename, const int size) {
    V2D network = file_to_V2D(filename, size);
    for (size_t i = 0; i < network.size(); i++) {
        cout << "ln: " + to_string(i) << endl;
        Product from(stoi(network[i][0])); Product to(stoi(network[i][1]));
        cout << "REACH ln21 " + to_string(from.label) + " " + to_string(to.label) << endl;
        // cout << to_string(vertices.find(from) == vertices.end()) << endl;
        cout << to_string(from == to) << endl;
        if (check.find(from.label) == check.end()) {
            addProduct(from);
            cout << "ln24: " + to_string(from.label) << endl;
        }
        // if (vertices.find(to) == vertices.end()) {
        //     addProduct(to);
        // }
        cout << "REACH ln33 " + to_string(from.label) << endl;
        addEdge(from, to, from.label);
    }
}

map<int, vector<Edge>> Graph::getGraph() {
    // return vertices;
    return check;
>>>>>>> 4d2905cac319353873d990521a17c7b5ae377bc9
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
