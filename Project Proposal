## Leading Question 
We want to investigate the categories of the products on Amazon by finding different connected components first. But what kind of product that represents this category? So, betweeness centrality is what we think of to measure the most popular product in a specific category, ie.the connected component. A back-up question can be formulated if we find the calculation for centrality to be too hard: we can compare the closeness of two products using dijkstra's algorithm because the shorter the path is, the closer these two products are.

For finding connected components, we can use the DFS traversal or Disjoint Set Union. For testing with a relatively small amount of data, we might use the DFS at first because it has O(V+E) runtime. But because the huge amount of data in the whole dataset, we will use disjoint set union instead to increase the efficiency because it only has a O(V) runtime and space. More details of between centrality will be mentioned in the "Algorithm" section below.

## Dataset Acquisition
Amazon Product Dataset: http://snap.stanford.edu/data/com-Amazon.html

## Data Format
A txt file stores the edges of an undirected graph connecting one node (a product) to another if they are bought together on Amazon. The weight for every edge is simply one because they are just connected. This txt file is extremely simple to read because it only has two columns representing the two product IDs. So, product ID should be a field of a node. 

Some key facts:
//Nodes: 334863
//Edges: 925872
//Diameter (longest shortest path): 44

Since the dataset is huge, we may use a subset which only include the first 1/50 or 1/100 of the edges. Because the source node is in an increasing order, this subset will not lose generality with respect to the final result.  

## Data Correction
Because the product ID can't be negative, if we find a negative id, we will simply ignore that pair of IDs which means that we will not add this edge into our graph.

## Data Storage
We will use adjacency list implementation by vector instead of linked list to store our graph. It saves space with O(V+E) storage. Moreover, adding a vertex (push_back) and finding all neighbors of a vertex (find the specific vector) takes optimal time.

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
