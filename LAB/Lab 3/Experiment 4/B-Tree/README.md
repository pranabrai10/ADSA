B-Tree Implementation in C
=
This program implements a B-Tree, a balanced multiway search tree widely used in databases and file systems to store large amounts of data efficiently.
A B-Tree of degree T is defined such that:
   -Each node can contain at most (2T - 1) keys.
   -Each node can have at most (2T) children.
   -All leaf nodes appear at the same level.
   -The keys in each node are stored in sorted order.

A. Structure of a B-Tree Node
-
struct BTreeNode {
    int keys[2*T - 1];
    struct BTreeNode *children[2*T];
    int n;      // Current number of keys
    int leaf;   // 1 if leaf node, 0 otherwise
};

Each node in the B-Tree contains:
     -keys[]: an array of sorted keys.
     -children[]: pointers to child nodes.
     -n: number of keys currently stored.
     -leaf: a flag (1 or 0) indicating whether the node is a leaf node.

B. Node Creation
-
struct BTreeNode* createNode(int leaf)
This function allocates memory for a new node, sets its leaf status, initializes key count n = 0, and sets all child pointers to NULL.

C. Splitting a Child Node
-
void splitChild(struct BTreeNode* parent, int i, struct BTreeNode* y)

When a child node y becomes full (contains 2*T - 1 keys), it is split into two nodes:
    -A new node z is created to hold the right half of y’s keys.
    -The middle key from y is moved up into the parent node.
    -The parent’s child pointers are adjusted to accommodate the new node.

This maintains the B-Tree’s properties by ensuring that no node exceeds its key limit.

D. Insertion
-
struct BTreeNode* insert(struct BTreeNode* root, int key)

Insertion occurs in the following steps:
    -If the root is NULL, create a new root node and insert the first key.
    -If the root is full, split it into two nodes and create a new root.
    -Use insertNonFull() to recursively find the correct leaf node for insertion.

E. Insertion into Non-Full Node
-
void insertNonFull(struct BTreeNode* node, int key)

-If the node is a leaf, the new key is inserted into the correct position (keeping the keys sorted).
-If the node is internal, the function finds the appropriate child and recursively inserts the key there.

If the child becomes full, splitChild() is called before continuing.

F. Deletion (Simplified)
-
void removeFromNode(struct BTreeNode* node, int key)

This basic version supports deletion only from leaf nodes:
1.If the key is present in a leaf node, it is simply removed.
2.If the key is not found and the current node is a leaf, a message is displayed saying the key does not exist.
3.If the key is in an internal node, a message indicates that complex internal deletion is not implemented.

G. Printing the B-Tree
-
void printBTree(struct BTreeNode* root, int level)

This recursive function prints the contents of the B-Tree level by level:
     -Displays all keys in the current node.
     -Recursively prints all child nodes, each time increasing the level number.
This helps visualize the hierarchical structure of the B-Tree.

H. Main Function
-
The main() function provides a menu-driven interface allowing users to:
1.Insert a key
2.Delete a key (if it exists in a leaf node)
3.Print the B-Tree structure
4.Exit the program

The program continues to execute until the user chooses to exit.

I. Example Run
-
B-Tree Operations:
1. Insert
2. Delete (only leaf keys)
3. Print B-Tree
4. Exit
Enter your choice: 1
Enter key to insert: 10
Enter your choice: 1
Enter key to insert: 20
Enter your choice: 1
Enter key to insert: 5
Enter your choice: 3
B-Tree structure:
Level 0: 10 
Level 1: 5 20 
Enter your choice: 2
Enter key to delete: 5
Deleted key 5
Enter your choice: 3
B-Tree structure:
Level 0: 10 
Level 1: 20 
Enter your choice: 4
Exiting...

J. Key Characteristics of B-Tree
-
Property	                                  Description
Balanced Tree	            Height grows logarithmically with number of elements.
Multiple Keys per Node	  Each node can hold several keys, reducing tree height.
Efficient Search	                  Searching takes O(log n) time.
Used in Databases	        Ideal for disk-based storage due to minimal disk reads.

K. Conclusion
-
This program demonstrates the fundamental working of a B-Tree data structure in C:
     -Supports insertion and simple deletion.
     -Ensures balance and efficient search through splitting.
     -Prints the tree structure for easy visualization.
