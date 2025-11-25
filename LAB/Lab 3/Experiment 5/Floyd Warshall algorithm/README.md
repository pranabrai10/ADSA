# Floyd–Warshall Algorithm – All-Pairs Shortest Path (C Implementation)

The **Floyd–Warshall Algorithm** is a classic **dynamic programming** method used to compute the **shortest paths between every pair of vertices** in a weighted graph.  
It works efficiently for **dense graphs** and supports **positive and negative edge weights** (but not negative cycles).

This implementation uses an adjacency matrix and produces the complete all-pairs shortest path matrix.

---

## 📌 Concept

The algorithm checks whether including an intermediate vertex **k** between vertices **i** and **j** produces a shorter path:

\[
\text{dist}[i][j] = \min(\text{dist}[i][j], \ \text{dist}[i][k] + \text{dist}[k][j])
\]

Where:

- `dist[i][j]` → shortest distance from vertex *i* to vertex *j*  
- `k` → current intermediate vertex being checked  

---

## 📌 Working Principle

### 1️⃣ Initialization

Start with the **adjacency matrix**, where:

- `graph[i][j]` = weight of edge i → j  
- `INF` (large number like `99999`) = no edge between i and j  
- `dist = graph` initially  

### 2️⃣ Iterative Updates

For each vertex **k** (as intermediate):

- Check **every pair (i, j)**  
- If going **i → k → j** is shorter than the current path **i → j**  
  → **update** the distance

### 3️⃣ Final Output

After all updates, `dist[i][j]` contains the shortest path between every pair of vertices.

---

## 📌 Example

### Input graph (4 vertices)

| From / To | 0 | 1 | 2 | 3 |
|-----------|---|---|---|---|
| **0** | 0 | 3 | ∞ | 7 |
| **1** | 8 | 0 | 2 | ∞ |
| **2** | 5 | ∞ | 0 | 1 |
| **3** | 2 | ∞ | ∞ | 0 |

### Result after Floyd–Warshall:

| From / To | 0 | 1 | 2 | 3 |
|-----------|---|---|---|---|
| **0** | 0 | 3 | 5 | 6 |
| **1** | 5 | 0 | 2 | 3 |
| **2** | 3 | 6 | 0 | 1 |
| **3** | 2 | 5 | 7 | 0 |

Shows the **shortest distances** between all vertex pairs.

---

## 📌 Advantages

✔ Simple, elegant, and easy to implement  
✔ Works for **directed** and **undirected** graphs  
✔ Supports **negative edge weights**  
✔ Finds **all-pairs shortest paths** in a single run  

---

## 📌 Limitations

✘ Slow for very large graphs (cubic time)  
✘ Cannot be used if the graph contains **negative weight cycles**  

---

## 📌 Time & Space Complexity

| Type | Complexity |
|------|------------|
| **Time** | O(V³) |
| **Space** | O(V²) |

---

## 📌 Applications

- Network routing (all-pairs optimal paths)  
- Social network analysis (closeness metrics)  
- Geographic mapping and logistics  
- Transitive closure / reachability analysis  
- Dynamic programming in optimization problems  

---

## 📌 Conclusion

The Floyd–Warshall Algorithm is a powerful, reliable method for computing **all-pairs shortest paths**.  
Its simplicity and versatility make it essential in:

- Graph theory  
- Operations research  
- Network optimization  
- Routing and navigation systems  

Even though it may not be the fastest for very large sparse graphs, its clarity and completeness continue to make it a foundational algorithm in computer science.

