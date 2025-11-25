# Splay Tree – C Implementation (Menu Driven)

This project implements a **Splay Tree** data structure in **C**, including all major operations such as:

- Insert  
- Search  
- Delete  
- Inorder Traversal  
- Preorder Traversal  

The implementation also includes all core internal mechanisms that define splay trees:

- Zig Rotation  
- Zig-Zig Rotation  
- Zig-Zag Rotation  
- Automatic Splaying After Each Operation  

Splay Trees automatically move accessed nodes to the **root**, improving performance for frequently accessed values.  
The program is fully **menu-driven**, allowing users to interactively test splaying behavior.

---

## 📌 Features

### ✔ User-Level Operations
| Operation | Description |
|----------|-------------|
| **Insert** | Insert a new key and splay it to the root |
| **Search** | Search a key and splay it to the root |
| **Delete** | Delete a key using splay-based merging |
| **Inorder Traversal** | Print keys in sorted order |
| **Preorder Traversal** | Display tree structure (root-first) |

---

## 📌 Internal Operations (Automatic)

These operations are **not directly called by the user**. They are triggered inside `insert()`, `search()`, and `delete()`:

- `splay(x)` → Moves accessed node `x` to the root  
- `leftRotate(x)` → Used in Zig, Zig-Zig, Zig-Zag  
- `rightRotate(x)` → Used in Zig, Zig-Zig, Zig-Zag  

These internal mechanisms ensure:

- **O(log n)** amortized Insert  
- **O(log n)** amortized Search  
- **O(log n)** amortized Delete  

---

## 📌 File Structure

```
SplayTree/
│
├── code.c      # Full implementation with menu
├── README.md         # Documentation (this file)
└── Input & Output
```

---

## 📌 Compilation

Use GCC:

```bash
gcc code.c -o code
```

---

## 📌 Running the Program

```bash
./code
```

---

## 📌 Menu Example

```
===== SPLAY TREE MENU =====
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Preorder Traversal
6. Exit
Your choice:
```

---

## 📌 How It Works Internally

### 🔹 Insertion
- Insert the node using standard BST logic  
- Then **splay** the inserted node to the root  

### 🔹 Search
- If the key exists → **splay it to the root**  
- If the key does not exist → splay the *last accessed node*  
  (keeps the tree adaptive)

### 🔹 Deletion
1. **Splay** the key to the root  
2. Remove the root  
3. Splay the **largest node in left subtree**  
4. Attach right subtree to the new root  

### 🔹 Rotations

| Rotation | Meaning |
|----------|---------|
| **Zig** | Node is a child of root → single rotation |
| **Zig-Zig** | Node and parent both left OR both right children → double rotation |
| **Zig-Zag** | Node and parent are misaligned (left-right or right-left) → double rotation |

These rotations keep the tree **self-adjusting**.

---

## 📌 Example Run

```
1
Enter value to insert: 50
Inserted and splayed.

1
Enter value to insert: 30
Inserted and splayed.

1
Enter value to insert: 40
Inserted and splayed.

2
Enter value to search: 30
Found 30 (now at root).

4
Inorder: 30 40 50
```

---

## 📌 Error Handling

The program handles incorrect operations gracefully:

### Example:
```
Enter value to delete: 200
Key not found — tree unchanged.
```

For searches:
- Missing key does **not** produce an error  
- Instead, the **closest accessed node is splayed**  

This is standard splay tree behavior.

---

## 📌 Advantages of Splay Trees

- Simple structure (no balancing information needed)  
- Great performance for frequently accessed nodes  
- Automatically adapts to usage patterns  
- All operations run in **O(log n)** amortized time  

Used in:
- File systems  
- Routers  
- Caches  
- Rope data structures  
- Memory allocators  

---

