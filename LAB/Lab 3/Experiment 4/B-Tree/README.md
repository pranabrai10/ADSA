# B-Tree Implementation in C

This code implements a **B-Tree**, a balanced multiway search tree widely used in **databases**, **file systems**, and **indexing structures**.  
B-Trees are optimized for systems that read and write large blocks of data (e.g., disks).

For a B-Tree of **minimum degree T**:

- Each node stores **at most (2T − 1) keys**
- Each node has **at most (2T) children**
- All leaf nodes appear at the **same level**
- Keys in every node are stored in **sorted order**

---

## 📌 A. Structure of a B-Tree Node

```c
struct BTreeNode {
    int keys[2*T - 1];
    struct BTreeNode *children[2*T];
    int n;      // current number of keys
    int leaf;   // 1 = leaf node, 0 = internal node
};
```

Each node contains:

- `keys[]` → sorted keys  
- `children[]` → pointers to child nodes  
- `n` → number of active keys  
- `leaf` → flag indicating leaf / internal node  

---

## 📌 B. Creating a Node

```c
struct BTreeNode* createNode(int leaf);
```

This function:

- Allocates memory for a new node  
- Sets leaf status (`leaf = 1` or `0`)  
- Initializes key count (`n = 0`)  
- Sets all child pointers to `NULL`  

---

## 📌 C. Splitting a Child Node

```c
void splitChild(struct BTreeNode* parent, int i, struct BTreeNode* y);
```

When a child node `y` becomes **full** (`2T − 1` keys):

1. A new node `z` is created to hold the **right half** of `y`’s keys  
2. The **middle key** in `y` is moved up into the parent  
3. Parent’s child pointers are adjusted  
4. The overfilled node is reduced to valid size  

This guarantees that **no node grows beyond its maximum allowed keys**.

---

## 📌 D. Insertion

```c
struct BTreeNode* insert(struct BTreeNode* root, int key);
```

Insertion steps:

1. If tree is empty → create root  
2. If root is full → split root and create a new root  
3. Use `insertNonFull()` to insert into a valid node  

---

## 📌 E. Insertion Into a Non-Full Node

```c
void insertNonFull(struct BTreeNode* node, int key);
```

- If node is **leaf** → shift keys and insert key in sorted order  
- If node is **internal** → find child to recurse into  
- Before descending, if child is full → split the child  

This ensures insertion **never enters a full node**.

---

## 📌 F. Deletion (Basic Version)

```c
void removeFromNode(struct BTreeNode* node, int key);
```

This simplified implementation supports only:

### 🔸 Deletion from leaf nodes
Steps:

1. If key exists in a leaf → remove it  
2. If key not found in a leaf → print message  
3. If key is in an internal node → program reports advanced deletion not implemented  

Full B-Tree deletion (merge/borrow operations) is complex, so this demo implements only the essential part.

---

## 📌 G. Printing the B-Tree

```c
void printBTree(struct BTreeNode* root, int level);
```

Prints:

- Current level (depth in tree)  
- All keys in each node  
- Recursively prints children  

This helps visualize the multi-level structure clearly.

---

## 📌 H. Main Program (Menu-Driven)

Users can:

1. Insert a key  
2. Delete a key (only if in leaf)  
3. Print B-Tree structure  
4. Exit  

Program runs continuously until “Exit” is chosen.

---

## 📌 I. Example Run

```
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
```

---

## 📌 J. Key Characteristics of B-Trees

| Property | Description |
|----------|-------------|
| **Balanced Tree** | All leaf nodes appear at same level |
| **Multiple Keys per Node** | Reduces height dramatically |
| **Efficient Search** | O(log n) search, insertion, deletion |
| **Ideal for Disk Storage** | Minimizes disk I/O operations |

---

## 📌 K. Conclusion

This program demonstrates the **core functionality** of a B-Tree:

- Balanced multiway search  
- Efficient insertion and simple deletion  
- Proper splitting of full nodes  
- Tree visualization for understanding structure  

B-Trees are fundamental to **databases, indexing engines, and file systems**, making this implementation an excellent educational foundation.
