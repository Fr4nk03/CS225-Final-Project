#include "tarjan.h"

using namespace std;

vector<int> findSCCs(map<Product, vector<Edge>> graph) {
    stack<Product> stack;
    vector<bool> visited(graph.size(), false);
    vector<bool> onStack(graph.size(), false);
    vector<int> lowLink(graph.size(), 0);

    auto it = graph.begin();
    for (unsigned int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(stack, it->first, graph, lowLink, visited, onStack);
        }
        it++;
    }

    return lowLink;
}

void dfs(stack<Product>& stack, Product p, map<Product, vector<Edge>> graph, vector<int>& lowLink, vector<bool>& visited, vector<bool> onStack) {
    stack.push(p);
    visited[p.id] = true;
    onStack[p.id] = true;
    lowLink[p.id] = p.id;

    for (Edge i: graph[p]) {
        Product dest = i.dest;
        if (!visited[dest.id]) {
            dfs(stack, dest, graph, lowLink, visited, onStack);
        }
        if (onStack[dest.id]) {
            lowLink[p.id] = min(lowLink[p.id], lowLink[dest.id]);
        }
    }

    if (p.id == lowLink[p.id]) {
        while (stack.top() != p) {
            onStack[stack.top().id] = false;
            lowLink[stack.top().id] = p.id;
            stack.pop();
        }
        onStack[p.id] = false;
        stack.pop();
    }
}




// /*private member

// two
// 1 number of nodes n
// 2 adjacency list

// id and sccCount to give name and count number

// id = []
// visited = []
// low = []

// onStack[false]
// stack an empty stack

// */

// /*
// std::vector<int> nodes
// std::vector<std::vector<int>> adjList
//  std:vector<int> low;
// std:vector<bool> visited;

// std:vector<bool> onStack;

// */


// void findScc(std::vector<int> nodes, std::vector<std::vector<int>> adjList) {
//     std:vector<bool> visited;
//     visited.resize(nodes.size, false);
//     std:vector<bool> onStack;
//     onStack.resize(nodes.size, false);
//     std:vector<int> low;
//     for (int i = 0; i < nodes.size(); i++) {
//         if (!visited[i]) {
//           dfs(i);
//         }
//     }
// }
// void dfs(int at) {
//       std::stack<int> stack;
//       std:vector<bool> onStack;
//       onStack.resize(nodes.size, false);
      

//       stack.push(at);
//       onStack[at] = true;

//       for (auto to : adjList) {
//         if (visited[to] == false) {
//             dfs(to);
//         }
//         if (onStack[to]) {
//             low[onStack] = min(low[at], low[to]);
//         }

//       }
//       ///check for start
//       if (nodes[at] == low[at]) {
//         for (node = stack.pop(); ;node = stack.pop()) {
//             onStack[node] = false;
//             low[node] = nodes[at];
//             if (node = at) {
//                 break;
//             }
//         }
//       }

// }
