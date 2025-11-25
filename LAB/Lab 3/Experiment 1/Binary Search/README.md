# Binary Search – Recursive & Iterative Approaches (C Implementation)

This code demonstrates the **Binary Search algorithm** implemented in C using:

- **Recursive Binary Search**
- **Iterative Binary Search**

It also includes a **Bubble Sort** routine to ensure the input array is sorted before performing binary search.

---

## 📌 Overview

Binary Search is a classic **divide-and-conquer** algorithm that efficiently searches for an element in a **sorted** array by repeatedly halving the search interval.

This program:

- Sorts the input array  
- Searches for a key using both recursive and iterative methods  
- Displays the search results with indices  

---

## 📌 Step-by-Step Explanation

### 🔹 (a) Sorting the Array — Bubble Sort

Before searching, the program calls:

```c
sortArray(arr, n);
```

**Bubble Sort** repeatedly compares adjacent elements and swaps them if they are in the wrong order.

Key properties:

- Largest element “bubbles” to the end after each pass  
- Repeats until entire array is sorted  
- Ensures binary search operates correctly  

---

### 🔹 (b) Recursive Binary Search

Function:

```c
int binarySearchRecursive(int arr[], int low, int high, int key);
```

Working logic:

1. Compute mid index:  
   ```
   mid = (low + high) / 2
   ```
2. Compare:
   - If `arr[mid] == key` → return `mid`
   - If `arr[mid] > key` → search left half
   - If `arr[mid] < key` → search right half  
3. When `low > high`, return `-1` (not found)

This version uses **recursion** and repeatedly divides the search space.

---

### 🔹 (c) Iterative Binary Search

Function:

```c
int binarySearchIterative(int arr[], int n, int key);
```

Working logic:

1. Start with:
   ```
   low = 0, high = n - 1
   ```
2. Loop until found or invalid:
   - Compute mid  
   - Compare and adjust low/high  
3. Return index if found, otherwise `-1`

This approach avoids recursion and uses constant memory.

---

### 🔹 (d) Main Function Workflow

1. User inputs array size and elements  
2. Array is sorted using Bubble Sort  
3. Sorted array is displayed  
4. User inputs key to search  
5. Both binary search methods run  
6. Results (index positions) are printed  

---

## 📌 Example Execution

### **Input**
```
Enter number of elements: 5
Enter 5 integers: 8 3 6 1 9
Enter the key to search: 6
```

### **Process**
- Sorted array → `1 3 6 8 9`  
- Binary Search searches for `6`

### **Output**
```
Sorted Array: 1 3 6 8 9
Recursive: Key 6 found at index 2
Iterative: Key 6 found at index 2
```

---

## 📌 Algorithmic Concept — Binary Search

Binary search follows **divide and conquer**:

- Midpoint is computed  
- Search space is halved every step  
- Much faster than linear search  

### ✔ Advantages
- Very efficient for large sorted datasets  
- Only O(log n) comparisons  

### ✖ Limitation
- Works **only** on sorted arrays  

---

## 📌 Time & Space Complexity

| Operation | Best Case | Worst Case | Space Complexity |
|-----------|-----------|------------|------------------|
| **Binary Search (Iterative)** | O(1) | O(log n) | O(1) |
| **Binary Search (Recursive)** | O(1) | O(log n) | O(log n) (call stack) |
| **Bubble Sort** | O(n) | O(n²) | O(1) |

---

## 📌 Conclusion

This program demonstrates:

- Both recursive and iterative forms of binary search  
- Importance of sorted data before searching  
- Divide-and-conquer (recursive) vs loop-based (iterative) logic  

The implementation helps visualize how binary search efficiently finds elements while maintaining minimal time complexity.


