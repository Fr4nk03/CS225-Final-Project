# CS225-Final-Project
Group member: Xinming Zhai, Jincheng Xu, Hanqi Mao, Shuqin Zhu

## Overview
Our project uses Amazon co-purchasing network obtained from http://snap.stanford.edu/data/amazon0302.html. If a product i is frequently co-purchased with product j, the graph contains a directed edge from i to j. The dataset is given as a txt file with two nodes of each edge seperated by '\t'. Our goal is to find strongly connected components and search for the most popular product with the greatest pageRank value.

Our presentation video: ///
(The first 3 minutes is recorded by Xinming Zhai and Jincheng Xu. The next 2 minutes is recorded by Shuqin Zhu. The last part is done by Hanqi Mao.)

All testing and running of our code can be done in main.cpp by **make or cmake**. IMPORTANT: Users should cd to src folder and then **make** can be used.

- - - -
## Main Files
### File: Utility.h/cpp
This file is mainly used to convert txt file into our graph. The **fileToV2d function** is used to preprocess the data while cleaning. The **const int size** parameter is included because users is allowed to limit the size of the graph for more efficient testing.

### File: Graph.h/cpp
txt file is converted into the directed graph through **fileToGraph** function. //For better visualization of the data cleaning process, we include fileToV2D function inside Utility.hpp.// Then, Tarjan's algorithm can be used to find the strongly connected components. We combine the pageRank algorithm into the Graph Class because it needs to have access to the private members to calculate the pagerank value of each product.

IMPORTANT: The dataset we used is unweighted. ///
- - - -
## PageRank algorithm Implementation
### Pagerank: ComputePageRanks(double damping_factor, int num_iterations)

The **damping_factor** simulates an imaginary product seeker who is randomly clicking on the product pages will eventually stop clicking. The probability, at any step, that the person will continue is the damping factor damping_factor. Generally, we use damping_factor = 0.85.

The number of iterations (**num_iterations**) is needed in the parameter because it not only is helpful for our testing, but also allows us to know when the pagerank value of each product converges to a float.

To run pagerank algorithm, uncomment blocks in **main.cpp** and change to the path of your dataset. TESTS: [pageRank_small] [ungraph-mixed]

- - - - 
## Tarjan's algorithm Implementation
### Tarjan's: 

Tarjan's algorithm is composed of two functions: **findSCC** and **dfs**

- - - -
## How to use our program?**
**make && ./main** in ./src folder
REMEMBER to change the relative path of the dataset you want to use in **main.cpp**.
