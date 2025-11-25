# Infix to Postfix Conversion and Postfix Evaluation – C Implementation

This code implements two classic expression-processing algorithms using stacks:

1. **Convert an Infix expression → Postfix expression**  
2. **Evaluate the resulting Postfix expression**

The program uses two stack structures — one for characters (operators/parentheses) and one for integer operands — making it a strong demonstration of stack usage in compiler design and expression evaluation.

---

## 📌 A. Char Stack (Used in Infix → Postfix Conversion)

### Purpose
Temporarily stores operators and parentheses during the conversion process.

### Structure
```c
struct CharStack {
    int top;
    char arr[MAX];
};
```

### Operations
- `pushChar()` — push operator/parenthesis  
- `popChar()` — pop from stack  
- `peekChar()` — view top element  
- `isCharEmpty()` — check emptiness  

This stack supports the **Shunting Yard Algorithm**.

---

## 📌 B. Int Stack (Used in Postfix Evaluation)

### Purpose
Stores numeric operands and intermediate computation results.

### Structure
```c
struct IntStack {
    int top;
    int arr[MAX];
};
```

### Operations
- `pushInt()` — push integer value  
- `popInt()` — pop and return integer  

Used to evaluate postfix expressions efficiently.

---

## 📌 C. Helper Functions

### 🔹 1. Operator Precedence
```c
int precedence(char op);
```
Defines precedence levels:

| Operator | Precedence |
|---------|------------|
| `^` | Highest |
| `*`, `/` | Medium |
| `+`, `-` | Lowest |

### 🔹 2. Operator Check
```c
int isOperator(char c);
```
Detects whether the character is a valid operator.

---

## 📌 D. Infix → Postfix Conversion

Uses **Dijkstra’s Shunting Yard Algorithm**.

### Steps:
1. Read expression from left to right  
2. If character is an **operand** → append to postfix string  
3. If **operator** → pop higher-or-equal precedence operators from stack  
4. If `(` → push to stack  
5. If `)` → pop until `(` appears  
6. After reading all characters → pop remaining operators  

### Example  
Infix:  
```
(a+b)*c
```

Conversion process:
- `(` → stack  
- `a` → output  
- `+` → stack  
- `b` → output  
- `)` → pop `+`  
- `*` → stack  
- `c` → output  

Final Postfix:
```
ab+c*
```

---

## 📌 E. Postfix Evaluation

After generating the postfix string:

1. Traverse each symbol  
2. If operand:
   - If digit → push  
   - If variable → ask user for value  
3. If operator:
   - Pop two operands  
   - Compute result  
   - Push result back  
4. Final stack value = result

### Example
Postfix:  
```
ab+c*
```

Values:
- a = 2  
- b = 3  
- c = 4  

Evaluation:
- Push 2, push 3 → apply `+` → push 5  
- Push 4 → apply `*` → result = **20**  

---

## 📌 F. Key Features

✔ Uses two independent stacks  
✔ Supports variables & digit operands  
✔ Handles parentheses properly  
✔ Supports operator precedence  
✔ Includes exponentiation (`^`)  
✔ Implements the full Shunting Yard Algorithm  
✔ Complete postfix evaluation engine  

---

## 📌 G. Sample Run

```
Enter an infix expression (variables allowed): (a+b)*c
Postfix Expression: ab+c*
Enter value for a: 2
Enter value for b: 3
Enter value for c: 4
Evaluation Result: 20
```

---

## 📌 H. Conclusion

This program demonstrates:

- How stacks are used for **expression parsing**  
- How infix expressions are converted to **postfix (Reverse Polish Notation)**  
- How postfix expressions are **evaluated efficiently**  
- Real principles used in **compiler design, interpreters, and arithmetic expression engines**  

It is a classic, foundational example linking data structures to real-world applications.

