Binary Search Tree (BST) Implementation in C

This program implements a Binary Search Tree (BST) in C language.

A BST is a node-based data structure where each node contains a key, and satisfies the following properties:
-The left subtree of a node contains only nodes with keys less than the node’s key.
-The right subtree of a node contains only nodes with keys greater than the node’s key.
-Both left and right subtrees are also binary search trees.

The program allows the user to:
-Insert a new node
-Delete an existing node
-Display the tree using Inorder, Preorder, and Postorder traversals

1️. Structure Definition
struct Node {
    int data;
    struct Node *left, *right;
};

Each node contains:
-data: the value stored in the node
-left: pointer to the left child
-right: pointer to the right child

2️. Node Creation
struct Node* createNode(int value)

-Allocates memory dynamically for a new node using malloc().
-Initializes data and sets both left and right to NULL.

3️. Insertion Operation
struct Node* insert(struct Node* root, int value)

-Inserts a new node into the tree following BST rules:
    -If value < root->data, insert in the left subtree.
    -If value > root->data, insert in the right subtree.
-Returns the root after insertion.

4️. Deletion Operation
struct Node* deleteNode(struct Node* root, int value)

-Deletes a node from the BST and maintains the BST property.
-There are three cases:
    -Node has no child (leaf node) → delete directly.
    -Node has one child → replace the node with its child.
    -Node has two children → replace the node’s value with its inorder successor (smallest value in the right subtree), and delete the successor node.

5️. Traversal Operations

There are three standard ways to traverse a BST:

a) Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root)

-Displays elements in ascending order.

b) Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root)

-Useful for creating a copy of the tree.

c) Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root)

-Useful for deleting the tree (as children are processed before the root).

6️. Menu-Driven Main Function

The main() function repeatedly displays a menu until the user chooses Exit (6).
It allows performing multiple insertions, deletions, and traversals dynamically.

Algorithmic Complexity
Operation	        Best Case	     Average Case    	Worst Case
Insertion	         O(log n)	       O(log n)	         O(n)
Deletion	         O(log n)	       O(log n)	         O(n)
Search	           O(log n)	       O(log n)	         O(n)
Traversal	           O(n)	          O(n)	           O(n)

The worst case occurs when the tree becomes skewed, resembling a linked list (when elements are inserted in sorted order).

Example Run
--- Binary Search Tree Operations ---
1. Insert
2. Delete
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
Enter your choice: 1
Enter value to insert: 40
Enter your choice: 1
Enter value to insert: 20
Enter your choice: 1
Enter value to insert: 60
Enter your choice: 3
Inorder Traversal: 20 40 60

Key Concepts
-Binary Search Tree (BST) ensures efficient searching and sorting.
-Recursive Functions simplify tree traversal and modification.
-Dynamic Memory Allocation allows flexible node creation during runtime.
