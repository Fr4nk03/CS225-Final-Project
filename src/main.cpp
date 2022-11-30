#include <iostream>
#include <typeinfo>
#include <fstream>
#include "utility.h"
#include "Graph.h"
#include "tarjan.h"

using namespace std;

int main() {
    Graph g;
    g.fileToGraph("/workspaces/cs225/release-f22/CS225-Final-Project/data/test.txt");
    // cout << g.getGraph()[Product("19022")].size() << endl;
    // cout << g.getGraph().size() << endl;
    // for (auto i: g.getGraph()) {
    //     cout << i.first.id << endl;
    // }

    g.setID();

    // auto vec = findSCCs(g);
    // cout << vec.size() << endl;
    // for (int i: vec) {
    //     cout << i << endl;
    // }
    // bool boo = '	' == '\t';
    // cout << boo << true << endl;
}
