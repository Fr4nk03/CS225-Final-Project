#include <iostream>
#include <typeinfo>
#include <fstream>
#include "utility.h"
#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    g.fileToGraph("/workspaces/cs225/release-f22/CS225-Final-Project/data/amazon-ungraph-middle.txt");
    auto map = g.getSCCs();
    for (auto it: map) {
        // for (Product p: it.second) {
        //     cout << p.label << " ";
        // }
        // cout << "are strongly connected." << endl;
        cout << it.first << endl;
    }
}
