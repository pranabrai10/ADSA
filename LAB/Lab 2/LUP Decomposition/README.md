# LUP Decomposition – C Implementation (LU with Partial Pivoting)

This program performs **LUP decomposition** of a square matrix.  
Given a matrix **A**, it computes:

- **L** → Lower triangular matrix (diagonal entries = 1)  
- **U** → Upper triangular matrix  
- **P** → Permutation matrix representing row swaps  

Such that:

\[
P \cdot A = L \cdot U
\]

LUP decomposition is preferred over plain LU because **partial pivoting improves numerical stability**.

---

## 📌 Overview

The program:

- Accepts a **3×3 matrix** as input  
- Performs **partial-pivoting LU decomposition**  
- Produces matrices **L**, **U**, and the permutation array **P**  
- Prints all resulting matrices in formatted output  

---

## 📌 Included Libraries

```c
#include <stdio.h>  // For input/output
#include <math.h>   // For fabs()
```

- `stdio.h` → reading the matrix, printing results  
- `math.h` → `fabs()` for pivot selection  

---

## 📌 Constant Definitions

```c
#define N 3
```

Specifies the matrix size (3×3).  
Can be changed to support larger matrices.

---

## 📌 Data Structures

### Matrix arrays

```c
double A[N][N];   // Input matrix (modified during decomposition)
double L[N][N];   // Lower triangular matrix
double U[N][N];   // Upper triangular matrix
int P[N];         // Permutation array
```

### Meaning of permutation array `P`

- `P[i] = j` → row `i` of the permuted matrix corresponds to **original row j**

This is equivalent to storing matrix **P** without actually storing a full matrix.

---

## 📌 Function: `lupDecomposition()`

Performs the LUP decomposition using partial pivoting.

---

### 🔹 Step 1 — Initialize permutation array

```c
for (int i = 0; i < N; i++)
    P[i] = i;
```

Initially represents the identity permutation.

---

### 🔹 Step 2 — Pivot Selection (Partial Pivoting)

Find the row in column `k` with the largest absolute value:

```c
double max = 0.0;
int k_prime = k;

for (int i = k; i < N; i++) {
    if (fabs(A[i][k]) > max) {
        max = fabs(A[i][k]);
        k_prime = i;
    }
}
```

**Why?**  
To minimize round-off errors and avoid division by small pivot values.

---

### 🔹 Step 3 — Swap Rows in `A` and `P` (if needed)

```c
if (k_prime != k) {
    swap rows in A;
    swap P[k] and P[k_prime];
}
```

This updates both the matrix and the permutation tracking.

---

### 🔹 Step 4 — Gaussian Elimination

Compute multipliers and eliminate entries below diagonal:

```c
A[i][k] /= A[k][k];
for (int j = k+1; j < N; j++)
    A[i][j] -= A[i][k] * A[k][j];
```

- Values stored **below diagonal** become entries of **L**
- Values **on and above diagonal** become entries of **U**

---

## 📌 Extracting L and U

After elimination, fill `L` and `U`:

```c
if (i > j) {               // below diagonal
    L[i][j] = A[i][j];
    U[i][j] = 0;
}
else if (i == j) {         // diagonal
    L[i][j] = 1;
    U[i][j] = A[i][j];
}
else {                     // above diagonal
    L[i][j] = 0;
    U[i][j] = A[i][j];
}
```

- `L` always has **1s on diagonal**
- `U` is upper triangular

---

## 📌 Program Flow (main)

### 1️⃣ Input matrix A
```c
printf("Enter elements of 3x3 matrix A:\n");
scanf("%lf", &A[i][j]);
```

### 2️⃣ Perform decomposition
```c
lupDecomposition(A, L, U, P);
```

### 3️⃣ Print permutation matrix P

Permutation matrix is constructed as:

```
P[i][j] = 1 if P[i] == j
P[i][j] = 0 otherwise
```

### 4️⃣ Print L and U

All matrices are printed using formatted `printf`.

---

## 📌 Example Output

```
Permutation matrix P:
1 0 0
0 0 1
0 1 0

Matrix L:
1   0   0
0.5 1   0
0.3 0.2 1

Matrix U:
4  2  1
0  3  5
0  0  6
```

Which satisfies:

\[
P \cdot A = L \cdot U
\]

---

## 📌 Applications

LUP decomposition is widely used in:

- Solving linear systems **A x = b**
- Matrix inversion
- Determinant calculation
- Numerical linear algebra
- Scientific computing and simulations

---

## 📌 Advantages

✔ More stable than LU without pivoting  
✔ Handles small pivots gracefully  
✔ Decomposition can be reused for multiple right-hand sides  
✔ Efficient for small and medium-sized matrices  

---

## 📌 Limitations

✘ Only implemented for **3×3 matrices** (extendable)  
✘ Assumes matrix is non-singular  
✘ Does not solve Ax = b (decomposition only)

---

## 📌 Conclusion

This program demonstrates how **LUP decomposition** works with:

- Partial pivoting  
- Matrix factorization  
- Extraction of L, U, and P matrices  

It provides a solid foundation for understanding numerical stability and matrix operations used in advanced scientific computing.

