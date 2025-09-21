Overview

-This program identifies a defective (lighter) coin from a set of coins using a divide-and-conquer approach with a simulated balance scale.
-The balance scale compares the sum of weights of two equal groups of coins.
-The algorithm recursively divides the coin set into halves until it isolates the defective coin.
Finally, a verification step confirms the defective coin against a known good one.


Key Features

-Divide & Conquer Algorithm – Efficiently narrows down the defective coin.
-Balance Simulation – Mimics the functionality of a physical balance scale.
-Verification Step – Ensures correctness by comparing the suspected coin with a reference coin.
-Dynamic Input – Works for any number of coins provided by the user.


Function Documentation

1. weigh()

int weigh(int coins[], int a_start, int b_start, int len);

Description:
Simulates weighing two groups of coins on a balance.

Parameters:
coins[] : Array of coin weights.
a_start : Starting index of group A.
b_start : Starting index of group B.
len : Number of coins in each group.

Returns:
-1 → Group A lighter
1 → Group B lighter
0 → Both groups equal


2. findDefective()

int findDefective(int coins[], int start, int n);

Description:
Recursively finds the index of the defective coin using a divide-and-conquer approach.

Parameters:
coins[] : Array of coin weights.
start : Starting index for the search.
n : Number of coins in the current segment.

Logic:
Divide the set of coins into two halves.
Weigh both halves.
Recursively search in the lighter half.
If balanced and n is odd, check the excluded coin.

Returns:
Index of the defective coin (candidate).
-1 if no defective coin found.


3. verify()

int verify(int coins[], int n, int candidate);

Description:
Validates the defective coin candidate by comparing it with a known good coin.

Parameters:
coins[] : Array of coin weights.
n : Total number of coins.
candidate : Index of the suspected defective coin.

Returns:
Candidate index if confirmed defective.
-1 if no defective coin found.


4. main()

int main();

Description:
Handles user input, executes the search, and displays the result.

Steps:
-Reads number of coins.
-Allocates memory for storing weights.
-Accepts coin weights from the user.
-Calls findDefective() to get a candidate coin.
-Verifies the candidate using verify().
-Prints the defective coin’s position or reports no defect.

Algorithm Complexity
Time Complexity: O(log n) (due to divide & conquer).
Space Complexity: O(log n) (due to recursive calls).

Sample Input/Output

Input 1:
Enter number of coins: 5
Enter weights of 5 coins:
10 10 9 10 10
Output 1:
Defective (lighter) coin is at position 2 (0-based index).

Input 2:
Enter number of coins: 4
Enter weights of 4 coins:
10 10 10 10
Output 2:
No defective coin found. All coins are perfect.
Fault detection problems where one faulty element differs slightly from the others.

Teaching divide-and-conquer algorithms and recursive problem-solving.
