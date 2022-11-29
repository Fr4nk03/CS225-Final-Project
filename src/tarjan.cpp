#include "tarjan.h"

using namespace std;

vector<int> findSCCs(Graph g) {
    unordered_map<Product, bool, MyHashFunction> visited;
    unordered_map<Product, int, MyHashFunction> lowLink;
    stack<Product> stack;
}
