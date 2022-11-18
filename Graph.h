#include <iostream>

using namespace std;

//node for adjacency list 
struct node {
    int val, pageRank;
    node *next;
}