#include "tarjan.h"

using namespace std;

vector<int> findSCCs(map<Product, vector<Edge>> graph) {
    stack<Product> stack;
    vector<bool> visited(graph.size(), false);
    vector<int> lowLink(graph.size(), 0);

    for (unsigned int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(i, graph, lowLink, visited);
        }
    }

    return lowLink;
}

void dfs(int idx, map<Product, vector<Edge>> graph, vector<int> lowLink, vector<bool> visited) {
    
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
