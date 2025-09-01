1. INCREASING ORDER OF GROWTH
  
List of Functions

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


Sorted order at n=1024:
1/n < log2(n) < n^0.51 < 12*sqrt(n) < 50*n^0.5 < n*log2(n) < n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32 * n < n^log2(n) < 3^n

Θ-equivalent function pairs

Θ(√n): 12√n , 50√n
Θ(n²): n² − 324 , 100n² + 6n

All the other functions are unique and do not have a Θ-pair in this list.
<img width="1920" height="995" alt="Screenshot (27)" src="https://github.com/user-attachments/assets/eaf6ce95-f32e-48cb-b457-baaec6c2b6e8" />


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
<img width="1920" height="995" alt="Screenshot (29)" src="https://github.com/user-attachments/assets/cce0ce0c-2653-4a06-8a8a-eec6a4022aab" />


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

T(n)=T(2n)+c
Expansion
𝑇(𝑛)=𝑇(𝑛/2)+𝑐
    =𝑇(𝑛/4)+2𝑐
    =𝑇(𝑛/8)+3𝑐

    =𝑇(𝑛/2𝑘)+𝑘𝑐
  
Stop when 
𝑛/2𝑘=1⇒𝑘=log2𝑛n/2k=1⇒k=log2n.

𝑇(𝑛)=𝑇(1)+𝑐⋅log2𝑛

Since 
𝑇(1)=𝑂(1):
𝑇(𝑛)=𝑂(log2𝑛)+𝑂(1)

Adding the final verification step (+c), we get:

𝑇(𝑛)=𝑂(log2𝑛+𝑐)

4. Complexity Analysis

Time Complexity: 
𝑂(log2𝑛+𝑐)

Space Complexity: 
𝑂(log2𝑛)
due to recursion stack (can be reduced to O(1) if implemented iteratively).

5. Dry Run Example

Coins (weights): [10, 10, 10, 9, 10, 10, 10]

Step 1: Split into [10,10,10] vs [9,10,10], right side lighter → recurse.

Step 2: Split [9,10,10] → compare [9] vs [10], left lighter → recurse.

Step 3: Single coin (index 3) → candidate.

Verification: Compare 9 with a known good coin (10). Since 9 < 10 → defective found.

Output:

Defective coin is at position 3.(0 based index)
<img width="768" height="477" alt="image" src="https://github.com/user-attachments/assets/d7f72b7b-eb72-495f-9e64-8a451e6b7cbe" />

