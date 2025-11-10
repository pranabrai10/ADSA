Strassen Matrix Multiplication
=
This code implements Strassen’s Algorithm for matrix multiplication in C, which reduces the time complexity of multiplying two matrices from
the traditional O(n³) to approximately O(n^2.81).

Overview
-
Matrix multiplication is a fundamental operation in computer science, used in various applications like graphics, scientific computing, and machine learning.
The Strassen algorithm is a divide-and-conquer approach that optimizes matrix multiplication by reducing the number of recursive multiplications needed.

Instead of performing 8 multiplications on submatrices like the conventional method, Strassen’s method performs only 7, reducing computational cost for large matrices.

Algorithm Explanation
-
1.Basic Idea
-
Given two square matrices A and B of size n × n, Strassen’s algorithm recursively divides them into 4 submatrices each:

A = | A11  A12 |
    | A21  A22 |

B = | B11  B12 |
    | B21  B22 |


It then computes 7 intermediate matrices (M1 to M7) using additions and subtractions of these submatrices.

2.Strassen’s Formulas
-
M1 = (A11 + A22) * (B11 + B22)
M2 = (A21 + A22) * B11
M3 = A11 * (B12 - B22)
M4 = A22 * (B21 - B11)
M5 = (A11 + A12) * B22
M6 = (A21 - A11) * (B11 + B12)
M7 = (A12 - A22) * (B21 + B22)


Then the resulting submatrices of C are:

C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6

Code Structure
Function	        Description
max()	            Returns the maximum of two integers.
next_pow2()	      Finds the next power of two (used for padding matrices).
add_block()	      Performs element-wise matrix addition for submatrices.
sub_block()	      Performs element-wise matrix subtraction for submatrices.
mul_naive()	      Performs standard O(n³) matrix multiplication (used for small matrices).
strassen()	      Core recursive function implementing Strassen’s algorithm.
main()	          Handles user input, matrix allocation, and final output.

Program Flow
-
The user inputs the matrix size n.

The program dynamically allocates memory for matrices A, B, and C.

Matrices A and B are padded to the next power of 2 (since Strassen works best on 2ⁿ × 2ⁿ matrices).

The strassen() function recursively multiplies the matrices:
-For small sizes (≤64), it switches to mul_naive() for efficiency.
-For larger sizes, it performs recursive submatrix multiplication.

The resulting matrix C = A × B is printed.

Example Run
-
Enter n (matrix dimension n x n): 2
Enter A (2 x 2) row-wise:
1 2
3 4
Enter B (2 x 2) row-wise:
5 6
7 8

Result C = A * B:
19 22
43 50


Output matches the standard matrix multiplication result.

Features
-
-Works for any square matrix size (n × n).
-Automatically pads matrices to the next power of 2 for Strassen’s algorithm.
-Recursively optimized multiplication with base case switch to naive method.
-Handles dynamic memory allocation and cleanup safely.

This implementation uses dynamic memory allocation and recursion for clarity, not absolute performance.
