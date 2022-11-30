#include <iostream>
#include <typeinfo>
#include <fstream>
#include "utility.h"
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    g.fileToGraph("/workspaces/cs225/release-f22/CS225-Final-Project/data/amazon-ungraph-small.txt");
    vector<Edge> vec = g.getGraph()[Product("1")];
    for (Edge i: vec) {
        cout << i.dest.label << " ";
    }
    cout << endl;
}
