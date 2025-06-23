# ECE 309 - Project 2: Binary Search Tree (BST)

**Author:** Nicholas Edwards  
**Date:** March 13, 2024  
**Course:** ECE 309 - Data Structures and Object-Oriented Programming for ECE (NC State University)  
**Section:** 405

---

## Overview

This project implements a **Binary Search Tree (BST)** in C++ with functionalities for insertion, searching, and removal of nodes. The program reads data from input files, builds a BST from those values, processes search requests, and builds a frequency-based BST according to the frequency of searched elements.

---

## Features

- **BST Operations:**  
  - Insert values into the BST  
  - Search for values in the BST  
  - Remove values from the BST  

- **BST Visualization:**  
  Prints the BST horizontally for easy visualization of tree structure.

- **Frequency Analysis:**  
  - Reads search requests from a file  
  - Counts the frequency of each searched value  
  - Sorts the frequency data in descending order  
  - Builds a frequency-based BST based on search frequencies

- **Performance Tracking:**  
  - Counts the number of steps taken during searches

---

## File Input

- **`tree.txt`:**  
  Contains comma-separated integer values to build the initial BST.

- **`request.txt`:**  
  Contains characters representing values to search in the BST.

---

## Usage

Run the program with the following command line arguments:

```bash
./program tree.txt request.txt
````

* `tree.txt`: File containing initial BST values
* `request.txt`: File containing search request values

---

## Output

* Prints the initial BST after insertion.
* Prints a frequency table showing values and their search frequencies.
* Prints the frequency-based BST built from sorted frequency data.
* Displays the total number of steps taken for searches in both BSTs.

---

## Implementation Details

* **Classes:**

  * `Node`: Represents a node in the BST with pointers to left and right children.
  * `BST`: Implements BST operations and printing.

* **Data Structures:**

  * Uses vectors for frequency tables.
  * Uses standard input/output streams for file handling and console output.

---

## Dependencies

* C++ Standard Library
* Compilation with any standard C++ compiler (e.g., g++, clang++)

---
## Notes

* The program assumes input files exist in the same directory as the executable.
* Values in `tree.txt` should be integers separated by commas.
* Search requests in `request.txt` should be single-digit characters.
---
