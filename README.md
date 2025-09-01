1. INCREASING ORDER OF GROWTH
  
  1. Purpose
This program compares the growth rates of 12 mathematical functions commonly encountered in algorithm complexity analysis.
It evaluates them for multiple values of 
𝑛
n (2,4,8,…,1024), prints their values, and shows the order of growth for each 𝑛.
At the end, it also groups functions that have the same asymptotic complexity (Θ).

2. List of Functions

The program compares the following 12 functions:

𝑓1(𝑛)=1/𝑛
f2(n)=log2(n)
𝑓3(𝑛)=𝑛⋅log2(𝑛)
𝑓4(𝑛)=12⋅underroot𝑛
𝑓5(𝑛)=50⋅𝑛^0.5
𝑓6(𝑛)=𝑛^0.51
𝑓7(𝑛)=𝑛^2−324
𝑓8(𝑛)=100𝑛^2+6𝑛
𝑓9(𝑛)=2𝑛^3
𝑓10(𝑛)=2^32⋅𝑛
𝑓11(𝑛)=𝑛log2(𝑛)
𝑓12(𝑛)=3^𝑛

3. Approach

Loop over 
n=2,4,8,…,1024

Each function is computed and stored.

Print function values

For each 
𝑛
n, the program prints the 12 values in scientific notation (%.3e) to handle very large numbers.

Sort functions by their values

A bubble-sort based function sortFunctions() is used to sort the functions in ascending order.

Print the growth order

Functions are displayed in increasing order of their values.
Example:

1/n < log2(n) < 12*sqrt(n) < ...


Print asymptotic Θ-equivalent groups

Functions that belong to the same asymptotic growth class are explicitly grouped:

Θ(√n): 12*sqrt(n), 50*n^0.5

Θ(n²): n² - 324, 100n² + 6n

Θ(n): 2^32 * n (same linear growth, different constant)

4. Output
   Comparison of 12 functions for n = 2,4,8,...,1024

n = 2
1/n             = 5.000e-001
log2(n)         = 1.000e+000
n*log2(n)       = 2.000e+000
12*sqrt(n)      = 1.697e+001
50*n^0.5        = 7.071e+001
n^0.51          = 1.424e+000
n^2 - 324       = -3.200e+002
100n^2 + 6n     = 4.120e+002
2n^3            = 1.600e+001
2^32 * n        = 8.590e+009
n^log2(n)       = 2.000e+000
3^n             = 9.000e+000

Sorted order at n=2:
n^2 - 324 < 1/n < log2(n) < n^0.51 < n*log2(n) < n^log2(n) < 3^n < 2n^3 < 12*sqrt(n) < 50*n^0.5 < 100n^2 + 6n < 2^32 * n

n = 4
1/n             = 2.500e-001
log2(n)         = 2.000e+000
n*log2(n)       = 8.000e+000
12*sqrt(n)      = 2.400e+001
50*n^0.5        = 1.000e+002
n^0.51          = 2.028e+000
n^2 - 324       = -3.080e+002
100n^2 + 6n     = 1.624e+003
2n^3            = 1.280e+002
2^32 * n        = 1.718e+010
n^log2(n)       = 1.600e+001
3^n             = 8.100e+001

Sorted order at n=4:
n^2 - 324 < 1/n < log2(n) < n^0.51 < n*log2(n) < n^log2(n) < 12*sqrt(n) < 3^n < 50*n^0.5 < 2n^3 < 100n^2 + 6n < 2^32 * n

n = 8
1/n             = 1.250e-001
log2(n)         = 3.000e+000
n*log2(n)       = 2.400e+001
12*sqrt(n)      = 3.394e+001
50*n^0.5        = 1.414e+002
n^0.51          = 2.888e+000
n^2 - 324       = -2.600e+002
100n^2 + 6n     = 6.448e+003
2n^3            = 1.024e+003
2^32 * n        = 3.436e+010
n^log2(n)       = 5.120e+002
3^n             = 6.561e+003

Sorted order at n=8:
n^2 - 324 < 1/n < n^0.51 < log2(n) < n*log2(n) < 12*sqrt(n) < 50*n^0.5 < n^log2(n) < 2n^3 < 100n^2 + 6n < 3^n < 2^32 * n

n = 16
1/n             = 6.250e-002
log2(n)         = 4.000e+000
n*log2(n)       = 6.400e+001
12*sqrt(n)      = 4.800e+001
50*n^0.5        = 2.000e+002
n^0.51          = 4.112e+000
n^2 - 324       = -6.800e+001
100n^2 + 6n     = 2.570e+004
2n^3            = 8.192e+003
2^32 * n        = 6.872e+010
n^log2(n)       = 6.554e+004
3^n             = 4.305e+007

Sorted order at n=16:
n^2 - 324 < 1/n < log2(n) < n^0.51 < 12*sqrt(n) < n*log2(n) < 50*n^0.5 < 2n^3 < 100n^2 + 6n < n^log2(n) < 3^n < 2^32 * n

n = 32
1/n             = 3.125e-002
log2(n)         = 5.000e+000
n*log2(n)       = 1.600e+002
12*sqrt(n)      = 6.788e+001
50*n^0.5        = 2.828e+002
n^0.51          = 5.856e+000
n^2 - 324       = 7.000e+002
100n^2 + 6n     = 1.026e+005
2n^3            = 6.554e+004
2^32 * n        = 1.374e+011
n^log2(n)       = 3.355e+007
3^n             = 1.853e+015

Sorted order at n=32:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < n*log2(n) < 50*n^0.5 < n^2 - 324 < 2n^3 < 100n^2 + 6n < n^log2(n) < 2^32 * n < 3^n

n = 64
1/n             = 1.563e-002
log2(n)         = 6.000e+000
n*log2(n)       = 3.840e+002
12*sqrt(n)      = 9.600e+001
50*n^0.5        = 4.000e+002
n^0.51          = 8.340e+000
n^2 - 324       = 3.772e+003
100n^2 + 6n     = 4.100e+005
2n^3            = 5.243e+005
2^32 * n        = 2.749e+011
n^log2(n)       = 6.872e+010
3^n             = 3.434e+030

Sorted order at n=64:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < n*log2(n) < 50*n^0.5 < n^2 - 324 < 100n^2 + 6n < 2n^3 < n^log2(n) < 2^32 * n < 3^n

n = 128
1/n             = 7.813e-003
log2(n)         = 7.000e+000
n*log2(n)       = 8.960e+002
12*sqrt(n)      = 1.358e+002
50*n^0.5        = 5.657e+002
n^0.51          = 1.188e+001
n^2 - 324       = 1.606e+004
100n^2 + 6n     = 1.639e+006
2n^3            = 4.194e+006
2^32 * n        = 5.498e+011
n^log2(n)       = 5.629e+014
3^n             = 1.179e+061

Sorted order at n=128:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < 50*n^0.5 < n*log2(n) < n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32 * n < n^log2(n) < 3^n

n = 256
1/n             = 3.906e-003
log2(n)         = 8.000e+000
n*log2(n)       = 2.048e+003
12*sqrt(n)      = 1.920e+002
50*n^0.5        = 8.000e+002
n^0.51          = 1.691e+001
n^2 - 324       = 6.521e+004
100n^2 + 6n     = 6.555e+006
2n^3            = 3.355e+007
2^32 * n        = 1.100e+012
n^log2(n)       = 1.845e+019
3^n             = 1.390e+122

Sorted order at n=256:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < 50*n^0.5 < n*log2(n) < n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32 * n < n^log2(n) < 3^n

n = 512
1/n             = 1.953e-003
log2(n)         = 9.000e+000
n*log2(n)       = 4.608e+003
12*sqrt(n)      = 2.715e+002
50*n^0.5        = 1.131e+003
n^0.51          = 2.408e+001
n^2 - 324       = 2.618e+005
100n^2 + 6n     = 2.622e+007
2n^3            = 2.684e+008
2^32 * n        = 2.199e+012
n^log2(n)       = 2.418e+024
3^n             = 1.932e+244

Sorted order at n=512:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < 50*n^0.5 < n*log2(n) < n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32 * n < n^log2(n) < 3^n

n = 1024
1/n             = 9.766e-004
log2(n)         = 1.000e+001
n*log2(n)       = 1.024e+004
12*sqrt(n)      = 3.840e+002
50*n^0.5        = 1.600e+003
n^0.51          = 3.430e+001
n^2 - 324       = 1.048e+006
100n^2 + 6n     = 1.049e+008
2n^3            = 2.147e+009
2^32 * n        = 4.398e+012
n^log2(n)       = 1.268e+030
3^n             = 1.#IOe+000

Sorted order at n=1024:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < 50*n^0.5 < n*log2(n) < n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32 * n < n^log2(n) < 3^n

Asymptotic T-equivalent groups:
T(sqrt(n)):  12*sqrt(n), 50*n^0.5
T(n^2):      n^2 - 324, 100n^2 + 6n
T(n):        n*log2(n) is bigger than n, but 2^32*n is also T(n)


2. TERNARY SEARCH

Functions Used

binarySearch(int arr[], int n, int key)

Iterative function.

Divides the array into two halves each step.

Makes 1 comparison per iteration (with arr[mid]).

Returns the index if key is found, else -1.

ternarySearch(int arr[], int l, int r, int key)

Recursive function.

Divides the array into three parts using two midpoints (mid1, mid2).

Makes 2 comparisons per recursive call (arr[mid1] and arr[mid2]).

Returns the index if key is found, else -1.

main()

Generates sorted arrays of different sizes.

Calls both search functions.

Counts and compares the number of comparisons.

Saves results in output.dat and plots using gnuplot.

Binary Search vs Ternary Search
Feature	                 Binary Search	              Ternary Search
Division	                 2 parts	                     3 parts
Comparisons per step	       1	                           2
Time Complexity	           O(log₂ n)	                  O(log₃ n)
Practical Performance	Faster (fewer comparisons)	Slower (more comparisons)
Implementation	Iterative	Recursive

Conclusion: Even though ternary search reduces the range faster (log₃ n vs log₂ n), it does two comparisons per step, making it slower in practice.
Binary Search is more efficient.

3. DETERMINING IF A COIN IS LIGHTER OR NOT

1. Problem Statement

A company manufactures coins that must have identical weights. During inspection, one worker may produce a coin that is lighter due to over-shaping.

There are 
𝑛
n coins in total.

Either one coin is lighter (defective) or all coins are perfect.

We are allowed to use only a balance weighing scale to compare groups of coins.

The task is to determine which coin is defective (lighter) or report “none” if all are perfect.

We must design an algorithm using divide and conquer in

𝑂(log2𝑛+𝑐)
O(log2n+c)
time, where 
            𝑐
c is a positive constant.

2. Algorithm (Divide and Conquer Approach)

Idea:

Divide coins into two halves.

Use balance scale to compare sums of the two halves.

Recurse only into the lighter half.

If the halves balance and 
𝑛
n is odd, check the excluded coin.

If all balance and no excluded coin exists, conclude no defective coin.

At the end, verify the candidate by comparing with a known good coin.

Step-by-Step Procedure

Base Case:

If only one coin remains → it is the candidate.

If no coin remains → return “none.”

Divide: Split coins into two halves. If 
𝑛
n is odd, leave one coin excluded.

Weigh: Compare the two halves on the balance scale.

If left lighter → recurse on left half.

If right lighter → recurse on right half.

If equal →

If odd, recurse on excluded coin.

If even, return “none.”

Verify: Compare the candidate with a known good coin.

If lighter → defective found.

Otherwise → return “none.”

3. Recurrence Relation

At each step, we reduce the problem size by half, performing one weighing.

𝑇(𝑛)=𝑇(𝑛2)+𝑐
T(n)=T(2n)+c
Expansion
𝑇(𝑛)=𝑇(𝑛/2)+𝑐
    =𝑇(𝑛/4)+2𝑐
    =𝑇(𝑛/8)+3𝑐
T(n)=T(n/2)+c=T(n/4)+2c=T(n/8)+3c
    =𝑇(𝑛/2𝑘)+𝑘𝑐
    =T(n/2k)+kc

Stop when 
𝑛/2𝑘=1⇒𝑘=log2𝑛n/2k=1⇒k=log2n.

𝑇(𝑛)=𝑇(1)+𝑐⋅log2𝑛
T(n)=T(1)+c⋅log2n

Since 
𝑇(1)=𝑂(1)
T(1)=O(1):

𝑇(𝑛)=𝑂(log2𝑛)+𝑂(1)
T(n)=O(log2n)+O(1)

Adding the final verification step (+c), we get:

𝑇(𝑛)=𝑂(log2𝑛+𝑐)
T(n)=O(log2n+c)
4. Complexity Analysis

Time Complexity: 
𝑂(log2𝑛+𝑐)
O(log2n+c)

Space Complexity: 
𝑂(log2𝑛)O(log2n) 
due to recursion stack (can be reduced to 
𝑂(1)
O(1) if implemented iteratively).

5. Dry Run Example

Coins (weights): [10, 10, 10, 9, 10, 10, 10]

Step 1: Split into [10,10,10] vs [9,10,10], right side lighter → recurse.

Step 2: Split [9,10,10] → compare [9] vs [10], left lighter → recurse.

Step 3: Single coin (index 3) → candidate.

Verification: Compare 9 with a known good coin (10). Since 9 < 10 → defective found.

Output:

Defective coin is at position 3.
