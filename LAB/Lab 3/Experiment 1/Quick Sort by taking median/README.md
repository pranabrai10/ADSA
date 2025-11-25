# Quick Sort using Median-of-Three Pivot – C Implementation

This code implements **Quick Sort** in C using the **Median-of-Three pivot selection technique** to improve performance.  
Choosing a good pivot reduces the risk of worst-case behavior and produces more balanced partitions—especially when the array is already sorted or nearly sorted.

---

## 📌 Overview

Quick Sort is a **divide-and-conquer** sorting algorithm that works by:

1. Selecting a pivot  
2. Partitioning the array around the pivot  
3. Recursively sorting the left and right partitions  

This version uses **Median-of-Three** pivot selection for more robust performance.

---

## 📌 Why Median-of-Three?

Instead of picking:

- the first element  
- or the last element  
- or the middle element  

Median-of-Three chooses the **median value among (first, middle, last)**.  
This significantly reduces the chances of highly unbalanced partitions.

Example bad cases avoided:

- Already sorted input  
- Reverse sorted input  
- Nearly sorted sequences  

---

## 📌 Explanation of the Code

### 🔹 1. Swap Function
```c
void swap(int *a, int *b)
```
Swaps two integers using a temporary variable.  
Used throughout the algorithm for rearranging elements.

---

### 🔹 2. Median-of-Three Pivot Selection
```c
int medianOfThree(int arr[], int low, int high)
```

Steps:
- Identify first (`low`), middle (`mid`), and last (`high`) elements  
- Sort these three values  
- Place the median at position **high − 1**  
- Return it as the pivot  

This produces a more stable pivot choice and lowers the chance of worst-case partitions.

---

### 🔹 3. Partition Function
```c
int partition(int arr[], int low, int high)
```

The array is rearranged so that:

- Elements **less than pivot** → left side  
- Elements **greater than pivot** → right side  

Finally, the pivot is placed in its correct sorted position, and the pivot index is returned.

---

### 🔹 4. Quick Sort Function
```c
void quickSort(int arr[], int low, int high)
```

- Recursively sorts left and right partitions  
- Uses **Median-of-Three** to select pivot  
- For small partitions (size ≤ 3), performs manual sorting for efficiency  
- Combines recursion with optimized pivot selection  

This hybrid approach reduces overhead and improves real-world performance.

---

### 🔹 5. Main Function

Handles user interaction:

- Reads number of elements  
- Reads the array  
- Calls `quickSort()`  
- Displays the sorted result  

---

## 📌 Algorithm Efficiency

| Case | Time Complexity |
|------|-----------------|
| **Best Case** | O(n log n) |
| **Average Case** | O(n log n) |
| **Worst Case** | O(n²) (rare with median-of-three) |

**Space Complexity:**  
- O(log n) → recursion stack

Median-of-Three dramatically reduces the frequency of worst-case behavior.

---

## 📌 Key Concepts

- **Divide and Conquer** — Split, conquer, and combine  
- **Median-of-Three Pivoting** — More balanced partitions  
- **Recursion** — Quick Sort calls itself for subproblems  
- **In-place Sorting** — No extra arrays required  

---

## 📌 Example Run

### **Input**
```
Enter number of elements: 5
Enter 5 integers: 56 32 78 12 43
```

### **Output**
```
Sorted array using Quick Sort (median-of-three pivot):
12 32 43 56 78
```

---

## 📌 Conclusion

This implementation demonstrates a practical enhancement to Quick Sort using **Median-of-Three pivot selection**, making the algorithm faster and more reliable for real data.

