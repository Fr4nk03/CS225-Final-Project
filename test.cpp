#include "tarjan.h"
#include "Graph.h"
#include "Pagerank.h"
#include <algorithm>
#include <iostream>
TEST_CASE("tarjan Public easy Test 1", "[weight=5]") {
   Product v1("v1"); Product v2("v2"); Product v3("v3");
   Graph g;
   g.addProduct(v1); g.addProduct(v2); g.addProduct(v3);
   g.addEdge(v1, v2, 1);
   g.addEdge(v2, v3, 1);
   g.addEdge(v3, v1 , 1);
   vector<int> v;
   v.push_back(0);
   v.push_back(0);
   v.push_back(0);
   REQUIRE( findSCCs(g)== v);
}
TEST_CASE("tarjan Public Test 2", "[weight=5]") {
   Product v0("v0");
    Product v1("v1"); Product v2("v2"); Product v3("v3");
   Product v4("v4"); Product v5("v5"); Product v6("v6");
   Graph g;
   g.addProduct(v0);
   g.addProduct(v1); g.addProduct(v2); g.addProduct(v3);
   g.addProduct(v4); g.addProduct(v5); g.addProduct(v6);

    g.addEdge(v0, v1, 1);
    g.addEdge(v1, v2, 1);
    g.addEdge(v2, v3, 1);
    g.addEdge(v3, v4, 1);
    g.addEdge(v4, v5, 1);
    g.addEdge(v5, v4, 1);
    g.addEdge(v3, v5, 1);
    g.addEdge(v3, v2, 1);
    g.addEdge(v1, v4, 1);
    g.addEdge(v1, v6, 1);
    g.addEdge(v6, v0, 1);
    g.addEdge(v6, v2, 1);


   vector<int> v;
   v.push_back(0);
   v.push_back(0);
   v.push_back(2);
   v.push_back(2);
   v.push_back(4);
   v.push_back(4);
   v.push_back(0);
    REQUIRE( findSCCs(g)== v);
}
TEST_CASE("tarjan Public Test 3", "[weight=8]") {
   Product v1("v1"); Product v2("v2"); Product v3("v3");
   Product v4("v4"); Product v5("v5"); Product v6("v6");
   Product v7("v7"); Product v8("v8");
   Graph g;
    g.addProduct(v1); g.addProduct(v2); g.addProduct(v3);
   g.addProduct(v4); g.addProduct(v5); g.addProduct(v6);
    g.addProduct(v7); g.addProduct(v8);
   g.addEdge(v1, v2, 1);
   g.addEdge(v3, v1, 1);
   g.addEdge(v2, v3, 1);
    g.addEdge(v4, v2, 1);
   g.addEdge(v4, v3, 1);
   g.addEdge(v4, v5, 1);
   g.addEdge(v5, v4, 1);
   g.addEdge(v5, v6, 1);
   g.addEdge(v6, v3, 1);
   g.addEdge(v6, v7, 1);
   g.addEdge(v7, v6, 1);
   g.addEdge(v8, v5, 1);
   g.addEdge(v8, v8, 1);
   g.addEdge(v8, v7, 1);
   vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(3);
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);
    v.push_back(7);
    REQUIRE( findSCCs(g) == v);

  

    
    
}
