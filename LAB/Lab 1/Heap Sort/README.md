# Heap Sort – C Implementation

This program implements the **Heap Sort** algorithm in C using a **max-heap** to sort elements in ascending order.  
Heap Sort is an efficient, in-place, comparison-based sorting method with a guaranteed **O(n log n)** runtime.

---

## 📌 Features

- Builds a **max-heap** from the input array  
- Performs **in-place** sorting (auxiliary space O(1))  
- Deterministic O(n log n) time complexity  
- Modular function design:
  - `heapify()`
  - `heapSort()`
  - `swap()`
  - `printArray()`
 
---

## 📂 Files Included

| File         | Description                          |
|--------------|--------------------------------------|
| heap_sort.c  | Complete C implementation of Heap Sort |
| README.md    | Documentation file (this file)      |
| input        | sample input data      |
| output       | sample output data      |

---

## 🚀 How Heap Sort Works

Heap Sort operates in two main phases:

### **1️⃣ Build a Max-Heap**
Transforms the array into a binary heap where:
- every parent node ≥ its children  
- largest element is at the root

This is done bottom-up using `heapify()`.

### **2️⃣ Repeatedly Extract the Maximum**
- Swap the root with the last element  
- Reduce heap size  
- Call `heapify()` to restore heap property  

Repeating this yields a sorted array in **ascending order**.

---

## 📜 Algorithm Complexity

| Operation             | Time Complexity |
|----------------------|-----------------|
| Building Max-Heap    | O(n)            |
| Heapify (single call)| O(log n)        |
| Total Heap Sort      | O(n log n)      |
| Space Complexity     | **O(1)** (in-place) |
| Sorting Stability     | **Not stable**  |

---

## 🖥️ Sample Input / Output

### **Input**
```
Enter number of elements: 6
Enter 6 elements:
5 3 8 1 2 7
```

### **Output**
```
Original array:
5 3 8 1 2 7

Sorted array:
1 2 3 5 7 8
```

---

## 🛠️ How to Compile

Use GCC:

```
gcc heap_sort.c -o heapsort
```

---

## ▶️ How to Run

```
./heapsort
```

---
