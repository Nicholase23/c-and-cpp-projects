# Linked List Repositioning Approaches - Project 1 (ECE 309)

**Author:** Nicholas Edwards  
**Course:** ECE 309 - Data Structures and Object-Oriented Programming for ECE  
**Section:** 405

## Overview

This project implements a linked list data structure supporting two node repositioning approaches:  
- **Move-To-Front (MTF)**  
- **Transpose**

The program reads initial integer data from a file to populate the linked list, then processes a sequence of requests from another input file. Each request searches for a value in the list and repositions the node based on the chosen approach, optimizing search efficiency.

## Features

- Classes for `Item`, `Node`, and `LinkedList` encapsulate data and linked list operations.
- Supports dynamic insertion and repositioning of nodes.
- Handles input from files with data values and request sequences.
- Counts steps taken during search and repositioning operations for performance analysis.

## Usage

Run the program from the command line as follows:

```

./program <repositioning approach> <input filename> <linked list file>

```

- `<repositioning approach>`:  
  - `0` for Move-To-Front  
  - `1` for Transpose  
- `<input filename>`: File containing the sequence of requests (digits).  
- `<linked list file>`: File containing initial integer values to build the linked list.

## Example

```

./program 0 validation1.txt data.txt

```

This runs the Move-To-Front approach with `validation1.txt` as the request file and `data.txt` as the initial data.

## Notes

- The program outputs the final linked list and the number of steps taken to process the requests.
- Memory management is handled within the `LinkedList` destructor.

---

*For questions or issues, contact Nicholas Edwards.*
