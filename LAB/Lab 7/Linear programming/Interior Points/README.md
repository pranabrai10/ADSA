# Interior Point Method – C Implementation (Barrier Method)

This code implements a **minimal educational version** of the **Interior Point Method (IPM)** for solving simple linear optimization problems.  
Specifically, it uses the **Logarithmic Barrier Method**, which approaches the optimal solution from **inside** the feasible region.

Unlike the Simplex Method (which walks along the edges), Interior Point Methods follow a smooth trajectory called the **central path**.

This implementation supports:
- A **single equality constraint**
- A strictly positive feasible starting point
- Newton-based updates for following the barrier path

Designed for **learning**, not industrial-scale optimization.

---

## 📌 Features

### ✔ Core Capabilities
| Feature | Description |
|---------|-------------|
| **Linear Objective Optimization** | Minimizes or maximizes \( c^T x \) |
| **Log-Barrier Function** | Ensures all \( x_i > 0 \) |
| **Newton Direction Computation** | Solves for step direction |
| **Adaptive Step Size** | Maintains strict positivity |
| **Equality Constraint Projection** | Preserves feasibility |
| **Barrier Parameter Update** | Drives the solution toward optimality |

---

## 📌 Concept Overview

Interior Point Methods approximate the original objective using a **barrier-augmented function**:

\[
\phi(x) = c^T x - t \sum_i \ln(x_i)
\]

Where:

- \( c^T x \) → original objective  
- \( -t \ln(x_i) \) → barrier preventing \( x_i \le 0 \)  
- \( t \) → barrier parameter, increased over time  

As \( t \rightarrow \infty \), \( \phi(x) \) approaches the true objective while keeping iterates strictly inside the positive orthant.

---

## 📌 Key Ideas

- Start with a **strictly positive** feasible point  
- Compute gradient + Hessian of the barrier function  
- Solve the Newton system to obtain a search direction  
- Choose a step size that keeps **all variables positive**  
- Apply a correction to satisfy the equality constraint  
- Increase the barrier parameter  
- Repeat until convergence  

This simple variant demonstrates the essential mechanics of IPMs.

---

## 📌 Major Components

### 🔹 1. Gradient Calculation
For each variable:

\[
g_i = c_i - \frac{t}{x_i}
\]

Used in Newton’s method.

---

### 🔹 2. Hessian Matrix
Diagonal matrix:

\[
H_{ii} = \frac{t}{x_i^2}
\]

Represents curvature of the barrier term.

---

### 🔹 3. Newton Direction
Solve the system:

\[
H \, \Delta x = -g
\]

The implementation uses **Gaussian elimination** for simplicity.

---

### 🔹 4. Step Size Rule
Ensure the step keeps all variables strictly positive:

\[
x_i + \alpha \Delta x_i > 0
\]

The program uses a safety factor **0.9** to prevent boundary violations.

---

### 🔹 5. Equality Constraint Correction
For the single equality constraint:

\[
A x = b
\]

The correction step:

- Computes constraint residual  
- Distributes adjustment evenly across all variables  
- Ensures next iterate satisfies the equality  

Simple and effective for demonstration.

---

## 📌 Algorithm Steps

1. Read number of variables and the single equality constraint  
2. Input:
   - Objective vector \( c \)  
   - Constraint row \( A \)  
   - RHS \( b \)  
3. Choose a **strictly positive feasible** starting point \( x_0 \)  
4. Compute:
   - Gradient  
   - Hessian  
5. Solve Newton system for search direction \( \Delta x \)  
6. Compute safe step size \( \alpha \)  
7. Update:
   \[
   x \leftarrow x + \alpha \Delta x
   \]
8. Project to satisfy equality constraint  
9. Increase barrier parameter \( t \)  
10. Repeat until gradient norm < tolerance  

---

## 📌 Data Structures Used

- Arrays for:
  - Objective vector  
  - Constraint vector  
  - Current point  
  - Gradient  
  - Newton direction  
- 2D array for Hessian  
- Gaussian elimination routine for solving linear systems  

---

## 📌 Advantages

- Simple and easy to understand  
- Demonstrates the core principles of Interior Point Methods  
- Ensures variables remain strictly positive  
- No external math libraries needed  
- Great for small, educational demonstrations  

---

## 📌 Limitations

- Supports **only one equality constraint**  
- No inequality constraints  
- Not a full IPM (no KKT matrix or full Newton system)  
- Not suitable for real-world optimization problems  
- Basic Gaussian elimination may suffer from numerical issues  
- Requires a feasible positive starting point  

