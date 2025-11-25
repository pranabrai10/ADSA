# Ellipsoid Method – C Implementation

This code implements the **Ellipsoid Algorithm**, a geometric iterative method used to test the **feasibility** of a Linear Programming (LP) system of inequalities:

\[
Ax \le b
\]

The ellipsoid method shrinks an enclosing ellipsoid step-by-step until either:

- A feasible point is found, or  
- The ellipsoid becomes too small (maximum iterations reached)

This implementation focuses on **education and understanding**, not industrial-scale optimization.

---

## 📌 Features

### ✔ User-Level Capability
| Operation | Description |
|-----------|-------------|
| **LP Feasibility Check** | Determines whether there exists an \( x \) such that \( Ax \le b \) |
| **Iterative Ellipsoid Updates** | Adjusts center and shape matrix each iteration |
| **Constraint Violation Detection** | Identifies most violated constraint |
| **Progress Logging** | Shows iteration updates and feasibility results |

---

## 📌 Concept Overview

The ellipsoid method maintains an ellipsoid:

\[
E = \{ x \mid (x - c)^T H^{-1} (x - c) \le 1 \}
\]

Where:

- **\( c \)** = center  
- **\( H \)** = shape matrix (positive definite)

### Each iteration:

1. Check if the center satisfies all constraints.  
2. If a constraint \( a_i^T x \le b_i \) is violated:
   - Compute the separating hyperplane direction  
   - Update the ellipsoid center  
   - Update the shape matrix  
3. Continue until feasibility or until iteration limit reaches.

---

## 📌 Major Components

### 🔹 1. Constraint Feasibility Check
For each inequality:

\[
a_i^T x - b_i
\]

The algorithm picks the **most violated constraint** and cuts the ellipsoid with it.

---

### 🔹 2. Separating Hyperplane
From the violated constraint, compute vector:

\[
g = \frac{a}{\sqrt{a^T H a}}
\]

This normalizes the inequality relative to the ellipsoid geometry.

---

### 🔹 3. Center Update
Move the ellipsoid center in the opposite direction of violation:

\[
x' = x - \frac{1}{n+1} H g
\]

This ensures the new center moves toward the feasible region.

---

### 🔹 4. Shape Matrix Update
Shrink the ellipsoid:

\[
H' = \frac{n^2}{n^2 - 1} \left( H - \frac{2}{n+1} Hg g^T H \right)
\]

This guarantees the new ellipsoid still contains the feasible region.

---

## 📌 Algorithm Steps

1. Input matrix **A** and vector **b**  
2. Choose initial radius **R**  
3. Initialize:
   - **center = 0**  
   - **shape = (R²)I** (ball of radius R)  
4. Check whether center satisfies **Ax ≤ b**  
5. If violated:
   - Compute separating hyperplane  
   - Update center  
   - Update shape matrix  
6. Repeat for **MAX_ITERS**  
7. Output feasible point if found

---

## 📌 Data Structures Used

| Component | Structure |
|-----------|-----------|
| Matrix A | 2D array |
| Vector b | 1D array |
| Ellipsoid center | 1D array |
| Gradient direction \( g \) | 1D array |
| Shape matrix \( H \) | 2D array |
| New shape matrix \( H' \) | 2D array |
| Temporary arrays | 1D/2D floats |

Basic floating-point linear algebra is used throughout.

---

## 📌 Advantages

- Works for **any LP feasibility check** \( Ax \le b \)  
- Does not require simplex or interior-point machinery  
- Operates entirely inside a bounding ellipsoid  
- Theoretically **polynomial time**  
- Excellent educational example for convex optimization  

---

## 📌 Limitations

- Slower in practice than Simplex or Interior Point methods  
- Sensitive to floating-point numerical stability  
- Requires a **correct bounding ellipsoid radius**  
- Feasible region must lie inside the initial ellipsoid  
- Only checks **feasibility**, does *not* optimize an objective function  

