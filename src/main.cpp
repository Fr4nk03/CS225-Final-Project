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
    g.print();

    // See this example at https://www.youtube.com/watch?v=wUgWX0nc4NY
    g.printSCCs();
}
