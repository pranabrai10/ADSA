Dijkstra’s Algorithm Implementation (C)
=
This program implements Dijkstra’s Algorithm — an algorithm for finding the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

It is one of the most widely used algorithms in network routing and graph-based optimizations.

A. Overview
-
-Algorithm Type: Greedy
-Time Complexity: O(V²) for this implementation (using adjacency matrix)
-Purpose: Finds the shortest path from a single source to all vertices
-Graph Representation: Adjacency Matrix

B. Constants and Definitions
-
#define V 10   // maximum number of vertices

The program supports up to 10 vertices.
You can modify this value to handle larger graphs.

C. Functions Used
-
1.minDistance()
-
Finds the vertex with the minimum distance value that has not yet been processed.

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


Purpose:
Selects the next vertex with the smallest known distance from the source that hasn’t been included in the shortest path tree (SPT).

2.printSolution()
-
Displays the shortest distance from the source vertex to all other vertices.

void printSolution(int dist[], int n, int src) {
    printf("Vertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t INF\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}

3.dijkstra()
-
Implements Dijkstra’s shortest path algorithm.

void dijkstra(int graph[V][V], int n, int src) {
    int dist[V];
    bool sptSet[V];

    // Initialization
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    // Main loop
    for (int count = 0; count < n-1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n, src);
}


Algorithm Steps:

1.Initialize all distances as infinite (INT_MAX) and source distance as 0.
2.Pick the vertex u with the minimum distance not yet processed.
3.Include u in the shortest path tree (sptSet).
4.Update the distance values of adjacent vertices of u.
5.Repeat until all vertices are processed.

D.Main Function
-
int main() {
    int n;
    printf("Enter number of vertices (<= %d): ", V);
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter source vertex (0 to %d): ", n-1);
    scanf("%d", &src);

    dijkstra(graph, n, src);
    return 0;
}

Explanation:
-
The user inputs:
The number of vertices n
The adjacency matrix representing the graph
The source vertex
The program then calls dijkstra() to compute and display the shortest paths.

E.Example Run
-
Enter number of vertices (<= 10): 5
Enter adjacency matrix (0 if no edge):
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0
Enter source vertex (0 to 4): 0


Output:

Vertex   Distance from Source (0)
0        0
1        8
2        9
3        5
4        7

F.Key Features
-
-Simple implementation using adjacency matrix
-Finds shortest path from a single source vertex
-Supports disconnected graphs (displays INF for unreachable vertices)
-Easy to understand and modify

G.Time and Space Complexity
-
Operation	Complexity
Time	O(V²)
Space	O(V)

(Can be optimized to O((V + E) log V) using priority queues and adjacency lists.)

H. Conclusion
-
This program efficiently demonstrates Dijkstra’s Algorithm for computing the shortest path in a weighted graph with non-negative weights.
It forms the basis for more advanced algorithms used in:
   -Network routing (e.g., OSPF, GPS pathfinding)
   -Transportation and logistics planning
   -Game AI pathfinding
