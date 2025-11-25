# Fibonacci Heap – C Implementation (Menu Driven)

This code implements a **Fibonacci Heap** data structure in **C**, including all major operations such as:

- Insert  
- Find-Min  
- Extract-Min  
- Decrease-Key  
- Delete  
- Display Root List  

The implementation also includes all internal mechanisms:
- Consolidation  
- Linking of trees  
- Cut  
- Cascading Cut  

The program is fully **menu-driven**, allowing users to interactively test Fibonacci Heap behavior.

---

## 📌 Features

### ✔ User-Level Operations
| Operation | Description |
|----------|-------------|
| **Insert** | Insert a new key into the heap |
| **Find-Min** | Display the smallest key |
| **Extract-Min** | Remove and return the minimum key |
| **Decrease-Key** | Reduce a key to a smaller value |
| **Delete** | Delete a key from the heap |
| **Display Root List** | Print all trees in the root list |

---

## 📌 Internal Operations (Automatic)
These functions are NOT called by the user; they are triggered internally:

- `consolidate()` → After Extract-Min  
- `fibLink()` → During consolidation  
- `cut()` → During Decrease-Key (when heap property is violated)  
- `cascadingCut()` → When a parent loses its second child  

These maintain the Fibonacci Heap’s structural guarantees and ensure:
- Insert → **O(1)**  
- Decrease-Key → **O(1) amortized**  
- Extract-Min → **O(log n)**  

---

## 📌 File Structure

```
Fibonacci heap/
│
├── code        # Full implementation with menu
├── README.md        # Documentation (this file)
└── Input & Output      #Sample
```

---

## 📌 Compilation

Use GCC with math library:

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
=== Fibonacci Heap Menu ===
1. Insert
2. Find-Min
3. Extract-Min
4. Decrease-Key
5. Delete
6. Display Root List
7. Exit
Enter choice:
```

---

## 📌 How It Works Internally

### 🔹 Insertion
- Node added directly to root list  
- No consolidation  

### 🔹 Extract-Min
- Remove minimum node  
- Move its children to root list  
- Automatically **consolidate** to merge trees  

### 🔹 Decrease-Key
- If new key < parent key:
  - **cut** the node from its parent  
  - move it to root list  
  - If parent was previously marked → **cascading cut**  

### 🔹 Delete
- Decrease key to `-∞`  
- Immediately extract-min  

---

## 📌 Example Run

```
Enter value to insert: 40
Enter value to insert: 12
Enter value to insert: 5
Minimum = 5
Extracted Min = 5
Root List: 12 40
```

---

## 📌 Error Handling

The program correctly detects cases where a key does NOT exist:

### Example:
```
Enter key to delete: 200
Error: Key 200 not found in heap.
```

Same applies to Decrease-Key.

---

## 📌 Advantages of Fibonacci Heap

- Best structure for algorithms with many decrease-key operations  
- Used in:
  - Dijkstra’s shortest path  
  - Prim’s Minimum Spanning Tree  
  - Network optimization algorithms  

---


