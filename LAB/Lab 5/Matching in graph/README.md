# Maximum Bipartite Matching – C Implementation (DFS / Hungarian Method)

This code implements the **Maximum Bipartite Matching (MBM)** algorithm in **C** using a **DFS-based augmenting path approach**, often associated with the **Hungarian Method** for bipartite matching.

The program finds the largest possible set of pairings between two disjoint sets **U** and **V** such that no two edges share a vertex.

---

## 📌 Features

### ✔ Core Capabilities
| Feature | Description |
|---------|-------------|
| **Bipartite Graph Input** | Reads adjacency matrix for U × V |
| **DFS-Based Augmenting Paths** | Recursively finds valid matches |
| **Reassignment Logic** | Re-matches vertices if needed |
| **Maximum Matching Output** | Prints number of matches and all U → V pairs |
| **Supports Any U, V Size** | Works for general bipartite graphs |

---

## 📌 Overview

A **bipartite graph** divides vertices into two disjoint sets **U** and **V** such that all edges go from U → V.

The goal of **Maximum Bipartite Matching** is to choose the largest number of edges where **no two edges share a vertex**.

This implementation uses:

- A DFS-based search to find **augmenting paths**
- A recursive matching function that:
  - Assigns free vertices in V
  - Reassigns already matched vertices when possible
- A visited array to prevent cycles during DFS

This approach guarantees a maximum matching for general bipartite graphs.

---

## 📌 How It Works

The program uses the following components:

### 🔹 Graph Representation
The bipartite graph is represented using an adjacency matrix:

```
graph[u][v] = 1  → edge exists between U[u] and V[v]  
graph[u][v] = 0  → no edge
```

### 🔹 Matching Array
`matchV[v]` stores the U-index matched to vertex V[v]:

- `matchV[v] = -1` → V[v] is free
- Otherwise → V[v] is matched to U[ matchV[v] ]

### 🔹 DFS Augmenting Path (bpm function)
The core of the algorithm:

1. Explore all V neighbors of U node `u`  
2. If V[v] is free → match it  
3. If V[v] is matched → try to reassign its partner via recursion  
4. Use `visited[v]` to avoid reconsidering nodes in the same DFS

### 🔹 Maximum Matching (maxBPM function)
Iterates through all U vertices:

- Runs `bpm(u)`  
- Increments the match count if a new match is found  

---

## 📌 Program Structure

```
graph[MAX][MAX]   → adjacency matrix
matchV[MAX]       → which U vertex each V is matched to
visited[MAX]      → visited flags for DFS
bpm(int u)        → tries to match vertex U[u]
maxBPM()          → computes and returns maximum matching
main()            → input, processing, and output
```

---

## 📌 Input Format

1. Number of vertices in sets U and V  
2. Adjacency matrix of size **U × V**

Where:
- `1` → edge exists  
- `0` → no edge  

### Example Input
```
Enter number of vertices in set U and V: 4 4
Enter adjacency matrix (U x V):
1 1 0 0
0 1 1 0
0 0 1 1
1 0 0 1
```

---

## 📌 Output

The program prints:

- Maximum number of matchings  
- The matching pairs in U → V format  

### Example Output
```
Maximum Matching possible = 4

Matched pairs (U -> V):
U3 -> V0
U0 -> V1
U1 -> V2
U2 -> V3
```

---

## 📌 Complexity

| Measure | Value |
|---------|--------|
| **Time Complexity** | O(U × V) |
| **Space Complexity** | O(U² + V) (adjacency matrix + helper arrays) |

The DFS-based Hungarian-style method is efficient for small and medium-size bipartite graphs.

---

## 📌 Advantages

- Simple and easy to understand  
- Works for all general bipartite graphs  
- Demonstrates fundamental concepts of augmenting paths  
- No advanced libraries required  
- Great for educational purposes  

---

## 📌 Limitations

- Uses adjacency matrix → O(U×V) space  
- DFS-based approach → not optimal for very large graphs  
- Does not implement Hopcroft–Karp (O(√V E))  
- No weighted matching (i.e., Hungarian algorithm for assignment problem)  


