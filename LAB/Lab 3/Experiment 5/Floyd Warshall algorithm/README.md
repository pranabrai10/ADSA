Floyd–Warshall Algorithm 
-
The Floyd–Warshall Algorithm is a fundamental algorithm in graph theory used to find the shortest path between every pair of vertices in a weighted graph. It is a dynamic programming approach that efficiently computes all-pairs shortest paths, even for dense graphs.

Concept
-
The algorithm works by considering each vertex as an intermediate node and checking whether including this vertex in the path between two other vertices results in a shorter distance.

It updates the shortest path distance between all pairs of vertices step by step by comparing direct and indirect routes through intermediate vertices.

Mathematically, it is based on the recurrence relation:

dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j])

Here,
   -dist[i][j] represents the shortest distance from vertex i to vertex j.
   -k represents the current intermediate vertex being considered.

Working Principle
-
1.The algorithm starts with an adjacency matrix of the graph, where:
   -graph[i][j] contains the weight of the edge between vertex i and vertex j.
   -If there is no edge, a large constant value (e.g., 99999) is used to represent infinity.

2.Initially, the distance matrix (dist) is the same as the adjacency matrix.

3.For each vertex k (as an intermediate vertex), the algorithm checks all pairs (i, j):
  -If the path i → k → j is shorter than the current path i → j, update dist[i][j].

4.After all iterations, the matrix dist contains the shortest distance between all vertex pairs.

Example
-
Consider the following adjacency matrix for a graph with 4 vertices:

From / To	0	1	2	3
0	        0	3	∞	7
1	        8	0	2	∞
2	        5	∞	0	1
3	        2	∞	∞	0

After applying the Floyd–Warshall algorithm, the resulting shortest path matrix is:

From / To	0	1	2	3
0	        0	3	5	6
1	        5	0	2	3
2	        3	6	0	1
3	        2	5	7	0

This shows the shortest distances between every pair of vertices.

Advantages
-
-Simple and elegant algorithm based on dynamic programming.
-Works for both directed and undirected graphs.
-Capable of detecting negative edge weights (but not negative cycles).

Limitations
-
-Inefficient for very large graphs because of its O(V³) time complexity.
-Cannot handle graphs that contain negative weight cycles.

Time and Space Complexity
-
-Time Complexity: O(V³), due to three nested loops.
-Space Complexity: O(V²), since it maintains a 2D distance matrix.

Applications
-
-Used in network routing to find optimal paths between all routers.
-Helps in social network analysis for computing closeness between users.
-Useful in geographical mapping systems and transport networks.

Conclusion
-
The Floyd–Warshall algorithm is an efficient and widely used method for finding the shortest paths between all pairs of nodes in a weighted graph.
Its simplicity and reliability make it a core algorithm in computer science, especially in graph theory, operations research, and network optimization.
