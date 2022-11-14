## Leading Question 
Our dataset is a directed graph from Amazon. Each node is a product and the edge from i to j means that product j is always being co-purchased with product i. Our goal is to use the dataset to find the popularity of the products, categorize them, and find the most popular product in the group. In this way, it will be a general and easy search tool for people to find some recommendations for co-purchasing products. In order to categorize the products, we will first use PageRank algorithm to assign the popularity or importance of each item and then, use Tarjan's algorithm to find the strong connected components and finally find the most popular one in the category based on the pagerank value we've calculated previously. To help achieve the goal, we will use DFS as our traversal algorithm for our directed graph. 


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
We will use a 2d dynamic array list<int> to store the graph adjacency list. For each node, we have three fields: its index, pagerank value and the ranking in the whole graph.


## Algorithm 

The algorithms we would like to use are Pagerank to evaluate popularity of the products (nodes in the graph) and Tarjan's Algorithm to find strongly connected component to categorize the products and find the most popular one in the specific group.

### Algorithm 1: Pagerank Algorithm (assign the pagerank value to each node)
  
Basic idea: When the transition matrix reaches to its steady state, we now have the final pagerank value and then we assign it to each node. We will also update the ranking into the node field so that when working on finding the most popular item in a group, we only need to find the node with the least ranking.

Function input: 2d dynamic array list<int> 

Function output: void

Function efficiency: 
- Time Complexity: Each iteration requires one vector-matrix multiplication, which on average requires O(n^2) time complexity, where n is the size of the 2d adjacency list.
- Memory: Our target memory performance is O(|E|) where |E| denotes the total number of edges in the graph.
  
Reference:
https://www.youtube.com/watch?v=kIUtEsaHpJU (The brief overview of the combination of Pagerank with strongly connected component) 



### Algorithm 2: Tarjan's Algorithm

Basic idea: A strongly connected component is the portion of a directed graph in which there is a path from each vertex to another vertex, and Tarjan’s algorithm can find all SCC's in a graph with one DFS traversal.

Function input: 

Function output: 

Function efficiency: 

- Time Complexity: Since Tarjan's Algorithm only requires one DFS traversal over the graph to find all SCC's, it has an linear O(V+E) time complexity, where V represents the number of vertices in the directed graph, and E represents the number of edges in the directed grpah.

- Memory: The worst case space complexity of Tarjan's algorithm is O(|V|) where V is the number of vertices in the directed graph. This happens when the whole graph is one giant strongly connected component.

Reference:
https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/



## Timeline
For the first week, since the data is simple, we may first extract the subset of the whole dataset and hopefully by the end of that week, we will finish the most or all parts of the data processing and correction. 

Next, before the mid checkpoint, we should complete finding connected components and start to develop and design the implementation of our betweeness centrality calculation. During design, we should consider the difficulty of this algorithm and decide whether we can switch to our back-up plan as mentioned in the "Leading Question" part.

We will spend less than 2 weeks on final testing and debugging and figure out how we are going to present our project to other fellow students.
