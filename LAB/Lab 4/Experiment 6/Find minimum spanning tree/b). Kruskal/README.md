Kruskal’s Algorithm
=
This program reads a graph from a .sif file (Simple Interaction Format), where each line defines an edge between two vertices along with its weight. It then applies Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) — a subset of edges that connects all vertices with the minimum possible total weight and without forming any cycles.

Algorithm Steps
-
1.Input Reading
-
-The program first prompts the user to enter the .sif filename.
-It opens and reads each line containing three values:

Source  Destination  Weight

Example:

A B 4
A C 3
B C 1
B D 2
C D 4


Each unique vertex is stored, and each edge is recorded with its weight.

2.Sorting Edges
-
-All edges are sorted in ascending order of their weights using the qsort() function.

3.Union-Find Structure
-
-A Disjoint Set Union (DSU) or Union-Find structure is used to detect cycles.
-Each vertex initially belongs to its own set.
-When an edge connects two vertices from different sets, they are merged.

4.Building MST
-
-The program iteratively picks the smallest edge that does not form a cycle.
-This process continues until (V - 1) edges are chosen (where V is the number of vertices).

5.Output
-
-Displays all edges included in the MST and calculates the Total Minimum Cost.
