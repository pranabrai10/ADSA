Implementation of Quick Sort, Merge Sort, and Heap Sort in C
=
This program demonstrates the implementation of three popular comparison-based sorting algorithms:

1.Quick Sort
2.Merge Sort
3.Heap Sort

Each sorting algorithm follows a different approach and has distinct time and space complexities.
The user can input an array of integers and choose which sorting method to apply.
After sorting, the program displays the sorted array in ascending order.


1.Quick Sort
-
Quick Sort is a divide-and-conquer algorithm.
It works by selecting a pivot element and partitioning the array into two subarrays:

-One containing elements smaller than or equal to the pivot
-Another containing elements greater than the pivot

The process is applied recursively to both subarrays.

Functions Used:

-partition(): Divides the array around the pivot.
-quickSort(): Recursively sorts the subarrays.

Time Complexity:

Case	         Complexity
Best	         O(n log n)
Average	       O(n log n)
Worst	           O(n²)

Space Complexity: O(log n) (due to recursion)

2.Merge Sort
-
Merge Sort also uses the divide-and-conquer strategy.
It divides the array into halves, recursively sorts them, and then merges the sorted halves.

Functions Used:
-mergeSort(): Recursively splits and sorts the array.
-merge(): Combines two sorted halves into one sorted array.

Time Complexity:

Case	       Complexity
Best	       O(n log n)
Average	     O(n log n)
Worst	       O(n log n)

Space Complexity: O(n) (temporary arrays used during merging)

3️.Heap Sort
-
Heap Sort uses a binary heap data structure to sort the elements.
It first builds a max heap, then repeatedly extracts the maximum element and places it at the end of the array.

Functions Used:
-heapify(): Ensures the heap property is maintained.
-heapSort(): Builds the heap and sorts the array.

Time Complexity:

Case	        Complexity
Best	        O(n log n)
Average	      O(n log n)
Worst	        O(n log n)

Space Complexity: O(1) (in-place sorting)

Algorithm Comparison

Algorithm	    Best Case	    Average Case	  Worst Case	 Space Complexity	    Technique Used
Quick Sort	  O(n log n)	   O(n log n)	      O(n²)	        O(log n)	       Divide and Conquer
Merge Sort	  O(n log n)	   O(n log n)	    O(n log n)	     O(n)	           Divide and Conquer
Heap Sort	    O(n log n)	   O(n log n)	    O(n log n)	     O(1)	           Heap Data Structure

Example Run
-
Enter number of elements: 5
Enter 5 integers: 25 13 47 2 19

Choose Sorting Method:
1. Quick Sort
2. Merge Sort
3. Heap Sort
Enter choice: 3

Sorted using Heap Sort:
2 13 19 25 47
