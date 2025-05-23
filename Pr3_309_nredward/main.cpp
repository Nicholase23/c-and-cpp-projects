/*
 * Nicholas Edwards
 * April 19, 2024
 * Maze Traversal Program
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue> // Include queue for BFS algorithm
#include <stack> // Include stack for DFS algorithm

using namespace std;

// Node class representing each cell in the maze
class Node {
private:
    int x; // x-coordinate of the node
    int y; // y-coordinate of the node
    char value; // value of the node (wall, path, start, end)

public:
    Node(int x, int y, char value) : x(x), y(y), value(value) {}

    // Getter functions
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    char getValue() const {
        return value;
    }

    // Setter function to update node value
    void setValue(char newValue) {
        value = newValue;
    }
};

// Maze class representing the entire maze
class Maze {
protected: // Change to protected for inheritance
    vector<vector<Node>> maze; // 2D vector to store the maze
    vector<vector<pair<int, int>>> parent; // Stores parent nodes for path reconstruction
    vector<vector<bool>> visited; // Keeps track of visited nodes

public:
    // Constructor to read maze from file
    explicit Maze(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        int y = 0;
        while (getline(file, line)) {
            int x = 0;
            vector<Node> row;
            for (char c : line) {
                if (c == '0' || c == '1') {
                    row.emplace_back(x, y, c); // Use push_back instead of emplace_back
                    x++;
                }
            }
            maze.push_back(row);
            y++;
        }
        file.close();

        // Initialize parent and visited vectors
        parent.resize(maze.size(), vector<pair<int, int>>(maze[0].size(), {-1, -1}));
        visited.resize(maze.size(), vector<bool>(maze[0].size(), false));
    }

    // Function to print the maze
    void printMaze() const {
        for (const auto& row : maze) {
            for (const auto& node : row) {
                if (node.getValue() == '0') {
                    cout << "# "; // Wall
                } else if (node.getValue() == '1') {
                    cout << "- "; // Wrong Path
                } else {
                    cout << node.getValue() << " "; // Start, End, or Path
                }
            }
            cout << endl;
        }
    }

    // Function to set value at a specific coordinate in the maze
    void setValueAt(int x, int y, char newValue) {
        if (x >= 0 && x < maze[0].size() && y >= 0 && y < maze.size()) {
            maze[y][x].setValue(newValue);
        } else {
            cerr << "Error: Coordinate out of range" << endl;
        }
    }

    // Function to check if a coordinate is within the maze boundaries
    bool isValid(int x, int y) const {
        return x >= 0 && x < maze[0].size() && y >= 0 && y < maze.size();
    }

    // Function to mark a node as visited
    void markVisited(int x, int y) {
        visited[y][x] = true;
    }

    // Function to check if a node has been visited
    bool isVisited(int x, int y) const {
        return visited[y][x];
    }

    // Function to get parent of a node
    pair<int, int> getParent(int x, int y) const {
        return parent[y][x];
    }

    // Function to set parent of a node
    void setParent(int x, int y, int px, int py) {
        parent[y][x] = {px, py};
    }
};

// Define arrays dx and dy representing the changes in the x and y coordinates respectively,
// for moving in four directions: right, down, left, and up.
int dx[] = {1, 0, -1, 0}; // Changes in x-coordinate for right, down, left, and up movements
int dy[] = {0, 1, 0, -1}; // Changes in y-coordinate for right, down, left, and up movements

// Breadth First Search Maze subclass
class BFSMaze : public Maze {
public:
    explicit BFSMaze(const string& filename) : Maze(filename) {} // Inherit constructor

    // Function to find the shortest path using BFS
    void BFS_searchpath(int startX, int startY, int destX, int destY) {
        queue<pair<int, int>> q;

        q.emplace(startX, startY);
        markVisited(startX, startY);

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == destX && y == destY) {
                // Reconstruct path
                while (x != startX || y != startY) {
                    maze[y][x].setValue('+');
                    int nx = getParent(x, y).first;
                    int ny = getParent(x, y).second;
                    x = nx;
                    y = ny;
                }
                maze[startY][startX].setValue('s');
                maze[destY][destX].setValue('e');
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny) && maze[ny][nx].getValue() != '0' && !isVisited(nx, ny)) {
                    q.emplace(nx, ny);
                    markVisited(nx, ny);
                    setParent(nx, ny, x, y);
                }
            }
        }
    }
};

// Depth First Search Maze subclass
class DFSMaze : public Maze {
public:
    explicit DFSMaze(const string& filename) : Maze(filename) {} // Inherit constructor

    // Function to find the path using DFS
    void DFS_searchpath(int startX, int startY, int destX, int destY) {
        stack<pair<int, int>> s;

        s.emplace(startX, startY);
        markVisited(startX, startY);

        while (!s.empty()) {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();

            if (x == destX && y == destY) {
                // Reconstruct path
                while (x != startX || y != startY) {
                    maze[y][x].setValue('+');
                    int nx = getParent(x, y).first;
                    int ny = getParent(x, y).second;
                    x = nx;
                    y = ny;
                }
                maze[startY][startX].setValue('s');
                maze[destY][destX].setValue('e');
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny) && maze[ny][nx].getValue() != '0' && !isVisited(nx, ny)) {
                    s.emplace(nx, ny);
                    markVisited(nx, ny);
                    setParent(nx, ny, x, y);
                }
            }
        }
    }
};

// Best-First Search Maze subclass
class GBFSMaze : public Maze {
public:
    explicit GBFSMaze(const string& filename) : Maze(filename) {} // Inherit constructor

    // Function to find the path using Best-First Search
    void GBFS_searchpath(int startX, int startY, int destX, int destY) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0, {startX, startY}});
        markVisited(startX, startY);

        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == destX && y == destY) {
                // Reconstruct path
                while (x != startX || y != startY) {
                    maze[y][x].setValue('+');
                    int nx = getParent(x, y).first;
                    int ny = getParent(x, y).second;
                    x = nx;
                    y = ny;
                }
                maze[startY][startX].setValue('s');
                maze[destY][destX].setValue('e');
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isValid(nx, ny) && maze[ny][nx].getValue() != '0' && !isVisited(nx, ny)) {
                    int heuristic = abs(nx - destX) + abs(ny - destY); // Manhattan distance as heuristic
                    pq.push({heuristic, {nx, ny}});
                    markVisited(nx, ny);
                    setParent(nx, ny, x, y);
                }
            }
        }
    }
};

// Main function
int main() {

    string programStart, mazeFile, coordinateFile, method;

    // Prompt user for input
    cout << "Please input your string in the following format:\n";
    cout << "./program <maze filename> <coordinate files> <searching method>\n";

    cin >> programStart >> mazeFile >> coordinateFile >> method; //Taking user input.

    cout << endl;

    ifstream inputFile(coordinateFile);

    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    int x1, y1, x2, y2;
    inputFile >> x1 >> y1 >> x2 >> y2;

    inputFile.close();

    // Display start and destination coordinates
    cout << "Start coordinates: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Destination coordinates: (" << x2 << ", " << y2 << ")\n" << endl;

    // Check the selected method and perform corresponding actions
    if (method == "BFS") {
        cout << "Using BFS Method:\n" << endl;

        BFSMaze maze(mazeFile); // Use BFSMaze instead of Maze

        // Call BFS_searchpath method
        maze.BFS_searchpath(x1, y1, x2, y2);

        maze.printMaze();
    } else if (method == "DFS") {
        cout << "Using DFS Method:\n" << endl;

        DFSMaze maze(mazeFile); // Use DFSMaze instead of Maze

        // Call DFS_searchpath method
        maze.DFS_searchpath(x1, y1, x2, y2);

        maze.printMaze();
    } else if (method == "GBFS") {
        cout << "Using GBFS Method:\n" << endl;

        GBFSMaze maze(mazeFile); // Use GBFSMaze instead of Maze

        // Call GBFS_searchpath method
        maze.GBFS_searchpath(x1, y1, x2, y2);

        maze.printMaze();
    } else {
        cerr << "Invalid searching method." << endl;
    }

    return 0;
}
