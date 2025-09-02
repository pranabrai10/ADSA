1. Overview

This program implements and compares Binary Search and Ternary Search algorithms. It measures the number of element comparisons each algorithm performs when searching for a key in a sorted array of varying sizes.

The program:
-Implements Binary Search (iterative) and Ternary Search (recursive).
-Tracks the number of comparisons required for each algorithm.
-Runs experiments for increasing array sizes (from 10 up to 100,000).
-Uses gnuplot to automatically plot the results for visual comparison.


2. Files Generated

output.dat → Contains experimental results in the format:
n comparisonsBinary comparisonsTernary

Example:
10 3 4
100 7 10
1000 10 15

gnuplot plot window → A graph comparing binary vs ternary search.


3. Program Structure

Global Variables
int comparisonsBinary = 0;
int comparisonsTernary = 0;
These counters keep track of the number of element comparisons performed in each search.

Binary Search Function
int binarySearch(int arr[], int n, int key);

Input:
arr[]: sorted array
n: number of elements
key: element to search

Output:
Returns index of the key if found, else -1.

Process:
Repeatedly divides the array into two halves.
Compares the middle element with the key (comparisonsBinary++ each time).

Time complexity: O(log₂n).
Ternary Search Function
int ternarySearch(int arr[], int l, int r, int key);

Input:
arr[]: sorted array
l: left index
r: right index
key: element to search

Output:
Returns index of the key if found, else -1.

Process:
Divides the array into three parts using mid1 and mid2.
Compares the key with both mids (comparisonsTernary++ twice per step).
Recursively searches the appropriate segment.

Time complexity: O(log₃n), but with more comparisons per step than binary search.

Main Function
int main();
Runs experiments for array sizes: 10, 100, 1000, 10000, 100000.

For each size:
Creates a sorted array arr[i] = i+1.
Chooses key = n (worst-case search: last element).
Runs binarySearch and ternarySearch.
Invokes gnuplot to generate a line graph.


4. Graph Details (gnuplot commands)

The following gnuplot script is executed:
set title 'Binary Search vs Ternary Search Comparisons'
set xlabel 'Array size (n)'
set ylabel 'Number of Comparisons'
set logscale x
set grid
plot 'output.dat' using 1:2 with linespoints title 'Binary Search', \
     'output.dat' using 1:3 with linespoints title 'Ternary Search'

X-axis: Array size (n) in log scale.
Y-axis: Number of comparisons.
Two curves: Binary Search and Ternary Search.


5. Expected Results

Binary Search performs fewer comparisons than Ternary Search in practice, even though both have logarithmic complexity.
This is because binary search makes 1 comparison per iteration, while ternary search often makes 2 comparisons per iteration.


6. Complexity Analysis

Algorithm	Time Complexity	Comparisons per Step	Practical Performance
Binary Search	O(log₂n)	1	Faster
Ternary Search	O(log₃n)	2	Slower
Thus, binary search is generally more efficient.

