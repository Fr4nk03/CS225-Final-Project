#include "tarjan.h"
#include "Graph.h"
#include "Pagerank.h"
#include <algorithm>
#include <iostream>
TEST_CASE("tarjan Public easy Test 1", "[weight=5]") {
   Product v1; Product v2; Product v3;
   Graph g;
   g.addProduct(v1); g.addProduct(v2); g.addProduct(v3);
   addEdge(v1, v2, 1);
   addEdge(v2, v3, 1);
   addEdge(v3, v1 , 1);
   REQUIRE( findSCCs(g)== {0,0,0});
}
TEST_CASE("tarjan Public Test 2", "[weight=5]") {
   
    Product v1; Product v2; Product v3;
   Product v4; Product v5; Product v6;
   Graph g;
   g.addProduct(v0);
   g.addProduct(v1); g.addProduct(v2); g.addProduct(v3);
   g.addProduct(v4); g.addProduct(v5); g.addProduct(v6);
   addEdge(v0, v1, 1);
   addEdge(v1, v4, 1);
   addEdge(v5, v4, 1);
   addEdge(v4, v5, 1);
   addEdge(v6, v0, 1);
   addEdge(v6, v2, 1);
   addEdge(v1, v2, 1);
   addEdge(v3, v2, 1);
   addEdge(v2, v3, 1);
   

    
    REQUIRE( findSCCs(g)== {0,0,2,2,4,4,0});
}
TEST_CASE("tarjan Public Test 3", "[weight=8]") {
   Product v1; Product v2; Product v3;
   Graph g;
    g.addProduct(v1); g.addProduct(v2); g.addProduct(v3);
   g.addProduct(v4); g.addProduct(v5); g.addProduct(v6);
    g.addProduct(v7); g.addProduct(v8);
   addEdge(v1, v2, 1);
   addEdge(v3, v1, 1);
   addEdge(v2, v3, 1);
    addEdge(v4, v2, 1);
   addEdge(v4, v3, 1);
   addEdge(v4, v5, 1);
   addEdge(v5, v4, 1);
   addEdge(v5, v6, 1);
   addEdge(v6, v3, 1);
   addEdge(v6, v7, 1);
   addEdge(v7, v6, 1);
   addEdge(v8, v5, 1);
   addEdge(v8, v8, 1);
   addEdge(v8, v7, 1);
    REQUIRE( findSCCs(g) == {1,1,1,4,4,6,6,8});

  

    
    
}