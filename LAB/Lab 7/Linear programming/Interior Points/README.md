Interior Point Method for Linear Optimization
=
Overview
-
This program implements a very simple version of the Interior Point Method (IPM), specifically the Barrier Method, to solve linear optimization problems.
Interior Point Methods approach the optimal solution from the inside of the feasible region, unlike the Simplex Method which moves along the boundary.

This version supports one equality constraint and ensures all variables remain strictly positive during the optimization process.

Objective
-
To demonstrate a minimal, easy-to-understand implementation of the Interior Point Method that:

-Maximizes or minimizes a linear objective function
-Maintains strictly positive variables
-Uses Newton steps to follow the central path
-Updates the barrier parameter to move toward optimality

Concept
-
Interior Point Methods reformulate a constrained optimization problem using a logarithmic barrier:

Minimize: ϕ(x) = cTx −t∑ln(xi)
                       i
Here:

-c^Tx → original objective
-−tln(xi) → barrier term that prevents entering negative region
-t increases to gradually reduce the effect of the barrier

The algorithm uses Newton's Method to iteratively move closer to the optimal solution while staying inside the feasible region.

Key ideas:
-
-Start with a strictly positive point that satisfies the equality constraint
-Compute gradient and Hessian of the barrier function
-Solve the Newton system
-Take a step that keeps all variables positive
-Project back to satisfy the equality constraint
-Increase the barrier parameter
-Repeat until convergence

Major Components
-
1. Gradient Calculation

Computes:

gi=ci−t/xi​

This is the gradient of the barrier-augmented objective.

2. Hessian Matrix

A diagonal matrix:

Hii=t/(xi)^2

Used in Newton’s method to compute the search direction.

3. Newton Direction

Solves:

Hdx=−g

(using Gaussian elimination in the code)

Produces the direction that improves the current point.

4. Step Size Rule

Ensures:

xi+αdxi>0

A conservative 0.9 safety margin is used to keep the iterate strictly inside the feasible region.

5. Equality Constraint Correction

Since this version supports one equality constraint, the correction is applied as:

-Compute the constraint residual
-Distribute the adjustment equally among all variables

Simple and effective for demonstration.

Algorithm Steps
-
1.Read number of variables and constraint.
2.Input objective vector c, constraint vector A, and RHS b.
3.Start from a positive feasible point x0
4.Compute gradient and Hessian.
5.Solve Newton system for direction dx.
6.Choose step size to keep variables positive.
7.Update x←x+αdx.
8.Project to satisfy equality constraint.
9.Increase barrier parameter t.

10.Repeat until gradient norm < tolerance.

Data Structures Used
-
-Arrays for:
  Objective vector
  Constraint row
  Gradient
  Newton direction
-2D array for Hessian matrix
-Gaussian elimination for solving linear systems

Advantages
-
-Simple and easy to understand
-Illustrates core ideas of Interior Point Methods
-Ensures all variables stay positive
-No external libraries required
-Useful for small educational examples

Limitations
-
-Supports only one equality constraint
-No inequality constraints
-Not a full IPM / no KKT system
-Not suitable for real optimization problems
-Uses basic Gaussian elimination (not numerically robust)
-Must provide a positive feasible starting point
