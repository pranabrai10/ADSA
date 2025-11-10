 LUP Decomposition
=
This program performs **LUP decomposition** (LU decomposition with partial pivoting) on a square matrix.  
It decomposes a given matrix `A` into three matrices:

- L: Lower triangular matrix with unit diagonal  
- U: Upper triangular matrix  
- P: Permutation matrix representing row swaps  

The decomposition satisfies the equation:

P * A = L * U


Objective
-
The program is designed to:

- Decompose a 3x3 matrix using **partial pivoting** for numerical stability.  
- Extract **L** (lower triangular) and **U** (upper triangular) matrices.  
- Display the **permutation matrix P** corresponding to row swaps.  

This is useful for solving systems of linear equations and understanding matrix factorization.



Included Libraries
-
#include <stdio.h>  // Input/output functions
#include <math.h>   // Mathematical functions (fabs)
<stdio.h> → For printf and scanf

<math.h> → For fabs() (absolute value of floating point numbers)

Constants and Macros
-
#define N 3   // Size of the matrix (3x3)
N defines the size of the square matrix.

The program can be extended for larger matrices by increasing N.

Data Structures
-
Matrix Arrays:

double A[N][N];  // Original input matrix
double L[N][N];  // Lower triangular matrix
double U[N][N];  // Upper triangular matrix
int P[N];        // Permutation array (records row swaps)
P[i] = j means row i in the final matrix corresponds to row j in the original matrix after pivoting.

Function: lupDecomposition
-
This function performs the LUP decomposition.

Step 1: Initialize Permutation Array
for (int i = 0; i < N; i++)
    P[i] = i;
Initially, no row swaps; P represents the identity permutation.

Step 2: Pivoting
for (int k = 0; k < N; k++) {
    double max = 0.0;
    int k_prime = k;
    for (int i = k; i < N; i++) {
        if (fabs(A[i][k]) > max) {
            max = fabs(A[i][k]);
            k_prime = i;
        }
    }
}
Finds the row with maximum absolute value in column k.

Improves numerical stability by reducing round-off errors.

Row Swap:

if (k_prime != k) {
    swap rows in A;
    swap indices in P;
}

Step 3: Elimination
for (int i = k+1; i < N; i++) {
    A[i][k] /= A[k][k];
    for (int j = k+1; j < N; j++)
        A[i][j] -= A[i][k] * A[k][j];
}
Converts A into an upper triangular form (U)

Stores multipliers below the diagonal → will form L.

Step 4: Extract L and U
if (i > j) {
    L[i][j] = A[i][j];
    U[i][j] = 0;
} else if (i == j) {
    L[i][j] = 1;
    U[i][j] = A[i][j];
} else {
    L[i][j] = 0;
    U[i][j] = A[i][j];
}
L gets values below diagonal, diagonal = 1

U gets upper triangular values

Program Logic (main)
Input matrix A from user:

printf("Enter elements of 3x3 matrix A:\n");
scanf("%lf", &A[i][j]);
Perform LUP decomposition:

lupDecomposition(A, L, U, P);
Print permutation matrix P:

1 indicates row mapping after pivoting, 0 elsewhere.

Print L and U matrices neatly using printf.

