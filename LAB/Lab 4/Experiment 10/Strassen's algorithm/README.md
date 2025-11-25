# Strassen’s Matrix Multiplication – C Implementation

This code implements **Strassen’s Algorithm**, an optimized divide-and-conquer method for multiplying two square matrices faster than the conventional matrix multiplication algorithm.

Strassen’s method reduces the number of recursive multiplications from 8 to **7**, lowering the time complexity and improving performance for large matrices.

---

## 📌 Aim

To multiply two square matrices efficiently using **Strassen’s Divide and Conquer Algorithm**.

---

## 📌 Objective

- Implement matrix multiplication using Strassen’s recursive formula  
- Reduce the number of multiplications compared to the traditional method  
- Demonstrate how divide-and-conquer improves asymptotic complexity  

---

## 📌 Background — Matrix Multiplication

For two matrices \( A \) and \( B \) of size \( n \times n \):

- **Traditional Method:**  
  \[
  O(n^3)
  \]
- Uses triple-nested loops

Strassen’s Algorithm improves this using recursion.

---

## 📌 Strassen’s Algorithm — Concept

Given:

\[
A =
\begin{bmatrix}
A_{11} & A_{12} \\
A_{21} & A_{22}
\end{bmatrix},
\qquad
B =
\begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
\]

Naive divide-and-conquer uses **8 multiplications**.

Strassen reduces this to **7 multiplications**:

### 🔹 Strassen’s 7 Products

\[
\begin{aligned}
M_1 &= (A_{11}+A_{22})(B_{11}+B_{22}) \\
M_2 &= (A_{21}+A_{22})B_{11} \\
M_3 &= A_{11}(B_{12}-B_{22}) \\
M_4 &= A_{22}(B_{21}-B_{11}) \\
M_5 &= (A_{11}+A_{12})B_{22} \\
M_6 &= (A_{21}-A_{11})(B_{11}+B_{12}) \\
M_7 &= (A_{12}-A_{22})(B_{21}+B_{22})
\end{aligned}
\]

### 🔹 Final Matrix C = A × B

\[
\begin{aligned}
C_{11} &= M_1 + M_4 - M_5 + M_7 \\
C_{12} &= M_3 + M_5 \\
C_{21} &= M_2 + M_4 \\
C_{22} &= M_1 - M_2 + M_3 + M_6
\end{aligned}
\]

---

## 📌 Algorithm Steps

1. Divide matrices A and B into 4 submatrices each  
2. Compute \( M_1 \) through \( M_7 \) recursively  
3. Use the Strassen formulas to compute \( C_{11}, C_{12}, C_{21}, C_{22} \)  
4. Combine submatrices into full matrix C  
5. Recursively continue until base case **1×1 matrix**

---

## 📌 Time Complexity

| Method | Complexity |
|--------|------------|
| **Strassen’s Algorithm** | \( O(n^{\log_2 7}) \approx O(n^{2.81}) \) |
| **Traditional Multiplication** | \( O(n^3) \) |

Strassen becomes beneficial for **large matrices**, especially when n is a power of two.

---

## 📌 Example

### **Input**
```
Enter size of matrix (power of 2): 2
Enter elements of matrix A:
1 2
3 4
Enter elements of matrix B:
5 6
7 8
```

### **Output**
```
Resultant Matrix (A × B):
19 22
43 50
```

---

## 📌 Result

Strassen’s Algorithm successfully multiplies matrices using divide-and-conquer:

- Reduces **8 multiplications → 7 multiplications**  
- Achieves better asymptotic performance than the classical method  
- Demonstrates an important concept in fast matrix multiplication research  

