# KMP String Search – C Implementation

This code provides a clean, efficient, and fully documented implementation of the **Knuth–Morris–Pratt (KMP)** String Searching Algorithm in **C**.

KMP finds all occurrences of a pattern string `P` inside a text string `T` in:

- **O(n + m)** time  
- where *n* = length of the text, and *m* = length of the pattern  

The algorithm avoids redundant comparisons by using prefix information from the pattern itself.

---

## 📌 Features

### ✔ Core Operations
| Feature | Description |
|---------|-------------|
| **LPS Array Construction** | Builds the longest-prefix-suffix table for the pattern |
| **KMP Search** | Efficiently finds all matches in O(n+m) time |
| **Multiple Occurrence Detection** | Prints ALL match positions |
| **Safe Input Handling** | Uses `fgets()` for robust string input |
| **Readable Implementation** | Clean functions: `computeLPS()` and `KMPSearch()` |

---

## 📌 File Structure

```
KMP/
│
├── code.c         # Full KMP implementation
├── README.md     # Documentation (this file)
├── input
└── ouput
```

---

## 📌 Compilation

Use GCC or any C compiler:

```bash
gcc code.c -o kmp
```
---

## 📌 Running the Program

```bash
./code
```

The program will prompt for:

```
Enter the text:
Enter the pattern:
```

---

## 📌 Example

### **Input**
```
Enter the text: ABABABACABA
Enter the pattern: ABABAC
```

### **Output**
```
Pattern found at positions: 2
```

Positions are **0-based**.  
(For 1-based indexing, simply print position + 1.)

---

## 📌 How the KMP Algorithm Works

### Step 1 — Build LPS Array
`lps[i]` = length of longest prefix of pattern `P` that is also a suffix of `P[0..i]`.

Example:  
Pattern `"ABABAC"`  
LPS → `[0,0,1,2,3,0]`

### Step 2 — Search the Pattern
Use two indices:

- `i`: text index  
- `j`: pattern index  

Rules:
- If characters match → advance both `i` and `j`
- If mismatch and `j != 0` → jump pattern index using LPS (`j = lps[j-1]`)
- If mismatch and `j == 0` → move text index only (`i++`)
- If `j == m` → full match found → record `i - j` → continue using LPS

This guarantees **linear time** because the algorithm never rechecks characters.

---

## 📌 Complexity

| Operation | Complexity |
|-----------|------------|
| LPS construction | **O(m)** |
| Pattern search | **O(n)** |
| Total | **O(n + m)** |
| Extra space | **O(m)** |

---

