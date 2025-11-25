# Huffman Coding – Data Compression (C Implementation)

This code implements **Huffman Coding**, a widely used **lossless data compression** algorithm that minimizes the total number of bits required to represent data.  
It assigns **shorter binary codes to frequent characters** and **longer codes to infrequent ones**, ensuring optimal compression using variable-length prefix-free codes.

---

## 📌 Overview

Huffman Coding constructs a **binary tree** (Huffman Tree) based on the frequency of characters in the input data.  
The binary path from root to leaf (0 for left, 1 for right) defines the Huffman code of each character.

This achieves **minimum average code length**, making Huffman Coding one of the most efficient compression techniques for text and symbol data.

---

## 📌 Objective

- Implement Huffman Coding in C using tree structures and a min-heap  
- Analyze character frequencies  
- Build the Huffman Tree  
- Generate prefix-free binary codes  
- Compress input text using these codes  

---

## 📌 Concept

Huffman Coding assigns codes based on frequency:

- **High-frequency characters → shorter codes**  
- **Low-frequency characters → longer codes**

This ensures optimal encoding among all prefix-free binary codes.

The algorithm uses:

- **Frequency analysis**  
- **Priority queue (min-heap)**  
- **Binary tree construction**  
- **Recursive code generation**

---

## 📌 Major Components

### 🔹 1. Frequency Table
Counts occurrences of each unique character in the input string.

### 🔹 2. Min-Heap / Priority Queue
Stores Huffman Tree nodes sorted by frequency.  
Allows repeated extraction of the two smallest-weight nodes.

### 🔹 3. Huffman Tree Construction
1. Remove two smallest nodes  
2. Combine them into a new internal node  
3. Insert the combined node back into the min-heap  
4. Continue until only one node remains → the root of the Huffman Tree  

### 🔹 4. Code Generation
- Traverse the Huffman Tree recursively  
- Assign:
  - `0` → left branch  
  - `1` → right branch  
- Store codes in an array or lookup table  

### 🔹 5. Encoding
Replace each original character with its Huffman code to form the compressed bitstream.

---

## 📌 Algorithm Steps

1. Count the frequency of each character  
2. Create leaf nodes and insert them into a min-heap  
3. While more than one node exists:
   - Extract the two lowest-frequency nodes  
   - Create a combined internal node  
   - Insert it back into the min-heap  
4. Remaining node becomes the Huffman Tree root  
5. Generate codes via tree traversal  
6. Encode input text using the generated codes  

---

## 📌 Data Structures Used

- `struct Node` containing:
  - Character
  - Frequency
  - Left / right child pointers
- Arrays for:
  - Frequencies  
  - Generated Huffman codes  
- **Min-heap (priority queue)** for selecting the smallest nodes efficiently  

---

## 📌 Advantages

- Produces **optimal**, prefix-free binary codes  
- **Lossless compression** → original data is perfectly recoverable  
- Highly efficient when character frequencies vary widely  
- Widely used in:
  - Text compression  
  - File archiving (ZIP, GZIP)  
  - Multimedia formats  

---

## 📌 Limitations

- Requires access to the **entire input** before encoding  
- The decoder must have the **exact same Huffman Tree or code map**  
- Not ideal for data with uniform frequency distribution  
- Tree-building adds overhead for very small input sizes  

---

## 📌 Conclusion

This project demonstrates how Huffman Coding performs optimal lossless compression by combining priority queues and tree-based encoding.  
It showcases the fundamental principles behind many real-world compression tools.

