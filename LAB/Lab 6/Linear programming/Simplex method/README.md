Simplex Method – Linear Programming Optimization
Overview
=
This project implements the Simplex Method, a fundamental algorithm used in Linear Programming to find the optimal solution of a linear objective function subject to linear constraints.
The algorithm works by converting the LP problem into a tableau and iteratively improving the solution until the maximum value of the objective function is reached.

Objective
-
To provide a simple and clear C implementation of the Simplex Algorithm for solving maximization problems with “≤” type constraints and non-negative variables.

Concept
-
The Simplex Method operates on the idea of improving an initial feasible solution step by step.

Each inequality constraint is converted into an equality by adding slack variables.

The entire problem is represented in a simplex tableau.

The algorithm selects a variable to enter the solution and another to leave, using mathematical rules.

Pivot operations are applied to update the tableau and move to a better solution.

The process stops when no further improvement is possible.

This method guarantees finding the optimal solution if it exists.

Major Components
-
1. Slack Variables

Added to convert “≤” constraints into equalities.
Example:

x1 + 2x2 ≤ 14⇒x1 + 2x2 + s1=14

2. Simplex Tableau

A structured matrix containing:

Coefficients of decision variables

Slack variable columns

Right-hand side values (RHS)

Objective function row (Z-row)

Used for all Simplex calculations.

3. Entering Variable Selection

The entering variable is chosen as the most negative value in the objective row, indicating the direction of improvement.

4. Leaving Variable Selection

The leaving variable is determined by the minimum ratio test:

RHS÷pivot column value

Ensures the next solution remains feasible.

5. Pivot Operation

Divide the pivot row by the pivot value

Adjust other rows to make all other values in the pivot column zero

Update the basic variable column accordingly

Algorithm Steps
-
1.Input the number of variables and constraints.
2.Construct the initial simplex tableau.
3.Identify the entering variable (most negative coefficient in Z-row).
4.Perform the minimum ratio test to find the leaving variable.
5.Apply the pivot operation.
6.Repeat steps 3–5 until no negatives remain in the Z-row.
7.Read the optimal values from the final tableau.

Data Structures Used
-
-2D array for storing the simplex tableau
-Array of basic variables to track which variables are currently in the basis
-Array of ratios used during the minimum ratio test
-Simple integer and floating-point variables for pivot computation

Advantages
-
-Simple and easy to understand
-Shows each iteration clearly (educational)
-Guaranteed optimal solution for feasible maximization problems
-Good for small LP problems and learning the simplex technique

Limitations
-
-Supports only maximization problems
-Works only with ≤ constraints
-Cannot solve ≤ / ≥ / = constraints requiring artificial variables
-Not suitable for large-scale industrial LP problems

Numerical precision may cause minor floating-point errors
