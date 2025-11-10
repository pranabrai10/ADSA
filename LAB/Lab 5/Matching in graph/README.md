Maximum Bipartite Matching in C

This C program implements the Maximum Bipartite Matching (MBM) algorithm using a DFS-based approach (Hungarian Method). It finds the largest set of pairings between two disjoint sets of vertices in a bipartite graph such that no two edges share a vertex.

Overview
A bipartite graph is a graph whose vertices can be divided into two disjoint sets U and V, such that every edge connects a vertex from U to a vertex from V.
The maximum matching problem seeks the largest set of edges such that no two edges share a vertex.
This program uses a DFS-based recursive approach to find augmenting paths and efficiently compute the maximum matching.

How It Works

Represent the bipartite graph as an adjacency matrix (graph[u][v] = 1 if an edge exists).
Maintain an array matchV[v] to store the current matching of V vertices.
For each vertex in U:
Try to find a vertex in V to match with using the DFS-based function bpm(u).
If the desired V is already matched, recursively check if the current match can be reassigned.
Mark visited vertices during DFS to avoid cycles.
Continue this process for all vertices in U to achieve maximum matching.

The DFS recursion allows the algorithm to backtrack and reassign vertices to ensure the maximum number of matches, even if initial choices block future matches.

Program Structure

graph[MAX][MAX] — adjacency matrix of the bipartite graph
matchV[MAX] — stores which U vertex is matched to each V vertex (-1 if unmatched)
visited[MAX] — marks V vertices visited during DFS
bpm(int u) — DFS function to find a match for U[u]
maxBPM() — iterates over all U vertices and computes the maximum matching
main() — takes input for U and V sizes, adjacency matrix, and prints the result


Input Format

Number of vertices in sets U and V
Adjacency matrix of size nU x nV
Enter 1 if there is an edge between U[u] and V[v]
Enter 0 if no edge exists

Example Input:
Enter number of vertices in set U and V: 4 4
Enter adjacency matrix (U x V):
1 1 0 0
0 1 1 0
0 0 1 1
1 0 0 1


Output
The program outputs:
Maximum number of matches
The matching pairs (U → V)

Example Output:
Maximum Matching possible = 4

Matched pairs (U -> V):
U3 -> V0
U0 -> V1
U1 -> V2
U2 -> V3

Complexity

Time Complexity: O(U × V) — each U vertex may traverse all V vertices in DFS
Space Complexity: O(V + U²) — adjacency matrix + arrays for matching and visited
