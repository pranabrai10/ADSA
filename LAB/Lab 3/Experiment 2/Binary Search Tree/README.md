# Binary Search Tree (BST) – C Implementation

This code implements a **Binary Search Tree (BST)** in C.  
A BST is a node-based data structure where each node stores a key and satisfies:

- Left subtree nodes contain keys **less than** the root  
- Right subtree nodes contain keys **greater than** the root  
- Both subtrees must also be valid BSTs  

The program is fully **menu-driven**, allowing the user to:

- Insert nodes  
- Delete nodes  
- Perform Inorder, Preorder, and Postorder traversals  

---

## 📌 1. Structure Definition

```c
struct Node {
    int data;
    struct Node *left, *right;
};
```

Each node contains:

- `data` → value stored  
- `left` → pointer to left child  
- `right` → pointer to right child  

---

## 📌 2. Node Creation

```c
struct Node* createNode(int value);
```

This function:

- Allocates memory dynamically  
- Sets the node’s data  
- Initializes left and right child pointers to `NULL`  

---

## 📌 3. Insertion Operation

```c
struct Node* insert(struct Node* root, int value);
```

Insertion follows BST rules:

- If `value < root->data` → insert into left subtree  
- If `value > root->data` → insert into right subtree  
- Returns the updated root  

Duplicate values are typically ignored in standard BSTs.

---

## 📌 4. Deletion Operation

```c
struct Node* deleteNode(struct Node* root, int value);
```

Three deletion cases:

### **1. Node with no children (Leaf Node)**
- Delete directly

### **2. Node with one child**
- Replace node with its single child

### **3. Node with two children**
- Replace node with its **inorder successor**  
  (smallest value in right subtree)  
- Delete successor node recursively

BST property is preserved in all cases.

---

## 📌 5. Traversal Operations

### 🔹 **Inorder Traversal (Left → Root → Right)**  
```c
void inorder(struct Node* root);
```
Prints elements in **ascending order**.

---

### 🔹 **Preorder Traversal (Root → Left → Right)**  
```c
void preorder(struct Node* root);
```
Useful for:

- Copying the tree  
- Storing tree structure  

---

### 🔹 **Postorder Traversal (Left → Right → Root)**  
```c
void postorder(struct Node* root);
```
Useful for:

- Deleting/freeing the entire tree safely  

---

## 📌 6. Menu-Driven Main Function

The program repeatedly displays a menu:

```
--- Binary Search Tree Operations ---
1. Insert
2. Delete
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Exit
```

Users can dynamically insert, delete, and traverse the BST.

---

## 📌 Algorithmic Complexity

| Operation | Best Case | Average Case | Worst Case |
|----------|-----------|--------------|------------|
| **Insertion** | O(log n) | O(log n) | O(n) |
| **Deletion** | O(log n) | O(log n) | O(n) |
| **Search** | O(log n) | O(log n) | O(n) |
| **Traversal** | O(n) | O(n) | O(n) |

Worst-case happens when the BST becomes **skewed**, e.g., inserting sorted elements (like a linked list).

---

## 📌 Example Run

```
Enter your choice: 1
Enter value to insert: 40

Enter your choice: 1
Enter value to insert: 20

Enter your choice: 1
Enter value to insert: 60

Enter your choice: 3
Inorder Traversal: 20 40 60
```

---

## 📌 Key Concepts

- Binary Search Tree provides efficient search, insert, and delete operations  
- Recursion simplifies traversal and structural modifications  
- Dynamic allocation allows flexible tree creation during runtime  


