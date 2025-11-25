# Dijkstra’s Algorithm – C Implementation

This code implements **Dijkstra’s Algorithm**, a greedy algorithm used to compute the **shortest path** from a single source vertex to all other vertices in a **weighted graph with non-negative weights**.

Dijkstra’s Algorithm is widely used in:

- Network routing (OSPF)
- GPS navigation / pathfinding
- Graph optimization problems
- AI navigation systems

This implementation uses an **adjacency matrix**, making it simple and beginner-friendly.

---

## 📌 A. Overview

- **Algorithm Type:** Greedy  
- **Purpose:** Single-source shortest path  
- **Graph Representation:** Adjacency matrix  
- **Time Complexity:**  
  ```
  O(V²)   // due to matrix representation and linear min search
  ```

- **Space Complexity:**  
  ```
  O(V)
  ```

The program supports up to **10 vertices**, configurable via:

```c
#define V 10
```

---

## 📌 B. Core Functions

### 🔹 1. `minDistance()`

```c
int minDistance(int dist[], bool sptSet[], int n);
```

Finds the vertex with the **minimum distance value** that is not yet processed.

Used to select the next node to include in the **Shortest Path Tree (SPT)**.

---

### 🔹 2. `printSolution()`

```c
void printSolution(int dist[], int n, int src);
```

Prints the shortest distance from the source vertex to all other vertices.

If the vertex is unreachable:

- Prints `INF`

---

### 🔹 3. `dijkstra()`

```c
void dijkstra(int graph[V][V], int n, int src);
```

Main implementation of Dijkstra’s Algorithm.

#### Algorithm Steps

1. Initialize all distances as `INT_MAX` (infinity)  
2. Set source vertex distance to `0`  
3. Repeat for (V – 1) iterations:
   - Select the vertex with minimum distance  
   - Mark it as processed  
   - Update distances of its adjacent vertices  
4. Print final shortest path results  

This version handles:

- Weighted graphs  
- Unreachable nodes  
- Graphs with up to 10 vertices  

---

## 📌 C. Main Function

The user provides:

1. Number of vertices  
2. Adjacency matrix  
3. Source vertex  

Then the program calls:

```c
dijkstra(graph, n, src);
```

Example of adjacency input:

- `0` means **no edge**
- Any positive value represents an **edge weight**

---

## 📌 D. Example Run

### **Input**
```
Enter number of vertices (<= 10): 5
Enter adjacency matrix (0 if no edge):
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0
Enter source vertex (0 to 4): 0
```

### **Output**
```
Vertex   Distance from Source (0)
0        0
1        8
2        9
3        5
4        7
```

---

## 📌 E. Key Features

✔ Simple adjacency-matrix implementation  
✔ Supports disconnected graphs (`INF` for unreachable nodes)  
✔ Easy to modify and extend  
✔ Pure C implementation — no external libraries  
✔ Suitable for teaching and demonstration  

---

## 📌 F. Time & Space Complexity

| Operation | Complexity |
|----------|-------------|
| **Time** | O(V²) |
| **Space** | O(V) |

*Note:*  
Can be optimized to  
```
O((V + E) log V)
```  
using priority queues (min-heaps) and adjacency lists.

---

## 📌 G. Conclusion

This program illustrates the core mechanics of **Dijkstra’s Algorithm**, one of the most important algorithms in graph theory.  
It forms the foundation for:

- Network routing protocols  
- Logistics and transportation systems  
- Pathfinding engines (GPS, games, robotics)

The implementation is simple yet complete, making it ideal for learning, labs, and academic assignments.
