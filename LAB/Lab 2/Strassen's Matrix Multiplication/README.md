# Strassen Matrix Multiplication (C Implementation)

This program implements **Strassen’s Algorithm** for efficient matrix multiplication in C.  
Strassen’s method improves upon the traditional \(O(n^3)\) matrix multiplication, reducing it to approximately:

\[
O(n^{2.81})
\]

making it faster for sufficiently large matrices.

---

## 📌 Overview

Matrix multiplication is widely used in:

- Computer graphics  
- Machine learning  
- Scientific simulations  
- Numerical linear algebra  

Traditional matrix multiplication requires **8 multiplications** for each recursive division.  
Strassen reduces this to **7 multiplications**, significantly improving performance for large matrices by trading multiplies for additions/subtractions.

---

## 📌 Algorithm Explanation

### 🔹 1. Divide Matrices into Submatrices

For an \(n times n\) matrix (where (n) is a power of 2):

A = [
A_{11} & A_{12}

A_{21} & A_{22}

B ={
B_{11} & B_{12}

B_{21} & B_{22}
]

---

### 🔹 2. Compute Strassen’s 7 Products

Instead of 8 usual multiplications:

```
M1 = (A11 + A22) * (B11 + B22)
M2 = (A21 + A22) * B11
M3 = A11 * (B12 - B22)
M4 = A22 * (B21 - B11)
M5 = (A11 + A12) * B22
M6 = (A21 - A11) * (B11 + B12)
M7 = (A12 - A22) * (B21 + B22)
```

---

### 🔹 3. Reconstruct the Result Matrix

```
C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6
```

All four submatrices form the result:

\[
C = A \cdot B
\]

---

## 📌 Code Structure

| Function        | Description |
|-----------------|-------------|
| `max()`        | Returns max of two integers |
| `next_pow2()`  | Computes nearest power-of-two ≥ n |
| `add_block()`  | Adds two submatrices |
| `sub_block()`  | Subtracts two submatrices |
| `mul_naive()`  | Standard \(O(n^3)\) multiplication (used for small n) |
| `strassen()`   | **Core recursive implementation** |
| `main()`       | User input, memory allocation, output |

---

## 📌 Program Flow

1. User inputs matrix size `n`.
2. Matrices **A**, **B** are read dynamically.
3. Matrices are **padded to the next power of 2** (required for Strassen).
4. `strassen()` performs recursive multiplication.
5. For small sizes (≤ 64), the algorithm switches to the **naive method** for speed.
6. Final matrix **C = A × B** is printed.

---

## 📌 Example Run

### Input
```
Enter n (matrix dimension n x n): 2
Enter A:
1 2
3 4
Enter B:
5 6
7 8
```

### Output
```
Result C = A * B:
19 22
43 50
```

Matches the correct multiplication result.

---

## 📌 Features

✔ Works for any \(n \times n\) matrix  
✔ Automatically pads to the next power of 2  
✔ Efficient recursive divide-and-conquer structure  
✔ Falls back to naive multiplication for small matrices  
✔ Uses safe dynamic memory allocation  

---

## 📌 Notes

- This implementation is optimized for *clarity and correctness*, not raw performance.
- Practical high-performance versions use cache optimizations and blocked memory layouts.
- Strassen's algorithm becomes beneficial only for **large** matrices (typically \(n ≥ 512\)).

---

## 📌 Conclusion

This program demonstrates:

- Divide-and-conquer matrix multiplication  
- The Strassen optimization technique  
- Recursion and submatrix operations  
- Dynamic memory handling  

It provides a clean educational implementation of one of the most important matrix multiplication algorithms in numerical computing.

