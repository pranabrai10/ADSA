Quick Sort using Median-of-Three Pivot
=
This program implements the Quick Sort algorithm in C using the Median-of-Three pivot selection technique to improve efficiency.
The Median-of-Three method helps in choosing a better pivot by taking the median value among the first, middle, and last elements of the partitioned array.
This approach reduces the chances of encountering the worst-case time complexity, especially when the input array is already sorted or nearly sorted.

Explanation of the Code
-
1.Swap Function
-
void swap(int *a, int *b)
This function exchanges the values of two integers using a temporary variable. It is used frequently throughout the program to rearrange elements during sorting.

2.Median-of-Three Pivot Selection
-
int medianOfThree(int arr[], int low, int high)

-Finds the first (low), middle (mid), and last (high) elements of the array.
-Sorts these three values to determine their median.
-The median element is used as the pivot, placed at position high - 1.

This strategy ensures a better pivot choice, minimizing the chance of unbalanced partitions and improving overall efficiency.

3.Partition Function
-
int partition(int arr[], int low, int high)

-The array is rearranged such that all elements less than the pivot are placed on the left, and those greater than the pivot are on the right.
-After rearrangement, the pivot is placed in its correct sorted position.
-Returns the index (pi) of the pivot for recursive sorting.

4.Quick Sort Function
-
void quickSort(int arr[], int low, int high)

-Divides the array into subarrays based on the pivot.
-Recursively sorts the left and right subarrays.
-For small partitions (size ≤ 3), the function performs a simple manual sort instead of recursion to reduce overhead.

5.Main Function
-
int main()

-Accepts user input for the number of elements and the elements themselves.
-Calls the quickSort() function to sort the array.
-Displays the final sorted array.

Algorithm Efficiency

Case	             Time Complexity
Best Case	          O(n log n)
Average Case	      O(n log n)
Worst Case	          O(n²) (minimized with median-of-three method)

Space Complexity: O(log n) (due to recursion stack)

Key Concepts
-
-Divide and Conquer: Quick Sort divides the array into smaller parts and sorts them independently.
-Median-of-Three: Improves pivot selection and prevents skewed partitions.
-Recursion: The algorithm calls itself to sort the left and right subarrays.

Example Run
-
Enter number of elements: 5
Enter 5 integers: 56 32 78 12 43
Sorted array using Quick Sort (median-of-three pivot):
12 32 43 56 78
