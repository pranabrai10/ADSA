Prim’s Minimum Spanning Tree (MST) from SIF File
=
This program reads a network graph from a SIF (Simple Interaction Format) file and constructs a Minimum Spanning Tree (MST) using Prim’s Algorithm.
It efficiently finds the subset of edges that connects all vertices in the graph with the minimum possible total weight.

A. Overview
-
Prim’s Algorithm is a greedy algorithm that finds the Minimum Spanning Tree (MST) for a weighted, undirected graph.
It starts from a source vertex and repeatedly adds the smallest edge that connects a vertex in the MST to a vertex outside the MST.

B. Key Concepts
-
Term	Description
MST (Minimum Spanning Tree)	A tree connecting all vertices with the smallest total edge weight and no cycles.
Greedy Choice	At each step, the smallest available edge connecting to an unvisited vertex is chosen.
Adjacency Matrix	The program stores the graph using a 2D matrix representation.

C. Program Structure
-
1.Vertex Mapping
-
The program supports named vertices (like A, B, C, etc.).
It maintains an array of vertex names and maps them to integer indices for processing.
int findVertexIndex(Vertex vertices[], int *count, char name[])
If a vertex name is new, it is added to the list.

2.Reading the SIF File
-
Each line of the file contains:
Source  Target  Weight

Example:

A B 4
A C 3
B C 2
B D 5
C D 7

This information is read and stored in an adjacency matrix.

3.Prim’s Algorithm Steps
-
1.Initialize all vertex keys as infinity (INF).
2.Start with the first vertex and set its key to 0.
3.At each step, pick the vertex with the minimum key that is not yet included in MST.
4.Update the key values of its adjacent vertices if a smaller weight edge is found.
5.Repeat until all vertices are included in the MST.

The helper function minKey() selects the next vertex with the minimum edge weight.

4.Output
-
Once the MST is built, the program prints:
-Each edge included in the MST
-The total cost of the MST

D. Time Complexity
-
For a graph with V vertices:
O(V²) using an adjacency matrix.

Program Flow
-
1.Prompt user for the input file name (e.g., graph.sif).
2.Read edges from the file and construct the adjacency matrix.
3.Run Prim’s Algorithm.
4.Display the MST edges and total minimum cost.

Example
-
Input File (graph.sif)
A B 4
A C 3
B C 2
B D 5
C D 7

Output
-
Minimum Spanning Tree using Prim's Algorithm:
A - C : 3
C - B : 2
B - D : 5
Total Minimum Cost = 10

Explanation of Output
-
-The MST connects all four vertices (A, B, C, D).
-The chosen edges have the minimum total cost.
-The total weight = 3 + 2 + 5 = 10.

Key Features
-
-Reads graph directly from a .sif file.
-Supports vertex names (not just numbers).
-Constructs undirected weighted graphs.
-Implements Prim’s algorithm efficiently using adjacency matrix representation.
-Displays total MST cost.

Conclusion
-
This program demonstrates the application of Prim’s Algorithm for Minimum Spanning Tree construction using real-world SIF graph data.
It’s useful in network design, circuit layout, and clustering problems — wherever minimal connection cost is essential.
