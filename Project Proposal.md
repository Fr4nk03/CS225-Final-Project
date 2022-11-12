## Leading Question 
Our dataset is a directed graph from Amazon. Each node is a product and the edge from i to j means that product j is always being co-purchased with product i. Our goal is to use the dataset to find the most popular product and make a category for these products. In this way, it will be a general and easy search tool for people to find some recommendations. For categorizing the products, we will use Tarjan's algorithm to find the strong connected components. To help achieve the goal, we will use DFS as our traversal algorithm for our directed graph. Then, in order to find the most popular item in this graph, we will use PageRank algorithm to assign the popularity or importance of each item. 

## Dataset Acquisition
Amazon Product Co-Purchasing Network Dataset: http://snap.stanford.edu/data/amazon0302.html

## Data Format
A txt file stores the edges of a directed graph from node i (a product) to node j if product i is frequently co-purchased with product j. The weight should be the result of 1 divides the sum of all edges leaving this node. This txt file is extremely simple to read because it only has two columns representing the two product IDs. So, product ID should be a field of a node. 

Some key facts:
//Nodes: 262111
//Edges: 1234877
//Diameter (longest shortest path): 32

Since the dataset is huge, we may use a subset which only include the first 1/50 or 1/100 of the edges. Because the source node is in an increasing order, this subset will not lose generality with respect to the final result.  

## Data Correction
Because the product ID can't be negative, if we find a negative id, we will simply ignore that pair of IDs which means that we will not add this edge into our graph.

## Data Storage
We will use adjacency list implemented by a 2d vector to store and update our transition matrix. The node has the coming edge will be the next element in the linked list of the node pointing to it.

## Algorithm 

The algorithm we would like to use is the combination of dijkstra's algorithm and betweeness centrality. To calculate the betweeness centrality of a node, we need to count all the shortest paths that passes this node so we need the help of dijkstra's algorithm.

Function input: connected component
Function output: update the maximum centrality calculated for each vertex and return the product ID with the maximum centrality. If we finish our goal earlier, we may think about making a visualization of the products from high to low of their centrality scores.
Function efficiency: For our undirected Graph, betweeness centrality is calculated base on the algorithm proposed by Brandes, 2001. This algorithm can calculate the score for each node in O(V+E). Since our leading question is about the most popular products in a specific connected component and these popular products can be similiar, the exact and accurate ranking of the centrality is not necessary. Hence, the approximation algorithms for betweenness centrality that consistently and efficiently discover the highest betweenness vertices may be more useful than computing the centrality score for every vertex exactly. We will try our best to reach our expected space efficiency which is less than O(V^2). 

Reference:
Ulrich Brandes (2001). A faster algorithm for betweenness
centrality. Journal of Mathematical Sociology. 25:163–177.

Comparing the speed and accuracy of approaches to betweenness centrality approximation:
https://computationalsocialnetworks.springeropen.com/articles/10.1186/s40649-019-0062-5

## Timeline
For the first week, since the data is simple, we may first extract the subset of the whole dataset and hopefully by the end of that week, we will finish the most or all parts of the data processing and correction. 

Next, before the mid checkpoint, we should complete finding connected components and start to develop and design the implementation of our betweeness centrality calculation. During design, we should consider the difficulty of this algorithm and decide whether we can switch to our back-up plan as mentioned in the "Leading Question" part.

We will spend less than 2 weeks on final testing and debugging and figure out how we are going to present our project to other fellow students.
