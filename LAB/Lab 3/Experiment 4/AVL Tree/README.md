# AVL Tree – Self-Balancing Binary Search Tree (C Implementation)

This code implements an **AVL Tree**, a self-balancing Binary Search Tree (BST).  
In an AVL Tree, the **height difference** (balance factor) between the left and right subtrees of every node is **never more than 1**.

This balancing ensures that:

- Insertion → O(log n)  
- Deletion → O(log n)  
- Search → O(log n)  

making AVL trees highly efficient for ordered data operations.

---

## 📌 A. Node Structure

```c
struct Node {
    int key;
    struct Node *left, *right;
    int height;
};
```

Each node contains:

- `key` → stored value  
- `left`, `right` → child pointers  
- `height` → height of subtree rooted at the node  

---

## 📌 B. Utility Functions

### 🔹 1. `height()`
Returns height of a node (0 for NULL):

```c
int height(struct Node *node) {
    return (node == NULL) ? 0 : node->height;
}
```

### 🔹 2. `max()`
Returns the maximum of two integers — used to update node heights.

### 🔹 3. `getBalance()`
Computes balance factor:

```
Balance = height(left subtree) – height(right subtree)
```

Meaning:

- `> +1` → **Left heavy**
- `< −1` → **Right heavy**

This value determines whether rotations are needed.

---

## 📌 C. Rotations (Balancing Cases)

When a node’s balance exceeds ±1, the AVL tree performs rotations.

### 🔹 1. Right Rotation — **LL Case**
Used when the node becomes left-heavy due to insertion in left subtree.

### 🔹 2. Left Rotation — **RR Case**
Used when the node becomes right-heavy due to insertion in right subtree.

### 🔹 3. Left-Right Rotation — **LR Case**
Steps:
1. Left Rotation on the **left child**  
2. Right Rotation on the **node**

### 🔹 4. Right-Left Rotation — **RL Case**
Steps:
1. Right Rotation on the **right child**  
2. Left Rotation on the **node**

These rotations restore AVL balance and maintain O(log n) height.

---

## 📌 D. Insertion Operation

The `insert()` function:

1. Inserts the node like a normal BST  
2. Updates node heights  
3. Computes balance factor  
4. Performs necessary rotations  

### 🔹 Insertion Cases

| Case | Condition | Rotation |
|------|-----------|----------|
| **LL** | balance > 1 and key < left->key | Right Rotate |
| **RR** | balance < -1 and key > right->key | Left Rotate |
| **LR** | balance > 1 and key > left->key | Left Rotate (left child), then Right Rotate |
| **RL** | balance < -1 and key < right->key | Right Rotate (right child), then Left Rotate |

---

## 📌 E. Deletion Operation

The `deleteNode()` function:

1. Performs standard BST deletion  
   - No child → remove  
   - One child → replace by child  
   - Two children → replace with inorder successor  
2. Updates heights  
3. Checks balance factor  
4. Applies required rotation(s)

### 🔹 Deletion Cases

| Case | Condition | Rotation |
|------|-----------|----------|
| **LL** | balance > 1 and left subtree is balanced | Right Rotate |
| **LR** | balance > 1 and left subtree is right-heavy | Left Rotate → Right Rotate |
| **RR** | balance < -1 and right subtree is balanced | Left Rotate |
| **RL** | balance < -1 and right subtree is left-heavy | Right Rotate → Left Rotate |

---

## 📌 F. User Interaction (Menu-Driven)

The `main()` function provides:

- Option 1 → Insert value  
- Option 2 → Delete value  
- Option 3 → Exit  

The program continues until the user selects **Exit**.

---

## 📌 G. Key Features

✔ Self-balancing BST  
✔ Rotations automatically maintain balance  
✔ Efficient **O(log n)** operations  
✔ Fully menu-driven  
✔ Supports insertion and deletion  
✔ Maintains minimal height at all times  

---

## 📌 H. Sample Run

```
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
```

---

## 📌 I. Conclusion

This program demonstrates a complete AVL Tree with:

- Automatic height-balancing  
- Rotation-based corrections  
- Guaranteed O(log n) performance  

AVL Trees are widely used in:

- Databases  
- File systems  
- Search engines  
- Memory managers  

because they maintain a tightly controlled height at all times.


