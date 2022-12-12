Contributors: Jincheng Xu, Hanqi Mao, Shuqin Zhu, Xinming ZHai

Link for this **report**: https://github.com/Fr4nk03/CS225-Final-Project/blob/main/report.md

# Final Project - recommendations for co-purchasing products.
Link for the **repo**: https://github.com/Fr4nk03/CS225-Final-Project.git
Link for the **dataset**: http://snap.stanford.edu/data/amazon0302.html

## How does our project work? 
We use two algorithm to find the recommendations for customers -- Pagerank and Tarjan's. We first assign pagerank values to each product in the network and then find the strongly connected components (SCC). Finally, we can find the product with the max pagerank value in each SCC which should be the most popular product in that category.

- - - -
## Two Algorithms we used

### Pagerank Algorithm: 
The goal of Pagerank algorithm is to evaluate popularity of the products. The final result of running the pagerank algorithm on the whole dataset can be found in the **repo/Final_Result.txt**. We tested the result for each iteration using the graph provided in this link: https://courses.cs.washington.edu/courses/cse373/17au/project3/project3-3.html. The testing code is inside **main.cpp** and is ready to run whenever the user uncomments the block. For the whole dataset, most products have a pagerank value of 0.000001 because of the huge size of the network. It's interesting to find that the max pagerank value for the whole dataset is 0.000074 which is much bigger than other products'. We also included tests integrated with the Tarjan's algorithm and the product label with the maximum pagerank value inside the SCC is found.


### Tarjan's Algorithm: 
  We first dfs assign index of each vertexes and then find strong connected component by dfs.
  
How to use our program?
