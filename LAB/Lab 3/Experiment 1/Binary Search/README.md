Binary Search
=
This C program demonstrates the binary search algorithm using two different approaches:

Recursive approach
Iterative approach

It also includes a sorting function (Bubble Sort) to ensure that the input array is sorted before searching.

Step-by-Step Explanation
-
(a) Sorting the Array
-
Before performing binary search, the program calls the function:
-sortArray(arr, n);
This function uses Bubble Sort, a simple comparison-based sorting algorithm.

How Bubble Sort works:

-It repeatedly compares each pair of adjacent elements in the array.
-If an element is greater than the next element, they are swapped.
-After each pass, the largest element “bubbles up” to its correct position.
-This continues until the entire array becomes sorted.
-This step ensures that binary search can be applied correctly.

(b) Recursive Binary Search Function
-
Function definition:
int binarySearchRecursive(int arr[], int low, int high, int key)

Working principle:

-The function divides the array into halves recursively.
-It finds the middle index using (low + high) / 2.
-Then it compares the middle element with the key.

Three possible cases:
  -If arr[mid] == key, the function returns mid (the key is found).
  -If arr[mid] > key, it searches only in the left half (calls itself recursively with high = mid - 1).
  -If arr[mid] < key, it searches only in the right half (calls itself recursively with low = mid + 1).

If low becomes greater than high, the key is not present, and the function returns -1.

This approach uses recursion to repeatedly divide the problem into smaller subproblems.

(c) Iterative Binary Search Function
-
Function definition:
-int binarySearchIterative(int arr[], int n, int key)

Working principle:

-It performs the same logic as the recursive version, but using a while loop instead of recursion.
-It starts with low = 0 and high = n - 1.
-Inside the loop:
   -Calculates the middle index mid = (low + high) / 2.
   -Compares arr[mid] with key.
   -Adjusts low and high accordingly to narrow down the search range.
-The loop continues until the key is found or the range becomes invalid (low > high).

This method avoids recursion and is more memory-efficient.

(d) Main Function
-
Steps performed in main():

-The user enters the number of elements and the array values.
-The array is sorted using Bubble Sort.
-The sorted array is displayed.
-The user enters the key to search.
-Both recursive and iterative binary search functions are called.
-The index position of the key (if found) is displayed.

Example Execution
-
Input:

Enter number of elements: 5
Enter 5 integers: 8 3 6 1 9
Enter the key to search: 6


Process:

The array is sorted → 1 3 6 8 9
The key 6 is compared using binary search logic.

Output:

Sorted Array: 1 3 6 8 9
Recursive: Key 6 found at index 2
Iterative: Key 6 found at index 2

4.Algorithmic Concept
-
Binary Search Algorithm
-Binary search works on the principle of divide and conquer.
-The search space is divided into halves at every step.
-This reduces the time complexity from O(n) (linear search) to O(log n).

Advantages:
-Very efficient for large sorted datasets.
-Requires fewer comparisons than linear search.

Disadvantages:
-Works only on sorted arrays.

5.Time and Space Complexity
-
Operation                   	Best Case         	Worst Case        	Space Complexity
Binary Search (Iterative)	      O(1)	             O(log n)	               O(1)
Binary Search (Recursive)	      O(1)	             O(log n)	             O(log n)
Bubble Sort	                    O(n)	              O(n²)	                 O(1)

6.Conclusion
-
This program demonstrates how binary search can be implemented using both recursion and iteration.
The use of a sorting function ensures that the array is in the correct order before applying the search.

The recursive approach showcases the concept of function calls and the divide-and-conquer technique, while the iterative approach highlights how loops can be used to achieve the same result efficiently.

Overall, the program effectively illustrates both the logic and implementation of binary search in C.

Would you like me to format this version in Markdown (README.md) style for direct upload to GitHub (same content, but neatly formatted with headings and code blocks)?
