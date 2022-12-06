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
    if (std::find(vertices[from].begin(), vertices[from].end(), Edge(from, to, label)) == vertices[from].end()) {
        vertices[from].push_back(Edge(from, to, label));
        return true;
    }
    // std::cout << "Edge from " << from.label << " to " << to.label << " already exists" << std::endl;
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

map<Product, vector<Edge>>& Graph::getGraph() {
    return vertices;
}

map<int, vector<Product>> Graph::getSCCs() {
    vector<int> lowLink = findSCCs(*this);
    map<int, vector<Product>> map;
    auto it = vertices.begin();
    for (unsigned int i = 0; i < lowLink.size(); i++) {
        map[lowLink[i]].push_back(it->first);
        it++;
    }
    return map;
}

void Graph::printSCCs() {
    for (auto i: getSCCs()) {
        cout << "[";
        for (auto j: i.second) {
            cout << j.label << " ";
        }
        cout << "]" << endl;
    }
}

void Graph::fileToGraph(string filename) {
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        string from;
        string to;
        for (unsigned int i = 0; i < line.size(); i++) {
            if (line[i] == '\t' || line[i] == ' ') {
                from = line.substr(0, i);
                to = line.substr(i + 1);
                break;
            }
        }
        // cout << from << "->" << to << endl;
        addProduct(from);
        addProduct(to);
        addEdge(Product(from), Product(to), 0);
    }
}
///This part is wrong we could not simply set id for nodes we need to use dfs to traverse it first
/*
void Graph::setID() {
    int num = 0;
    for (auto i: vertices) {
        setID(i.first, num);
        num++;
    }
    for (auto& i: vertices) {
        for (auto& j: i.second) {
            if (j.to.id == -1) {
                Product p = vertices.find(j.to)->first;
                j.to.id = p.id;
            }
        }
    }
}
*/
void Graph::setID(Product p, int id) {
    auto it = vertices.find(p);
    Product newP = it->first;
    vector<Edge> vec = it->second;
    newP.id = id;
    vertices.erase(it);
    vertices.insert(make_pair(newP, vec));
}

void Graph::print() {
    for (auto i: vertices) {
        cout << i.first.label << "'s id: " << i.first.id << ". Connected to: ";
        for (auto j: i.second) {
            cout << j.to.label << "(" << j.to.id << ")" << " ";
        }
        cout << endl;
    }
}
