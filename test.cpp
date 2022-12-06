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
   
    REQUIRE( == );

  

    
    REQUIRE( == );
}
TEST_CASE("tarjan Public Test 3", "[weight=5]") {
   
    REQUIRE( == );

  

    
    REQUIRE( == );
}
