SIF File Parser and Graph Representation
-
This program reads a Simple Interaction Format (SIF) file and constructs a graph representation of the network defined within it.
SIF is a standard format used to represent biological networks, social networks, or interaction graphs, where each line represents a relationship between nodes.

A. Overview
-
The program:
1.Reads data from a .sif file line by line.
2.Parses each line to extract the source node, interaction type, and target nodes.
3.Builds an adjacency list representation of the graph.
4.Displays the graph connections in a readable format.

B. What is a SIF File?
-
The SIF (Simple Interaction Format) represents pairwise relationships between entities (nodes).
Each line follows this structure:
source_node  interaction_type  target_node1  target_node2 ...

Example:
-
A pp B
A pp C
B pd D

This defines the following relationships:
  -A interacts with B and C via “pp” (protein-protein interaction)
  -B interacts with D via “pd” (protein–DNA interaction)

C. Data Structures Used
-
1.Adjacency List Representation
-
The graph is stored as an array of vertices, where each vertex maintains a linked list of its adjacent nodes.

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    char name[MAX_NAME];
    Node* head;
} Vertex;

Vertex stores the node’s name and a pointer to its adjacency list.
Node represents a connection to another vertex (edge).

2.Global Variables
-
Vertex graph[MAX_NODES];
int nodeCount = 0;

-graph[]: stores all vertices.
-nodeCount: tracks the total number of unique nodes.

D. Function Explanations
-
1. getIndex(char name)
    -Searches whether the given node name already exists in the graph.
   -If found, returns its index.
   -If not, adds a new vertex and initializes its adjacency list.

3. addEdge(int u, int v)

Adds a directed edge from vertex u to vertex v by inserting a new node in the adjacency list.

3. parseLine(char line)
-Reads a line from the SIF file.
-Extracts:
   -Source node
   -Interaction type (ignored for adjacency creation)
   -Target nodes
-Calls getIndex() and addEdge() to create graph connections.

4. printGraph()
Displays all vertices and their adjacency lists in the format:
Source -> Target1 Target2 ...

E. Program Flow
-
1.The program opens the file network.sif for reading.
2.Each valid (non-comment) line is parsed using the parseLine() function.
3.Nodes are added to the adjacency list as they are discovered.
4.Once the file is processed, the complete adjacency list is printed.

F. Input File Example (network.sif)
-
A pp B C
B pp D
C pp D
D pp E

G. Output Example
-
Graph Adjacency List (from SIF):
A -> C B
B -> D
C -> D
D -> E
E ->

H. Explanation of Output
-
-The adjacency list shows all vertices (A, B, C, D, E) and the nodes they are directly connected to.
-For instance, A -> C B means:
    -There are edges from A to C
    -And from A to B

I. Advantages
-
-Supports dynamic creation of nodes while reading the file.
-Uses linked lists for efficient adjacency representation.
-Can handle up to 100 nodes with unique names.
-Skips comment lines (those starting with #) and blank lines automatically.

J. Limitations
-
-Only supports directed graphs (edges are one-way: A → B).
-Interaction type (e.g., pp, pd) is read but not used for analysis.
-File name is fixed (network.sif); user input for file name is not supported.

K. Applications
-
This program is especially useful for:
-Bioinformatics: parsing protein–protein or gene interaction networks.
-Social networks: mapping influence or communication patterns.
-Graph visualization tools: preprocessing data before visualization (e.g., Cytoscape).

L. Conclusion
-
This C program provides a clear and efficient way to:
-Parse SIF-format network data,
-Construct a graph using adjacency lists, and
-Display its structure in a readable format.

It serves as a foundation for advanced graph-based applications like network analysis, pathfinding, or visualization tools.
