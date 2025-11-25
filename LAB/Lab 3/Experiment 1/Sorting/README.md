# Quick Sort, Merge Sort, and Heap Sort – C Implementation

This code demonstrates the implementation of **three widely-used comparison-based sorting algorithms** in C:

1. **Quick Sort**  
2. **Merge Sort**  
3. **Heap Sort**

Each algorithm follows a different strategy, uses different data structures internally, and has unique time/space complexities.  
The user enters an array and chooses which sorting method to apply.  
The sorted array is then displayed in ascending order.

---

## 📌 1. Quick Sort

Quick Sort is a **divide-and-conquer** algorithm that:

1. Selects a pivot element  
2. Partitions the array:
   - Left side → elements ≤ pivot  
   - Right side → elements > pivot  
3. Recursively sorts the two partitions  

### 🔹 Functions Used
- `partition()` — partitions the array around the pivot  
- `quickSort()` — recursively sorts subarrays  

### 🔹 Time Complexity

| Case | Complexity |
|-------|------------|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |

### 🔹 Space Complexity  
```
O(log n)  // recursion stack
```

---

## 📌 2. Merge Sort

Merge Sort is another **divide-and-conquer** sorting algorithm.  
It divides the array into halves until subarrays of size 1 remain, then **merges** them in sorted order.

### 🔹 Functions Used
- `mergeSort()` — recursively splits and sorts the array  
- `merge()` — merges two sorted halves into one sorted array  

### 🔹 Time Complexity

| Case | Complexity |
|-------|------------|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

### 🔹 Space Complexity  
```
O(n)  // extra arrays used during merging
```

---

## 📌 3. Heap Sort

Heap Sort uses a **binary heap** to sort elements.

### Algorithm Outline:
1. Build a **max heap** from the array  
2. Repeatedly extract the largest element  
3. Place extracted elements at the end of the array  
4. Restore heap structure after each extraction  

### 🔹 Functions Used
- `heapify()` — maintains heap structure  
- `heapSort()` — converts the array into a heap and sorts it  

### 🔹 Time Complexity

| Case | Complexity |
|-------|------------|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

### 🔹 Space Complexity  
```
O(1)  // in-place algorithm
```

---

## 📌 Algorithm Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Technique |
|-----------|-----------|---------------|-------------|------------------|-----------|
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | Divide & Conquer |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | Divide & Conquer |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) | Heap Data Structure |

---

## 📌 Example Run

### **Input**
```
Enter number of elements: 5
Enter 5 integers: 25 13 47 2 19

Choose Sorting Method:
1. Quick Sort
2. Merge Sort
3. Heap Sort
Enter choice: 3
```

### **Output**
```
Sorted using Heap Sort:
2 13 19 25 47
```

---

## 📌 Conclusion

This program demonstrates the three most important comparison-based sorting algorithms:

- **Quick Sort** → Fastest on average, uses recursion  
- **Merge Sort** → Stable and predictable, best for large datasets  
- **Heap Sort** → In-place, guaranteed O(n log n)  

Together, they illustrate multiple approaches to problem-solving in sorting:

- Divide & Conquer  
- Heap-based selection  
- Recursive & iterative strategies  


