#pragma once

#include "Graph.h"

#include <stack>

std::vector<int> findSCCs(map<Product, vector<Edge>> graph);
void dfs(int idx, map<Product, vector<Edge>> graph, vector<int> lowLink, vector<bool> visited);
