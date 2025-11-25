# Kruskal’s Algorithm – Minimum Spanning Tree (C Implementation)

This code implements **Kruskal’s Algorithm** to compute the **Minimum Spanning Tree (MST)** of a graph whose edges are read from a **SIF (Simple Interaction Format)** file.

Each line in the SIF file contains an edge in the format:

```
Source   Destination   Weight
```

Kruskal’s Algorithm finds a subset of edges that connects all vertices with **minimum total weight**, without forming cycles.

---

## 📌 Overview

Kruskal’s Algorithm is a **greedy** minimum spanning tree algorithm that:

1. Sorts all edges by weight  
2. Adds edges from smallest to largest  
3. Uses **Union-Find (Disjoint Set Union)** to avoid cycles  
4. Stops once the MST contains **V − 1** edges  

This implementation supports named vertices (A, B, C, ...), automatically mapping them internally.

---

## 📌 Algorithm Steps

### 🔹 1. Input Reading (SIF File)
- Program asks the user for the SIF filename  
- Each line contains:

```
<Source>  <Destination>  <Weight>
```

Example:

```
A B 4
A C 3
B C 1
B D 2
C D 4
```

The program:
- Stores each unique vertex  
- Records each edge with weight  
- Builds a list of all edges  

---

### 🔹 2. Sorting Edges
All edges are sorted in **ascending order of weight** using:

```c
qsort()
```

This ensures the algorithm always processes the smallest available edge first.

---

### 🔹 3. Union-Find (Disjoint Set Union)
Used to efficiently detect and avoid cycles.

- Each vertex starts in its own set  
- Two helper operations:
  - `find()` → finds the root/parent of a vertex  
  - `union()` → merges two disjoint sets  

An edge is included **only if** its endpoints are in different sets.

---

### 🔹 4. Building the MST
The algorithm iterates through sorted edges:

1. Pick the smallest edge  
2. If the edge connects **different sets**, include it in the MST  
3. Merge the sets  
4. Stop when the MST has **V−1 edges**

This guarantees the MST has minimum total cost.

---

### 🔹 5. Output
The program prints:

- All edges selected in the MST  
- The **Total Minimum Cost**  

---

## 📌 Example

### **Input (graph.sif)**

```
A B 4
A C 3
B C 1
B D 2
C D 4
```

### **Possible Output**

```
Edges in Minimum Spanning Tree (Kruskal's Algorithm):
B - C : 1
B - D : 2
A - C : 3

Total Minimum Cost = 6
```

The exact MST may vary if there are multiple valid MSTs with the same weight.

---

## 📌 Program Structure

| Component | Description |
|-----------|-------------|
| **Edge struct** | Stores (source, destination, weight) |
| **Vertex list** | Map vertex names to integer indices |
| **Union-Find (DSU)** | Detects cycles and connects components |
| **qsort()** | Sorts edges by weight |
| **Main routine** | Reads SIF file, runs Kruskal’s Algorithm, prints MST |

---

## 📌 Time Complexity

Let **E = number of edges, V = number of vertices**:

\[
O(E \log E) \quad \text{due to sorting}
\]

Union-Find operations are almost constant time with path compression.

---

## 📌 Key Features

- Reads graph directly from a `.sif` file  
- Supports **named vertices** (not just numeric indices)  
- Uses **Union-Find** for efficient cycle detection  
- Produces the complete Minimum Spanning Tree  
- Displays total MST cost  

---

## 📌 Conclusion

This project demonstrates the practical use of **Kruskal’s Algorithm** for computing a Minimum Spanning Tree using real graph data from SIF files.  
It is widely used in:

- Network design  
- Cluster analysis  
- Graph connectivity  
- Circuit and pipeline optimization  

Where minimum-cost connectivity is essential.

---
