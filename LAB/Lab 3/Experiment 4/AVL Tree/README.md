AVL Tree Implementation

This program implements an AVL Tree, which is a self-balancing Binary Search Tree (BST).
In an AVL Tree, the height difference (balance factor) between the left and right subtrees of any node is at most 1.

This property ensures that insertion and deletion operations always maintain a logarithmic time complexity — O(log n).

A. Node Structure
struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

Each node stores:
-key → the data value
-left and right → pointers to child nodes
-height → height of the subtree rooted at that node

B. Utility Functions

1. height()

Returns the height of a node (0 for NULL nodes).
int height(struct Node *node) {
    return (node == NULL) ? 0 : node->height;
}

2. max()
Helper function to find the maximum of two integers.

3. getBalance()
Calculates the balance factor of a node:
Balance Factor = height(left subtree) - height(right subtree)

If:
-balance > 1 → left heavy
-balance < -1 → right heavy

C. Rotations (Balancing the Tree)

When the balance factor exceeds ±1, the tree needs rotation to restore balance.

1. Right Rotation (LL Case)
Applied when a node is left-heavy due to an insertion in its left subtree.

2. Left Rotation (RR Case)
Applied when a node is right-heavy due to an insertion in its right subtree.

3. Left-Right Rotation (LR Case)
Applied when insertion happens in the right subtree of the left child.

Performed as:
Left Rotation on left child → Right Rotation on node

4. Right-Left Rotation (RL Case)
Applied when insertion happens in the left subtree of the right child.

Performed as:
Right Rotation on right child → Left Rotation on node

These rotations ensure that the tree remains balanced after every insertion or deletion.

D. Insertion

The insert() function:
1.Recursively inserts the new key in the correct position (as in a normal BST).
2.Updates the height of each ancestor node.
3.Calculates the balance factor of the node.
4.Performs appropriate rotation(s) if the balance factor becomes unbalanced (±2).

Balance Cases in Insertion:

Case	 v                    Condition	                                           Rotation
Left-Left (LL)	      balance > 1 && key < node->left->key	                    Right Rotate
Right-Right (RR)	    balance < -1 && key > node->right->key	                  Left Rotate
Left-Right (LR)	      balance > 1 && key > node->left->key	     Left Rotate (left child) → Right Rotate
Right-Left (RL)	      balance < -1 && key < node->right->key	   Right Rotate (right child) → Left Rotate

E. Deletion

The deleteNode() function:
1.Performs standard BST deletion (three cases):
      -Node with no children → simply remove it.
      -Node with one child → replace it with its child.
      -Node with two children → replace its key with its inorder successor (smallest value in right subtree).
2.Updates the height of nodes.
3.Checks balance factor and performs necessary rotations to restore balance.

Balance Cases in Deletion:

Case	                 Condition	                                              Rotation
Left-Left	           balance > 1 && getBalance(left) >= 0	                    Right Rotate
Left-Right	         balance > 1 && getBalance(left) < 0	     Left Rotate (left child) → Right Rotate
Right-Right	         balance < -1 && getBalance(right) <= 0	                  Left Rotate
Right-Left	         balance < -1 && getBalance(right) > 0	   Right Rotate (right child) → Left Rotate

F. User Interaction (Main Function)

The main() function provides a menu-driven interface:
    -Option 1 → Insert a new value
    -Option 2 → Delete a value
    -Option 3 → Exit the program
It continuously accepts user choices until the user selects “Exit”.

G. Key Features
  -Self-balancing BST (AVL property)
  -Automatic rotations after insertions or deletions
  -Efficient O(log n) search, insertion, and deletion
  -Menu-driven program for easy interaction

H. Sample Run
AVL Tree Operations:
1. Insert
2. Delete
3. Exit
Enter your choice: 1
Enter value to insert: 10
Enter your choice: 1
Enter value to insert: 20
Enter your choice: 1
Enter value to insert: 30
Enter your choice: 2
Enter value to delete: 20
Enter your choice: 3
Exiting...

I. Conclusion

This program efficiently implements an AVL Tree that:
    -Automatically maintains balance during insertions and deletions,
    -Ensures minimal height,
    -Guarantees logarithmic time complexity for major operations.

It is a foundational concept in Data Structures used in applications like databases, search engines, and memory management systems.
