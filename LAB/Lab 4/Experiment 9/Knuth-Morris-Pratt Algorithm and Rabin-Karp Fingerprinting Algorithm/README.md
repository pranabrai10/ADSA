# KMP and Rabin–Karp String Matching Algorithms – C Implementation

This code implements two efficient pattern-searching algorithms:

1. **Knuth–Morris–Pratt (KMP) Algorithm**  
2. **Rabin–Karp Fingerprinting Algorithm**

Both are designed to locate occurrences of a pattern within a text while avoiding unnecessary character comparisons.

---

## 📌 Aim

To implement fast and efficient string matching using KMP and Rabin–Karp algorithms.

---

## 📌 Objective

- Efficiently search for pattern occurrences inside a text  
- Reduce redundant comparisons found in naive matching  
- Demonstrate two different optimization techniques:  
  - Prefix-based skipping (KMP)  
  - Rolling hash (Rabin–Karp)

---

## 📌 1. Knuth–Morris–Pratt (KMP) Algorithm

KMP avoids re-checking characters by preprocessing the pattern.

### 🔹 Key Idea
Build an **LPS (Longest Prefix-Suffix)** array indicating the longest proper prefix that is also a suffix.  
This allows skipping ahead on mismatches without repeating comparisons.

### 🔹 Complexity
| Phase | Time |
|-------|------|
| Preprocessing LPS | O(m) |
| Pattern Searching | O(n) |
| **Total** | **O(n + m)** |

Where:

- **m** = pattern length  
- **n** = text length  

---

## 📌 2. Rabin–Karp Fingerprinting Algorithm

Uses hashing to compare numeric fingerprints rather than characters.

### 🔹 Key Idea
- Compute hash for the pattern  
- Compute rolling hash for each window of the text  
- If hash matches → verify by character comparison  

Useful for **multiple pattern matching**.

### 🔹 Complexity
| Case | Time |
|-------|-------|
| Average-case | O(n + m) |
| Worst-case | O(nm) (when collisions occur) |

---

## 📌 Algorithm Steps

### 🔹 Knuth–Morris–Pratt (KMP)
1. Build the **LPS array**  
2. Compare pattern with text  
3. On mismatch → use LPS to shift pattern without rechecking  
4. Continue until pattern is found or text ends  

---

### 🔹 Rabin–Karp
1. Compute initial hash of pattern and first window of text  
2. Slide window one step at a time  
3. Update hash using rolling hash formula  
4. If hash matches → verify substring  
5. Continue scanning to find all matches  

---

## 📌 Example

### **Input**
```
Enter the text: ABABDABACDABABCABAB
Enter the pattern: ABABCABAB
```

### **Output**
```
--- Knuth-Morris-Pratt (KMP) Algorithm ---
Pattern found at index 10

--- Rabin-Karp Fingerprinting Algorithm ---
Pattern found at index 10
```

---

## 📌 Result

Both KMP and Rabin–Karp efficiently locate the pattern in the given text.  
Each algorithm uses a different strategy:

- **KMP** → avoids redundant comparisons using LPS  
- **Rabin–Karp** → speeds up matching using rolling hash  

Together, they demonstrate two classic approaches to fast string matching.

