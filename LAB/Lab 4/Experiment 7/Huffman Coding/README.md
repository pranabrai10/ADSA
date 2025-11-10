Huffman Coding – Data Compression
=
Overview
-
This project implements Huffman Coding, a lossless data compression technique that minimizes the average code length used to represent characters in a message. It uses variable-length codes, assigning shorter codes to more frequent characters and longer codes to less frequent ones.

Objective
-
To design and implement an algorithm that efficiently encodes data using Huffman coding principles, thereby reducing the total number of bits required to store or transmit textual data.

Concept
-
Huffman coding is based on frequency analysis of characters. The algorithm constructs a binary tree (Huffman Tree) where each leaf node represents a character, and its path from the root defines the binary code assigned to it.

-Characters with higher frequency → shorter codes
-Characters with lower frequency → longer codes

This ensures minimum average code length, achieving optimal lossless compression.

Major Components
-
1.Frequency Table
Counts occurrences of each unique character in the input data.

2.Min-Heap / Priority Queue
Stores tree nodes in ascending order of frequency for efficient retrieval of the smallest nodes.

3.Huffman Tree Construction
-Remove two nodes with the smallest frequency.
-Combine them into a new node with a frequency equal to their sum.
-Repeat until only one node remains — the root of the Huffman Tree.

4.Code Generation
-Traverse the Huffman Tree recursively.
-Assign ‘0’ for the left edge and ‘1’ for the right edge.
-Store the binary codes for each character.

5.Encoding Process
Replace each character in the original data with its corresponding Huffman code to form the compressed output.

Algorithm Steps
-
1.Count the frequency of each character.
2.Create a leaf node for each character and insert it into a min-heap.
3.While more than one node remains:
     -Extract the two nodes with the smallest frequencies.
     -Create a new internal node with these two as children.
     -Insert the new node back into the heap.
4.The remaining node is the root of the Huffman Tree.
5.Generate codes by traversing the tree.
6.Encode the original data using the generated codes.

Data Structures Used
-
-Structures (struct) for tree nodes containing:
    -Character data
    -Frequency
    -Left and right child pointers
-Arrays for character frequency and Huffman codes
-Priority queue (min-heap) for efficient node selection

Advantages
-
-Produces optimal prefix-free codes (no code is a prefix of another).
-Lossless compression — original data can be perfectly reconstructed.
-Efficient for text or symbol-based data with uneven frequency distribution.

Limitations
-
-Requires the entire dataset to be known before encoding.
-Huffman codes vary with input distribution, so decoding requires the same code map.
