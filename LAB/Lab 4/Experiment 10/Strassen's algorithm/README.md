Strassen’s Matrix Multiplication Algorithm
=
Aim
-
To implement Strassen’s Matrix Multiplication Algorithm for multiplying two square matrices efficiently.

Objective
-
To multiply two square matrices using divide and conquer approach that reduces the time complexity compared to the conventional matrix multiplication method.

Matrix Multiplication
-
For two matrices A and B of size n × n, the traditional method requires O(n³) multiplications.
Strassen’s algorithm reduces the number of multiplications by using a divide and conquer approach.

Strassen’s Algorithm Concept
-
Strassen observed that instead of performing 8 recursive multiplications (as in the naive divide-and-conquer approach), the same result can be achieved using 7 multiplications and some additions/subtractions.

Given two matrices divided into four submatrices:

A = | A11  A12 |      B = | B11  B12 |
    | A21  A22 |          | B21  B22 |


He defined 7 new matrices as:

M1 = (A11 + A22) × (B11 + B22)
M2 = (A21 + A22) × B11
M3 = A11 × (B12 - B22)
M4 = A22 × (B21 - B11)
M5 = (A11 + A12) × B22
M6 = (A21 - A11) × (B11 + B12)
M7 = (A12 - A22) × (B21 + B22)


Then the resulting product matrix C = A × B is obtained as:

C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6

Algorithm Steps
-
1.Divide each matrix into four submatrices.
2.Compute M1 to M7 using the above formulas recursively.
3.Combine the results to form the resultant matrix C.
4.Continue until the base case (1×1 matrix) is reached.

Time Complexity
-
-Strassen’s Algorithm: O(n^log₂7) ≈ O(n^2.81)
-Traditional Method: O(n³)
Thus, Strassen’s algorithm is faster for larger matrices.

Example
-
Input
Enter the size of matrix (power of 2): 2
Enter elements of matrix A:
1 2
3 4
Enter elements of matrix B:
5 6
7 8

Output
Resultant Matrix (A × B):
19 22
43 50

Result
-
Strassen’s algorithm successfully multiplies two matrices using divide and conquer approach, reducing the number of multiplications from 8 to 7 and achieving better computational efficiency than the conventional method.
