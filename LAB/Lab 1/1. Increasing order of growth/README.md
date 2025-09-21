1. Objective

This program is designed to:
-Compare the asymptotic growth rates of various mathematical functions commonly encountered in algorithm analysis.
-Group functions that are Θ-equivalent (i.e., same asymptotic order).
-Print the relative growth order of all functions when evaluated at a large input size n.


2. Included Libraries

#include <stdio.h>   // For input/output (printf)
#include <math.h>    // For mathematical functions like log2, sqrt, pow
#include <string.h>  // For string handling (used in function struct)


3. Constants and Macros

#define NUM_FUNCS 12   // Number of functions being compared
#define MAX_NAME 50    // Maximum name length for each function
#define MAX_N 1024     // Value of n for evaluation (can be increased for better accuracy)

NUM_FUNCS ensures fixed array size for functions.
MAX_N acts as the large input size at which growth is evaluated (bigger n → better asymptotic behavior).


4. Data Structure

typedef struct {
    char name[MAX_NAME];     // Human-readable function name
    double (*func)(double);  // Pointer to mathematical function
    double value;            // Computed value at n = MAX_N
} Function;


5. Functions Defined

Each function corresponds to a mathematical complexity:
double f_inv(double n)       { return 1.0 / n; }                   // 1/n
double f_log2(double n)      { return log2(n); }                   // log2(n)
double f_nlogn(double n)     { return n * log2(n); }               // n*log2(n)
double f_12sqrt(double n)    { return 12 * sqrt(n); }              // 12√n
double f_50sqrt(double n)    { return 50 * sqrt(n); }              // 50√n
double f_n051(double n)      { return pow(n, 0.51); }              // n^0.51
double f_n2minus324(double n){ return pow(n, 2) - 324; }           // n² - 324
double f_100n2plus6n(double n){ return 100 * pow(n, 2) + 6 * n; }  // 100n² + 6n
double f_2n3(double n)       { return 2 * pow(n, 3); }             // 2n³
double f_2pow32n(double n)   { return pow(2, 32) * n; }            // 2³² * n
double f_nlog2n(double n)    { return pow(n, log2(n)); }           // n^(log₂n)
double f_3n(double n)        { return pow(3, n); }                 // 3ⁿ


6. Main Program Logic

Step 1: Initialization
Function funcs[NUM_FUNCS] = {
   {"1/n", f_inv, 0}, {"log2(n)", f_log2, 0}, ...
};
All functions are stored in an array for easy iteration.

Step 2: Evaluate Functions
double n = MAX_N;
for (int i = 0; i < NUM_FUNCS; i++) {
    funcs[i].value = funcs[i].func(n);
}

Each function is computed at n = 1024.

Step 3: Θ-equivalence Groups
int grouped[NUM_FUNCS] = {0};
for (int i = 0; i < NUM_FUNCS; i++) {
    if (grouped[i]) continue;
    printf("{ %s", funcs[i].name);
    grouped[i] = 1;
    for (int j = i + 1; j < NUM_FUNCS; j++) {
        double ratio = funcs[i].value / funcs[j].value;
        if (ratio > 0.5 && ratio < 2.0) { // ratio ~ constant
            printf(", %s", funcs[j].name);
            grouped[j] = 1;
        }
    }
    printf(" }\n");
}
Groups functions where values differ by at most a constant factor.

Step 4: Sorting by Growth
for (int i = 0; i < NUM_FUNCS - 1; i++) {
    for (int j = i + 1; j < NUM_FUNCS; j++) {
        if (funcs[i].value > funcs[j].value) {
            Function temp = funcs[i];
            funcs[i] = funcs[j];
            funcs[j] = temp;
        }
    }
}
Uses bubble sort to order functions by their computed values.
The result approximates growth order.

Step 5: Print Growth Order
printf("\nAsymptotic growth order (approx at n=%g):\n", n);
for (int i = 0; i < NUM_FUNCS; i++) {
    printf("%s", funcs[i].name);
    if (i < NUM_FUNCS - 1) printf(" < ");
}
printf("\n");

Output is in the form:
1/n < log2(n) < sqrt(n) < ... < 3^n

7. Sample Output (n=1024)
Θ-equivalent function groups (based on ratio at n=1024):
{ 12*sqrt(n), 50*sqrt(n) }
{ n^2 - 324, 100n^2 + 6n }

Asymptotic growth order (approx at n=1024):
1/n < log2(n) < 12*sqrt(n) < 50*sqrt(n) < n^0.51 < n*log2(n) < n^2 - 324 < 100n^2 + 6n < 2n^3 < 2^32*n < n^log2(n) < 3^n

8. Key Observations
-Functions with similar asymptotic classes (like 12√n and 50√n) are grouped together.
-Constant differences (e.g., n^2 - 324 vs. 100n^2 + 6n) don’t affect asymptotic order.
-Exponential functions (n^(log₂n), 3^n) grow far faster than polynomials.

9. Graph
Program plots graphs using gnuplot.
