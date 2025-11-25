# SIF File Parser and Graph Representation – C Implementation

This code implements a **Simple Interaction Format (SIF)** file parser and constructs a **graph representation** using an adjacency list.  
SIF files are widely used to represent **biological**, **social**, and **interaction** networks.

The program reads each line of a `.sif` file, extracts the nodes and interactions, builds the graph, and finally prints all adjacency lists.

---

## 📌 A. Overview

This program:

1. Reads a `.sif` file line by line  
2. Parses the **source node**, **interaction type**, and **target nodes**  
3. Builds a **directed graph** using adjacency lists  
4. Prints the graph structure in a readable format  

This is especially useful in **network biology**, **data visualization**, and **graph mining** tasks.

---

## 📌 B. What Is a SIF File?

A **SIF (Simple Interaction Format)** file describes relationships between nodes.

### General structure:
```
source_node   interaction_type   target1   target2   ...
```

### Example:
```
A pp B
A pp C
B pd D
```

Meaning:

- `A` interacts with `B` via **pp**  
- `A` interacts with `C` via **pp**  
- `B` interacts with `D` via **pd**  

(*Interaction types are read but not used to modify the graph structure.*)

---

## 📌 C. Data Structures

### 1️⃣ Node Structure (Linked List)
```c
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
```
Represents an edge to another vertex.

---

### 2️⃣ Vertex Structure
```c
typedef struct {
    char name[MAX_NAME];
    Node* head;
} Vertex;
```

Each vertex stores:

- Name of node  
- Pointer to its adjacency list  

---

### 3️⃣ Global Variables
```c
Vertex graph[MAX_NODES];
int nodeCount = 0;
```

- `graph[]` → stores all unique nodes  
- `nodeCount` → keeps track of how many distinct nodes have been added  

---

## 📌 D. Function Descriptions

### 🔹 1. `getIndex(char name[])`
- Checks if a node already exists  
- If not, creates a new vertex entry  
- Returns the index of the node  

Used to ensure all node names map to integer indices.

---

### 🔹 2. `addEdge(int u, int v)`
Adds a directed edge **u → v** by inserting a node into the linked list.

---

### 🔹 3. `parseLine(char line[])`
- Extracts:
  - Source node  
  - Interaction type  
  - One or more target nodes  
- Converts names to indices (via `getIndex()`)  
- Adds directed edges for each target  

---

### 🔹 4. `printGraph()`
Prints adjacency lists in the format:

```
A -> B C
B -> D
C -> D
...
```

---

## 📌 E. Program Flow

1. Open the file `network.sif`  
2. Read each line  
3. Skip empty lines or comments (`# ...`)  
4. Parse the content  
5. Build adjacency lists  
6. Print the full graph  

---

## 📌 F. Example Input (network.sif)

```
A pp B C
B pp D
C pp D
D pp E
```

---

## 📌 G. Example Output

```
Graph Adjacency List (from SIF):
A -> C B
B -> D
C -> D
D -> E
E ->
```

### Explanation:
- `A` connects to `B` and `C`
- `B` connects to `D`
- `D` connects to `E`
- `E` has no outgoing edges

---

## 📌 H. Advantages

✔ Automatically creates nodes as they are discovered  
✔ Efficient adjacency list representation  
✔ Supports up to 100+ unique node names  
✔ Ignores comments and blank lines  
✔ Simple and modular design  

---

## 📌 I. Limitations

✘ Directed graph only (A → B does not imply B → A)  
✘ Interaction types (pp, pd, etc.) are read but not processed  
✘ Input file name is fixed (`network.sif`)  
✘ No reverse lookup (target → source) unless added manually  

---

## 📌 J. Applications

This parser is useful in:

- **Bioinformatics:** protein–protein, gene–gene networks  
- **Social network analysis**  
- **Graph visualization (e.g., Cytoscape preprocessing)**  
- **Network mining / clustering tasks**  
- **Dependency graph construction**

---

## 📌 K. Conclusion

This C implementation provides a clean and efficient way to:

- Parse SIF network data  
- Build adjacency lists dynamically  
- Display the graph in a human-readable format  

It serves as a foundation for more advanced graph algorithms such as:

- BFS / DFS  
- Shortest paths (Dijkstra, Floyd–Warshall)  
- MST construction  
- Network centrality analysis  
- Graph visualization pipelines  
