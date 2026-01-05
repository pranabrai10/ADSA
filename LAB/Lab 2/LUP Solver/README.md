# LUP Decomposition and Linear System Solver (C Implementation)

This program performs **LUP decomposition** on a square matrix **A** and uses it to solve the linear system:

\[
Ax = b
\]

It decomposes the matrix into:

- **L** → Lower triangular matrix (1s on diagonal)  
- **U** → Upper triangular matrix  
- **P** → Permutation matrix (handles row swaps for stability)

Then it solves the system in two phases:

1. **Forward substitution:** solve \(Ly = Pb)  
2. **Backward substitution:** solve \(Ux = y)

The final output is the solution vector **x**.

---

## 📌 Overview

This program:

- Accepts matrix **A** and vector **b** as input  
- Computes LUP decomposition using **partial pivoting**  
- Detects singular or nearly-singular matrices  
- Solves the system efficiently using triangular systems  
- Outputs the final solution vector  

LUP decomposition is one of the most stable and widely used numerical methods for solving linear equations.

---

## 📌 Key Concepts

### 🔹 LUP Decomposition

Factor a matrix:

\[
PA = LU
\]

Where:

- **L** → Lower triangular matrix (1s on diagonal)  
- **U** → Upper triangular matrix  
- **P** → Permutation matrix for row pivoting  

### 🔹 Why Pivoting? (Permutation Matrix P)

Partial pivoting swaps rows so that the largest available pivot appears on the diagonal.

This prevents:

- Division by extremely small numbers  
- Numerical instability  
- Failure when matrix elements are zero  

`P` ensures that the correct rows are tracked throughout decomposition.

---

## 📌 Forward Substitution

Solves the system:

\[
Ly = Pb
\]

Since **L is lower triangular**, compute:

```
y[0] = Pb[0]
y[1] = Pb[1] - L[1][0] * y[0]
y[2] = Pb[2] - L[2][0] * y[0] - L[2][1] * y[1]
...
```

This produces an intermediate vector **y**.

---

## 📌 Backward Substitution

Solve:

\[
Ux = y
\]

Since **U is upper triangular**, solve from bottom to top:

```
x[n-1] = y[n-1] / U[n-1][n-1]
x[n-2] = (y[n-2] - U[n-2][n-1]*x[n-1]) / U[n-2][n-2]
...
```

This produces the final **solution vector x**.

---

## 📌 Step-by-Step Program Flow

### 1️⃣ Input
- Read integer **n** (matrix size)
- Read **A[n][n]**
- Read vector **b[n]**

---

### 2️⃣ LUP Decomposition

Performed column by column:

#### ✔ Initialize permutation
`P[i] = i` (identity permutation)

#### ✔ Pivot selection
Find row with max absolute value in column `k`  
→ swap rows if necessary

#### ✔ Elimination  
Eliminate elements below pivot to form **U**  
Store multipliers in **L**

#### ✔ Singular matrix check  
If pivot ≈ 0 → matrix is singular

---

### 3️⃣ Apply Permutation to b

Compute vector:

\[
Pb = b\ \text{reordered according to } P
\]

Used during forward substitution.

---

### 4️⃣ Solve the system

✔ **Forward substitution:**  
Solve \(L y = P b\)

✔ **Backward substitution:**  
Solve \(U x = y\)

---

### 5️⃣ Output

Print the final solution vector:

```
Solution x:
x[0] = ...
x[1] = ...
x[2] = ...
```

---

## 📌 Important Features

✔ Works for any square matrix up to size `MAX`  
✔ Fully handles partial pivoting  
✔ Detects singular/unstable matrices  
✔ Uses stable numerical linear algebra methods  
✔ Efficient: decomposition is reused to solve the system  

---

## 📌 Applications

- Engineering simulations  
- Solving linear equations repeatedly  
- Numerical analysis  
- Computer graphics transformations  
- Matrix inversion and determinants  

---

## 📌 Conclusion

This program demonstrates:

- Stable LUP matrix decomposition  
- Forward and backward substitution  
- Solving \(A x = b\) efficiently and accurately  

It is a core technique used throughout scientific computing, data science, and numerical methods.

