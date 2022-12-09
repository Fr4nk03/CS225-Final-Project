# CS225-Final-Project
Group member: Xinming Zhai, Jincheng Xu, Hanqi Mao, Shuqin Zhu

## Overview
Our project uses Amazon co-purchasing network obtained from http://snap.stanford.edu/data/amazon0302.html. If a product i is frequently co-purchased with product j, the graph contains a directed edge from i to j. The dataset is given as a txt file with two nodes of each edge seperated by '\t'. Our goal is to find strongly connected components and search for the most popular product with the greatest pageRank value.

Our presentation video: ///

All testing and running of our code can be done in main.cpp by make or cmake.

- - - -
## Tarjan's and pageRank algorithm Implementation
### Files: Graph.h/cpp
txt file is converted into the directed graph through /// ///. Then, Tarjan's algorithm can be used to find the strongly connected components. We combine the pageRank algorithm into the Graph Class because it needs to have access to the private members to calculate the pagerank value of each product.

IMPORTANT: The dataset we used is unweighted. ///
- - - -
##Pagerank : 

 Pagerank to evaluate popularity of the products.


##Tarjan's : 
  We first dfs assign index of each vertexes and then find strong connected component by dfs.
  
How to use our program?

