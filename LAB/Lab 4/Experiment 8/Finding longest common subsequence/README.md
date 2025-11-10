Longest Common Subsequence (LCS) and All Common Subsequences
=
Overview
-
This program finds:
1.The Longest Common Subsequence (LCS) between two strings.
2.All possible unique common subsequences between the two strings (avoiding duplicates).

The program uses Dynamic Programming (DP) to compute the LCS and recursion to explore all possible common subsequences.

Algorithm Used
-
1.Longest Common Subsequence (LCS)
-
-The LCS problem is solved using Dynamic Programming.
-A 2D array dp[m+1][n+1] is built, where m and n are the lengths of the two input strings.
-The recurrence relation is:
if (X[i-1] == Y[j-1])
    dp[i][j] = 1 + dp[i-1][j-1];
else
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

-The final LCS length is stored in dp[m][n].

2.Printing One LCS
-
-Starting from the bottom-right of the DP table, we backtrack:
    -If characters match, include them in the LCS string.
    -Otherwise, move toward the larger DP value.

3.Finding All Common Subsequences
-
-A recursive approach explores all possible subsequences that are common between the two strings.
-Each subsequence is stored only if it is unique, preventing duplicates.

Program Structure
-
Function	                                         Description
LCSLength()	                      Builds the DP table and returns the LCS length.
printLCS()	                     Extracts and prints one LCS from the DP table.
allCommonSubsequences()	      Recursively generates all possible common subsequences.
isDuplicate()	                  Ensures each subsequence is unique before printing.

Key Concepts
-
-Dynamic Programming (DP) for efficient LCS computation
-Backtracking to reconstruct one LCS
-Recursion to find all subsequences
-Duplicate elimination using string comparison

Complexity Analysis
-
Operation	                         Time Complexity	       Space Complexity
Finding LCS	                          O(m × n)	               O(m × n)
Printing LCS	                        O(m + n)	                 O(1)
Finding All Common Subsequences	    Exponential	        O(Number of subsequences)
