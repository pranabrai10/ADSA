# Longest Common Subsequence (LCS) & All Common Subsequences – C Implementation

This code implements:

1. **The Longest Common Subsequence (LCS)** between two strings using Dynamic Programming  
2. **All unique common subsequences** between the strings using recursion  

The program ensures **no duplicate subsequences** and demonstrates both DP and recursive backtracking techniques.

---

## 📌 Overview

Given two strings **X** and **Y**, the program:

- Computes the **length** of their LCS  
- Prints **one valid LCS** by backtracking through the DP table  
- Recursively finds **all possible unique common subsequences**  

This provides both an optimal subsequence and a complete view of all matches.

---

## 📌 Algorithms Used

### 🔹 1. Longest Common Subsequence (LCS) — Dynamic Programming

A DP table `dp[m+1][n+1]` is built where:

- **m** = length of string X  
- **n** = length of string Y  

Recurrence relation:

```
if (X[i-1] == Y[j-1])
    dp[i][j] = 1 + dp[i-1][j-1];
else
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
```

Final answer:  
`dp[m][n]` gives the **LCS length**.

---

### 🔹 2. Printing One LCS — Backtracking

Starting at `dp[m][n]`:

- If characters match → include character and move diagonally  
- If not → move in the direction of the larger dp value  

This reconstructs one valid LCS string.

---

### 🔹 3. Finding All Common Subsequences — Recursion

A recursive function:

- Explores all subsequences  
- Records only subsequences present in **both X and Y**  
- Stores subsequences uniquely  

Duplicates are avoided using a comparison function.

---

## 📌 Program Structure

| Function | Description |
|----------|-------------|
| **LCSLength()** | Fills DP table and returns LCS length |
| **printLCS()** | Backtracks through DP table to print one LCS |
| **allCommonSubsequences()** | Recursively generates all common subsequences |
| **isDuplicate()** | Ensures subsequences are printed only once |

---

## 📌 Key Concepts

- **Dynamic Programming** for LCS length and table construction  
- **Backtracking** to retrieve one optimal LCS  
- **Recursion** to generate all subsequences  
- **Duplicate Removal** to ensure unique output  

This combination highlights the contrast between polynomial and exponential algorithms within the same problem domain.

---

## 📌 Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| **Finding LCS** | O(m × n) | O(m × n) |
| **Printing one LCS** | O(m + n) | O(1) |
| **Finding all common subsequences** | Exponential | O(#subsequences) |

Note:  
Finding all subsequences is inherently exponential due to the nature of string subsequences.

---

## 📌 Conclusion

This program demonstrates two important problem-solving techniques:

- **Efficient LCS calculation using DP**  
- **Exhaustive recursive enumeration** of all common subsequences  

It provides a full understanding of subsequence analysis — from optimal solutions to complete enumeration.

