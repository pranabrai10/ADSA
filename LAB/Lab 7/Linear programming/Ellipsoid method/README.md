Ellipsoid Method
=
Overview
-
This program implements the Ellipsoid Algorithm, a geometric method used to test whether a Linear Programming (LP) system is feasible.
The goal is to find a point x such that:
    Ax≤b

The ellipsoid algorithm works by repeatedly shrinking an ellipsoid that contains the feasible region until a feasible point is found (or until the ellipsoid becomes too small).

Objective
-
To provide a simple C implementation that checks LP feasibility using the ellipsoid method by:

-Starting with a large ellipsoid that contains the solution
-Identifying a violated constraint
-Cutting the ellipsoid using a separating hyperplane
-Updating the ellipsoid’s center and shape
-Repeating until feasibility is detected

This code focuses on learning, not industrial-scale optimization.

Concept
-
The ellipsoid method maintains an ellipsoid:

E={x:(x−c)^TH^(−1)(x−c)≤1}

where:
-c = center
-H = shape matrix

Each iteration:

-Check whether the current center c satisfies all constraints.
-If a constraint is violated, use it as a separating hyperplane.
-Update the ellipsoid by:
    -Moving the center
    -Shrinking the ellipsoid using a mathematical update rule

The feasible region is guaranteed to remain inside the new ellipsoid.

The algorithm terminates when:
-A feasible point is found, or
-The maximum number of iterations is reached.

Major Components
-
1. Feasibility Check

For each constraint (ai)^Tx≤bi, compute:

    (ai)^Tx−bi

The constraint with the largest violation is used to cut the ellipsoid.

2. Separating Hyperplane

The violated constraint defines a direction a, which is normalized using:

g=a/(sqrt{(a^THa)​})

This ensures correct scaling relative to the ellipsoid geometry.

3. Center Update

The center moves opposite to the violated direction:

x′=x−(1/(n+1))Hg

This shifts the ellipsoid toward the feasible region.

4. Shape Matrix Update

The ellipsoid shrinks according to:

H′=(n^2/((n^2)-1))(H−(2/(n+1)Hgg^TH)

This ensures the new ellipsoid still contains the feasible region.

Algorithm Steps
-
1.Input matrix A and vector b.
2.Choose initial radius R and set:
    -center = 0
    -shape = (R^2)I (ball of radius R)
3.Test feasibility of the center.
4.If violated:
    -Compute separating hyperplane
    -Update center
    -Update ellipsoid shape
5.Repeat for up to MAX_ITERS iterations.
6.If a feasible point is found, print it.

Data Structures Used
-
-2D array for matrix A
-1D arrays for vectors x, b, g, and temporary computations
-2D arrays for H (shape matrix) and newH
-Basic floating-point operations and linear algebra

Advantages
-
-Works for any LP feasibility check Ax≤b
-Does not require simplex tableaux
-Always stays inside a bounding ellipsoid
-Guarantees polynomial-time complexity (theoretical)
-Good educational example of convex optimization

Limitations
-
-Slow in practice compared to Simplex or Interior Point Methods
-Sensitive to numerical precision
-Requires initial bounding radius R
-Feasible region must be bounded inside the initial ellipsoid
-Only checks feasibility, does not optimize an objective function
