## Leading Question 
Our dataset is a directed graph from Amazon. Each node is a product and the edge from i to j means that product j is always being co-purchased with product i. Our goal is to use the dataset to find the popularity of the products, categorize them, and find the most popular product in the group. In this way, it will be a general and easy search tool for people to find some recommendations for co-purchasing products. In order to categorize the products, we will first use PageRank algorithm to assign the popularity or importance of each item and then delete the nodes which has a pagerank less than a specific number. Then, use Tarjan's algorithm to find the strong connected components and hence find the most popular one in the category based on the pagerank value we've calculated previously. To help achieve the goal, we will use DFS as our traversal algorithm for our directed graph. 


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
We will use adjacency list implemented by a 2d vector to store and update our transition matrix. 


## Algorithm 

The algorithms we would like to use are Pagerank to evaluate popularity of the products (nodes in the graph) and Tarjan's Algorithm to find strongly connected component to categorize the products and find the most popular one in the specific group.

### Algorithm 1: Pagerank Algorithm
Function input: an undirected graph

Function output: 

Function efficiency: 

Reference:
https://www.youtube.com/watch?v=kIUtEsaHpJU (The brief overview of the combination of Pagerank with strongly connected component) 



### Algorithm 2: Tarjan's Algorithm
Function input: 

Function output: 

Function efficiency: 

Reference:
https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/



## Timeline
For the first week, since the data is simple, we may first extract the subset of the whole dataset and hopefully by the end of that week, we will finish the most or all parts of the data processing and correction. 

Next, before the mid checkpoint, we should complete finding connected components and start to develop and design the implementation of our betweeness centrality calculation. During design, we should consider the difficulty of this algorithm and decide whether we can switch to our back-up plan as mentioned in the "Leading Question" part.

We will spend less than 2 weeks on final testing and debugging and figure out how we are going to present our project to other fellow students.
