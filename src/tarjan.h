#pragma once

#include "Graph.h"

#include <stack>

std::vector<int> findSCCs(Graph& g);
void dfs(stack<Product>& stack, Product p, map<Product, vector<Edge>> graph, vector<int>& lowLink, vector<bool>& visited, vector<bool>& onStack);
