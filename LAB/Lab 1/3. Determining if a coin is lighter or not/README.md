# Defective Coin Finder – Divide & Conquer Using Simulated Balance Scale

This program identifies a **single defective (lighter) coin** from a collection of coins using a **divide-and-conquer algorithm**.  
It simulates a physical **balance scale** that compares the weight of two groups, recursively narrowing down the location of the defective coin.

---

## 📌 Overview

The program:

- Uses a **simulated weighing scale** that compares the total weights of two groups.
- Applies **divide & conquer** to repeatedly cut the search space in half.
- Isolates the suspected defective coin.
- Performs a **verification step** to ensure correctness.
- Works for **any number of coins**, as long as at most one coin is defective and lighter.

This approach models classic algorithmic puzzles and introduces recursive problem-solving strategies.

---

## 📌 Key Features

- **Divide & Conquer Logic**  
  Efficiently narrows the search from *n* coins to *1* in only *O(log n)* comparisons.

- **Balance Scale Simulation**  
  The `weigh()` function mimics a real balance scale:
  - returns which side is lighter
  - or if both sides are equal

- **Verification Step**  
  Confirms the candidate coin by comparing it with a known good coin.

- **Dynamic User Input**  
  Works for any `n`, with arbitrary coin weights.

---

## 📌 Function Documentation

### 1️⃣ `weigh()`

```c
int weigh(int coins[], int a_start, int b_start, int len);
```

**Purpose:**  
Simulates weighing two equal-sized groups of coins.

**Parameters:**
- `coins[]` – array of coin weights  
- `a_start` – start index of group A  
- `b_start` – start index of group B  
- `len` – number of coins in each group  

**Returns:**
- `-1` → Group A is lighter  
- ` 1` → Group B is lighter  
- ` 0` → Both groups weigh the same  

---

### 2️⃣ `findDefective()`

```c
int findDefective(int coins[], int start, int n);
```

**Purpose:**  
Recursively locates the defective (lighter) coin.

**Parameters:**
- `coins[]` – coin weights  
- `start` – starting index of the current segment  
- `n` – number of coins in the segment  

**Logic:**
1. Divide coins into two equal halves.  
2. Weigh both halves using `weigh()`.  
3. If one half is lighter → recurse into that half.  
4. If equal and one leftover coin exists → that leftover is checked.  
5. If equal and no leftover → no defective coin.

**Returns:**  
Index of the suspected coin (0-based), or `-1` if none found.

---

### 3️⃣ `verify()`

```c
int verify(int coins[], int n, int candidate);
```

**Purpose:**  
Confirms that the candidate coin is actually lighter.

**Parameters:**
- `coins[]` – coin weight array  
- `n` – number of coins  
- `candidate` – suspected defective index  

**Logic:**
- Compare candidate with the first known good coin (the first coin that is not the candidate).
- If candidate < good coin → confirmed.
- Else → not defective.

**Returns:**  
Confirmed defective index, or `-1` if verification fails.

---

### 4️⃣ `main()`

```c
int main();
```

**Program Flow:**

1. Read number of coins `n`.  
2. Allocate memory for coin weights.  
3. Input the weights from the user.  
4. Call `findDefective()` to get a candidate.  
5. Call `verify()` to confirm.  
6. Display the result.  

---

## 📊 Algorithm Complexity

| Operation              | Complexity |
|------------------------|-----------|
| **Time Complexity**    | O(log n)  |
| **Space Complexity**   | O(log n) (recursive stack) |

Efficient even for very large `n`.

---

## 📝 Sample Input/Output

### **Input 1**
```
Enter number of coins: 5
Enter weights of 5 coins:
10 10 9 10 10
```

### **Output 1**
```
Defective (lighter) coin is at position 2 (0-based index).
```

---

### **Input 2**
```
Enter number of coins: 4
Enter weights of 4 coins:
10 10 10 10
```

### **Output 2**
```
No defective coin found. All coins are perfect.
```

---

## 🎯 Applications

- Fault detection in manufacturing systems  
- Identifying defective components in hardware  
- Puzzle-solving & competitive programming  
- Teaching **divide and conquer**, recursion, and algorithm analysis  

---

## ✅ Conclusion

This program provides a clean and efficient implementation of the classic **defective coin problem** using:

- recursive divide & conquer  
- simulated weighing  
- verification for correctness  

It is an excellent demonstration of how algorithmic thinking can drastically reduce problem complexity.

