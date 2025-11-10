Infix to Postfix Conversion and Evaluation Program
=
This program performs two main tasks:
 1. Convert an infix expression to a postfix expression
 2. Evaluate the postfix expression

It uses two types of stacks — one for characters (operators) and one for integers (operands).


A. Char Stack (for Infix to Postfix Conversion)
-
Purpose:
Used to temporarily hold operators and parentheses during the conversion.


Structure Used:
struct CharStack {
    int top;
    char arr[MAX];
};

Key Operations:
-pushChar() → pushes an operator or parenthesis onto the stack.
-popChar() → pops the top operator from the stack.
-peekChar() → looks at the top element without removing it.
-isCharEmpty() → checks if the stack is empty.


B. Int Stack (for Postfix Evaluation)
-
Purpose:
Used to store integer operands and intermediate results during evaluation.

Structure Used:
struct IntStack {
    int top;
    int arr[MAX];
};

Key Operations:
-pushInt() → pushes an integer onto the stack.
-popInt() → removes and returns the top integer.


C. Helper Functions
-
1.precedence(char op)
Determines the order of precedence for operators:
-^ → highest precedence
-*, / → medium precedence
-+, - → lowest precedence

2.isOperator(char c)
Checks whether a character is an operator.


D. Infix to Postfix Conversion
-
-The Shunting Yard Algorithm (by Edsger Dijkstra) is used.
-Steps:
    -Read each character from the infix expression.
    -If the character is an operand, add it to the postfix string.
    -If it’s an operator, pop operators from the stack to the postfix expression until an operator with lower precedence is found.
    -If it’s a ‘(’, push it onto the stack.
    -If it’s a ‘)’, pop everything from the stack until a matching ‘(’ is found.
    -At the end, pop all remaining operators from the stack.


Example:
Infix → (a+b)*c
Conversion steps:
(a+b)*c
→ ab+
→ ab+c*

Postfix → ab+c*

E. Postfix Evaluation
-
Once the postfix expression is generated:

1.Traverse each symbol in the postfix expression:
     -If it’s a digit, push it directly.
     -If it’s a variable, ask the user for its value and push that.
     -If it’s an operator, pop two operands, perform the operation, and push the result.

2.After the full traversal, the stack will contain the final evaluated result.


Example:
Postfix: ab+c*
Values: a=2, b=3, c=4
→ Push 2, 3, perform + → push 5
→ Push 4, perform * → 5*4 = 20

Result → 20

F. Key Features
-
   -Uses two stacks (one for characters, one for integers)
   -Handles variables and digits
   -Supports parentheses
   -Supports operator precedence and associativity
   -Handles exponentiation (^)

G. Sample Run
-
Enter an infix expression (variables allowed): (a+b)*c
Postfix Expression: ab+c*
Enter value for a: 2
Enter value for b: 3
Enter value for c: 4
Evaluation Result: 20


H. Conclusion
-
This program demonstrates the use of stack data structure in:
    -Converting infix expressions to postfix (Reverse Polish Notation),
    -Evaluating arithmetic expressions efficiently using stacks.


It is a classic example of applying data structures and expression parsing algorithms in compiler design and mathematical computation.
