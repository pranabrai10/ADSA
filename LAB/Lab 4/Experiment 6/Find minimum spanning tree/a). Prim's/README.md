# Prim’s Minimum Spanning Tree (MST) – C Implementation (SIF File Input)

This code implements **Prim’s Algorithm** to compute the **Minimum Spanning Tree (MST)** of a graph provided in a **SIF (Simple Interaction Format)** file.  
The program reads vertex names and weighted edges directly from the file, maps them internally, builds an adjacency matrix, and constructs the MST.

Prim’s algorithm finds a subset of edges that connects all vertices with **minimum total cost**, without forming cycles.

---

## 📌 A. Overview

Prim’s Algorithm is a **greedy algorithm** for computing the MST of a weighted, undirected graph.

### Key idea:
- Begin with any vertex  
- Repeatedly select the **minimum-weight edge** connecting a visited vertex to an unvisited vertex  
- Continue until all vertices are included  

This program extends Prim’s Algorithm by supporting **named vertices** (e.g., A, B, C), commonly used in biological and network interaction SIF files.

---

## 📌 B. Key Concepts

| Term | Description |
|------|-------------|
| **MST (Minimum Spanning Tree)** | A tree connecting all vertices with minimum total edge weight and no cycles |
| **Greedy Choice** | Selects the smallest available edge expanding the tree |
| **Adjacency Matrix** | Graph stored in a 2D matrix for easy weight lookup |

---

## 📌 C. Program Structure

### 🔹 1. Vertex Mapping
The SIF file may contain **named** vertices (A, B, C, ...).  
The program maintains a list of vertex names and assigns each a numerical index.

Function:

```c
int findVertexIndex(Vertex vertices[], int *count, char name[]);
```

- If a name already exists → return its index  
- If new → add it to the vertex list  

---

### 🔹 2. Reading the SIF File
Each line of the SIF file contains:

```
Source   Target   Weight
```

Example:

```
A B 4
A C 3
B C 2
B D 5
C D 7
```

The program:

- Reads each line  
- Maps vertex names to indices  
- Stores weights in an adjacency matrix  
- Treats graph as **undirected**  

---

### 🔹 3. Prim’s Algorithm Steps

1. Initialize all vertex keys to **infinity (INF)**  
2. Choose a starting vertex and set its key = 0  
3. Repeat:
   - Pick the unvisited vertex with the **minimum key** (`minKey()`)
   - Include it in the MST
   - Update keys of adjacent vertices if a lighter edge is found  
4. Continue until all vertices are included  

Helper function:
- `minKey()` → selects the next vertex with smallest connecting edge  

---

### 🔹 4. Output

After computing the MST, the program prints:

- Each selected edge in the MST  
- Total minimum cost of the spanning tree  

Example Output:

```
Minimum Spanning Tree using Prim's Algorithm:
A - C : 3
C - B : 2
B - D : 5
Total Minimum Cost = 10
```

---

## 📌 D. Time Complexity

Using an **adjacency matrix**, Prim’s Algorithm runs in:

\[
O(V^2)
\]

Suitable for moderate-size graphs.

---

## 📌 Program Flow

1. Ask user for input file name (e.g., *graph.sif*)  
2. Read SIF file and construct adjacency matrix  
3. Run Prim’s Algorithm  
4. Display MST edges and total cost  

---

## 📌 Example

### **Input File (graph.sif)**

```
A B 4
A C 3
B C 2
B D 5
C D 7
```

### **Output**

```
Minimum Spanning Tree using Prim's Algorithm:
A - C : 3
C - B : 2
B - D : 5
Total Minimum Cost = 10
```

### Explanation

- MST connects **A, B, C, D**  
- Edges chosen minimize total cost  
- Total = 3 + 2 + 5 = **10**  

---

## 📌 Key Features

- Reads graph directly from a `.sif` file  
- Supports named vertices (A, B, C, …)  
- Undirected, weighted graph representation  
- Efficient implementation using adjacency matrix  
- Output includes MST edges and total cost  

---

## 📌 Conclusion

This program demonstrates how **Prim’s Algorithm** can be applied to real-world SIF graph data to construct a **Minimum Spanning Tree**.  
Useful in:

- Network design  
- Circuit and PCB layout  
- Clustering algorithms  
- Graph analysis and modelling  

Wherever minimal-cost connectivity is required.


