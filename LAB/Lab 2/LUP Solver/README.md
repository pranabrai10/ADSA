LUP decomposition

This program is designed to:

Take a square matrix A and a vector b as input.

Perform LUP decomposition on A, breaking it into:

L → Lower triangular matrix with 1s on the diagonal

U → Upper triangular matrix

P → Permutation matrix (records row swaps for pivoting)

Solve the system of linear equations 
A⋅x=b using the decomposition.

Output the solution vector x.

Essentially, it allows you to solve any system of linear equations efficiently and safely, avoiding numerical issues by pivoting.

Key Concepts
LUP Decomposition

LUP decomposition is a way to factor a matrix A into:

P⋅A=L⋅U

Where:

L → Lower triangular matrix (all zeros above the diagonal, ones on the diagonal)

U → Upper triangular matrix (all zeros below the diagonal)

P → Permutation matrix representing row swaps

Why use P?

Partial pivoting swaps rows so the largest element in a column is on the diagonal.

This prevents division by zero or very small numbers and improves numerical stability.

Forward Substitution

After decomposition, we first solve:

L⋅y=P⋅b

y is an intermediate vector.

Since L is lower triangular with 1s on the diagonal, you can compute y row by row:

y[0] = Pb[0]
y[1] = Pb[1] - L[1][0]*y[0]
y[2] = Pb[2] - L[2][0]*y[0] - L[2][1]*y[1]
...

Backward Substitution

Next, we solve:

U⋅x=y

U is upper triangular, so we solve from the last row upwards:

x[n-1] = y[n-1] / U[n-1][n-1]
x[n-2] = (y[n-2] - U[n-2][n-1]*x[n-1]) / U[n-2][n-2]
...


This gives the final solution vector x.

Step-by-Step Program Flow

Input

Ask the user for the size of the matrix n.

Read the n x n matrix A.

Read the vector b of length n.

LUP Decomposition

Initialize P to the identity permutation.

For each column k:

Find the row with the largest absolute value in that column (pivot).

Swap rows if necessary and update P.

Eliminate elements below the pivot to make U upper triangular.

Store multipliers in L.

Detect singular matrices if a pivot is very small (≈ 0).

Apply Permutation to b

Compute Pb, the permuted vector, according to P.

Solve the System

Forward substitution: Solve L * y = Pb.

Backward substitution: Solve U * x = y.

Output

Print the solution vector x.

Important Features

Works for any square matrix of size n ≤ MAX.

Automatically handles row swaps via partial pivoting.

Checks for singular matrices.

Efficiently solves Ax = b using decomposition instead of direct elimination.

Uses standard numerical linear algebra techniques suitable for numerical computing.

Do you want me to make that diagram?
