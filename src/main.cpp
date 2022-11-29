#include <iostream>
#include <typeinfo>
#include <fstream>
#include "utility.h"
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    ifstream infile("/workspaces/cs225/release-f22/CS225-Final-Project/data/amazon-ungraph-small.txt");
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
        g.addProduct(from);
        g.addProduct(to);
        g.addEdge(Product(from), Product(to), 0);
    }
    vector<Edge> vec = g.getGraph()[Product("1")];
    for (Edge i: vec) {
        cout << i.dest.label << " ";
    }
    cout << endl;
}
