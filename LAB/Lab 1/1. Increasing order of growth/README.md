# Asymptotic Growth Rate Comparison (C Program)

This program compares the **asymptotic growth rates** of multiple mathematical functions commonly used in algorithm analysis.  
It evaluates all functions at a large input size **n**, groups Θ-equivalent ones, and prints their relative growth order.

---

## 📌 1. Objective

This program is designed to:

- Compare the asymptotic growth of 12 different mathematical functions  
- Group functions that are **Θ-equivalent**  
- Display the **relative growth order** of all functions for a large input \(n\)  
- Provide an empirical demonstration of complexity classes  

---

## 📌 2. Included Libraries

```c
#include <stdio.h>    // For input/output
#include <math.h>     // For log2(), sqrt(), pow()
#include <string.h>   // For storing function names
```

---

## 📌 3. Constants and Macros

```c
#define NUM_FUNCS 12   // Number of functions compared
#define MAX_NAME 50    // Max name length
#define MAX_N 1024     // Evaluation point for growth comparison
```

- `NUM_FUNCS` → size of the function array  
- `MAX_N` → the value of n at which all functions are evaluated (larger n gives more accurate asymptotic behavior)

---

## 📌 4. Data Structure

```c
typedef struct {
    char name[MAX_NAME];     // Name of the function
    double (*func)(double);  // Pointer to function implementation
    double value;            // Computed value at n = MAX_N
} Function;
```

Each entry stores:

- function name  
- pointer to corresponding mathematical function  
- computed result at \(n = 1024\)

---

## 📌 5. Mathematical Functions Implemented

| Function | Code | Complexity |
|---------|------|------------|
| \(1/n\) | `f_inv` | inverse function |
| \(\log_2 n\) | `f_log2` | logarithmic |
| \(n \log_2 n\) | `f_nlogn` | n log n |
| \(12\sqrt{n}\) | `f_12sqrt` | root growth |
| \(50\sqrt{n}\) | `f_50sqrt` | same Θ-class as above |
| \(n^{0.51}\) | `f_n051` | sublinear polynomial |
| \(n^2 - 324\) | `f_n2minus324` | quadratic |
| \(100n^2 + 6n\) | `f_100n2plus6n` | quadratic |
| \(2n^3\) | `f_2n3` | cubic |
| \(2^{32} n\) | `f_2pow32n` | large constant × n |
| \(n^{\log_2 n}\) | `f_nlog2n` | super-polynomial |
| \(3^n\) | `f_3n` | exponential |

---

## 📌 6. Main Program Logic

### 🔹 Step 1 — Initialization

All functions and their names stored in an array:

```c
Function funcs[NUM_FUNCS] = {
    {"1/n", f_inv, 0},
    {"log2(n)", f_log2, 0},
    ...
};
```

---

### 🔹 Step 2 — Evaluate Functions at n = 1024

```c
double n = MAX_N;
for (int i = 0; i < NUM_FUNCS; i++) {
    funcs[i].value = funcs[i].func(n);
}
```

This gives actual numeric values to compare asymptotic behavior.

---

### 🔹 Step 3 — Θ-Equivalence Grouping

Two functions are considered Θ-equivalent if:

```
0.5 < (value_i / value_j) < 2.0
```

Grouping code:

```c
if (ratio > 0.5 && ratio < 2.0) {
    grouped[j] = 1;
}
```

---

### 🔹 Step 4 — Sort Functions by Growth

A simple bubble-sort arranges functions from smallest to largest value:

```
1/n  <  log2(n)  <  sqrt(n)  <  ...  <  3^n
```

---

### 🔹 Step 5 — Print Growth Order

Produces an ordered chain:

```
1/n < log2(n) < 12*sqrt(n) < ... < 3^n
```

---

## 📌 7. Sample Output (n = 1024)

### Θ-equivalent groups

```
{ 12*sqrt(n), 50*sqrt(n) }
{ n^2 - 324, 100n^2 + 6n }
```

### Asymptotic growth order

```
1/n < log2(n) < 12*sqrt(n) < 50*sqrt(n) < n^0.51 < n*log2(n)
< n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32*n < n^log2(n) < 3^n
```

---

## 📌 8. Key Observations

- Functions that differ only by constant factors fall into the same Θ group.  
- Logarithmic, polynomial, super-polynomial, and exponential functions all grow at very different rates.  
- Exponential functions such as \(3^n\) dominate all others.  
- Polynomial differences like \(n^2 - 324\) vs. \(100n^2 + 6n\) do **not** change asymptotic class.  

---

## 📌 9. Graphing Support

The program can optionally generate graphs using **gnuplot** to visualize growth differences.

Example usage:

```
gnuplot> plot "data.txt" using 1:2 with lines
```

---

## 📌 Conclusion

This program provides:

- A clear demonstration of how different complexity functions behave  
- Empirical Θ-grouping using numerical ratios  
- A sorted ranking of asymptotic growth rates  
- Practical insight into why certain algorithms scale better than others  

It is a valuable educational tool for understanding algorithmic complexity and Big-O analysis.

