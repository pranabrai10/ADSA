KMP and Rabin–Karp String Matching Algorithms
=
Aim
-
To implement the Knuth–Morris–Pratt (KMP) Algorithm and the Rabin–Karp Fingerprinting Algorithm for efficient pattern searching in strings.

Objective
-
To search for occurrences of a given pattern within a text using efficient string-matching algorithms that reduce unnecessary comparisons.

1.Knuth–Morris–Pratt (KMP) Algorithm
-
-KMP improves the naive string search by avoiding re-comparisons.
-It preprocesses the pattern to build an LPS (Longest Prefix Suffix) array.
-The LPS array indicates the longest proper prefix of the pattern that is also a suffix — helping to skip unnecessary checks.

Time Complexity:
-
-Preprocessing: O(m)
-Searching: O(n)
-Overall: O(m + n)
(where m = length of pattern, n = length of text)

2.Rabin–Karp Fingerprinting Algorithm
-
-Uses a hash function to compute a numeric value (fingerprint) for the pattern and substrings of the text.
-If the hash values match, a direct comparison is made to confirm the match.
-Ideal for multiple pattern searches.

Time Complexity:
-
-Average case: O(n + m)
-Worst case: O(nm) (if many hash collisions occur)

Algorithm Steps
-
Knuth–Morris–Pratt (KMP)
-
1.Compute the LPS array for the pattern.
2.Compare characters of the text and pattern.
3.If mismatch occurs, shift the pattern based on LPS value (no re-checking of previous characters).
4.Continue until the pattern is found or text ends.

Rabin–Karp
-
1.Compute hash value for the pattern and the first substring of text.
2.Slide the window by one character at a time and update the hash using the rolling hash formula.
3.If hash values match, compare the actual strings to confirm.
4.Continue until all matches are found.

Example
-
Input
Enter the text: ABABDABACDABABCABAB
Enter the pattern: ABABCABAB

Output
--- Knuth-Morris-Pratt (KMP) Algorithm ---
Pattern found at index 10

--- Rabin-Karp Fingerprinting Algorithm ---
Pattern found at index 10

Result
-
Both the KMP and Rabin–Karp algorithms successfully locate the pattern in the given text efficiently.
