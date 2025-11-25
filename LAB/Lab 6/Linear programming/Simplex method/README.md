# Simplex Method – Linear Programming Optimization (C Implementation)

This code implements the **Simplex Method**, one of the most widely used algorithms in **Linear Programming (LP)** for optimizing linear objective functions subject to linear constraints.

The algorithm transforms the LP into a **simplex tableau** and iteratively moves toward the optimal solution by improving the objective value at each step.

This implementation focuses on **maximization problems** with:
- “≤” type constraints  
- Non-negative variables  

Designed for clarity and educational understanding.

---

## 📌 Features

### ✔ Core Capabilities
| Feature | Description |
|---------|-------------|
| **Slack Variable Support** | Converts ≤ constraints into equalities |
| **Simplex Tableau Construction** | Full tableau for LP representation |
| **Entering Variable Selection** | Finds variable that improves objective |
| **Leaving Variable Selection** | Uses minimum ratio test |
| **Pivot Operation** | Updates tableau to next feasible solution |
| **Iterative Improvement** | Repeats until optimality is reached |

---

## 📌 Concept Overview

The Simplex Method improves a feasible solution **step by step** by moving along the edges of the feasible region.

### Key Ideas:
- Convert inequalities to equalities using **slack variables**
- Represent the full system in a **simplex tableau**
- Choose a variable to **enter** (improve the objective)
- Choose a variable to **leave** (maintain feasibility)
- Apply a **pivot operation** to update the tableau
- Stop when no further improvement is possible

This process guarantees the optimal solution (if it exists) for feasible LPs.

---

## 📌 Major Components

### 🔹 1. Slack Variables  
Each “≤” constraint becomes an equality.

Example:  
\[
x_1 + 2x_2 \le 14 
\quad\Rightarrow\quad 
x_1 + 2x_2 + s_1 = 14
\]

Slack variables form an identity matrix inside the tableau.

---

### 🔹 2. Simplex Tableau  
A structured 2D matrix containing:

- Coefficients of variables  
- Slack variable columns  
- Right-hand side (RHS) values  
- Objective function row (Z-row)

This tableau is updated at every iteration.

---

### 🔹 3. Entering Variable (Pivot Column)
Select the **most negative** coefficient in the Z-row.  
This direction improves the objective value.

---

### 🔹 4. Leaving Variable (Pivot Row)
Use the **minimum ratio test**:

\[
\text{ratio} = \frac{\text{RHS}}{\text{pivot column value}}
\]

Ensures the solution remains feasible.

---

### 🔹 5. Pivot Operation
Once pivot row and column are identified:

1. Divide pivot row by pivot element  
2. Eliminate pivot column values from all other rows  
3. Update basis variables  

This moves the solution to an adjacent extreme point.

---

## 📌 Algorithm Steps

1. Input:
   - Number of decision variables  
   - Number of constraints  

2. Construct the initial simplex tableau  
3. Identify the **entering variable** (most negative Z-row coefficient)  
4. Perform **minimum ratio test** to choose the leaving variable  
5. Apply **pivot operation**  
6. Repeat Steps 3–5 until Z-row has no negative values  
7. Read optimal solution from final tableau  

---

## 📌 Data Structures Used

- **2D array** → simplex tableau  
- **Array of basic variables** → tracks which variables are in the basis  
- **Array for ratios** → used in minimum ratio test  
- **Scalars** → pivot element, pivot row/column indices  

---

## 📌 Advantages

- Very simple and easy to understand  
- Shows each iteration clearly → great for learning  
- Guaranteed optimal solution for feasible maximization problems  
- Suitable for small LP examples  
- No advanced libraries required  

---

## 📌 Limitations

- Supports only **maximization** problems  
- Works only with **≤ constraints**  
- Does **not** handle ≥, = constraints requiring artificial variables  
- Not suitable for large-scale industrial LP problems  
- Floating-point arithmetic may introduce minor numerical errors  

