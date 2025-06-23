# Maze Traversal Program

## Course Information

- **Course Name**: Data Structures and Object-Oriented Programming for Electrical and Computer Engineers  
- **Course Code**: ECE 309  
- **Instructor**: Nicholas Edwards  
- **Lab Section**: 405  
- **Date**: April 19, 2024

## Program Overview

This C++ program implements a maze traversal algorithm to find the shortest path between a start and an end point within a maze. It utilizes object-oriented programming principles, including classes, inheritance, and polymorphism, to model the maze and traversal methods. The program supports multiple search algorithms:​:contentReference[oaicite:21]{index=21}

- **Breadth-First Search (BFS)**: Explores all possible paths level by level to find the shortest path.
- **Depth-First Search (DFS)**: Explores paths by going as deep as possible before backtracking.
- **Greedy Best-First Search (GBFS)**: Uses a heuristic to explore paths that appear to be closest to the goal.:contentReference[oaicite:28]{index=28}

The maze is represented as a grid of nodes, each with properties indicating whether it's a wall, path, start, or end. The program reads maze data from a file and coordinates from another file, then applies the selected search algorithm to find and display the path.:contentReference[oaicite:33]{index=33}

## Requirements

- **Programming Language**: C++
- **Libraries**:
  - `<iostream>`
  - `<fstream>`
  - `<vector>`
  - `<string>`
  - `<queue>`
  - `<stack>`:contentReference[oaicite:48]{index=48}

## How to Run

1. Ensure you have a C++ compiler installed (e.g., GCC).
2. Place the maze data file and coordinates file in the same directory as the program.
3. Compile the program

   ```bash
   g++ -o maze_traversal maze_traversal.cpp
4. Run the program with the following command:

   ```bash
   ./maze_traversal <maze_filename> <coordinates_filename> <search_method>
   ```

Replace `<maze_filename>` with the name of the maze data file, `<coordinates_filename>` with the file containing start and end coordinates, and `<search_method>` with one of `BFS`, `DFS`, or `GBFS`.

## Sample Input

* **Maze File**: `maze.txt`

  ```
  111111
  100001
  101101
  101001
  111101
  111111
  ```

* **Coordinates File**: `coordinates.txt`

  ```
  1 1 4 4
  ```

* **Search Method**: `BFS`

## Sample Output

```
Start coordinates: (1, 1)
Destination coordinates: (4, 4)

Using BFS Method:

# # # # # 
# s - - # 
# # + # # 
# + - e # 
# # # # # 
```

## Notes

* Ensure that the maze file contains only `1` (wall) and `0` (path) characters.
* The coordinates file should contain four integers: startX startY endX endY.
* The search method must be one of `BFS`, `DFS`, or `GBFS`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
