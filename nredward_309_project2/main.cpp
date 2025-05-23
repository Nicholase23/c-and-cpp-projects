/* Nicholas Edwards
 * March 13, 2024
 * ECE 309
 * Project 2: BST
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Node
{
public:
    int value;      // Value in node. //
    Node * left;     // Pointer to the left child node. //
    Node * right;    // Pointer to the right child node. //

    // Constructor to initialize node with a value and nullptr for left and right children. //
    Node(int x = 0) : value(x), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node * root; // Pointer to the root node of the BST. //
public:
    // Constructor to initialize BST with a nullptr root. //
    BST() : root(nullptr) {}
    // Function declarations for BST operations. //
    bool BSTSearch(int x), BSTInsert(int x), BSTRemove(int x);
    // Function to print the BST. //
    void horizon_display(), horizon_display(Node * n, int spacing);

    int stepsCounter = 0;
};

bool BST::BSTSearch(int x)
{
    Node * ptr = root; // Start from the root of the tree. //

    // Traverse the tree until ptr becomes nullptr. //
    while (ptr)
    {
        stepsCounter++;
        if (ptr->value == x)
        {
            return true; // Return true when value is found.  //
        }
        else
        {
            // Move down the tree based on the value.
            ptr = x < ptr->value ? ptr->left : ptr->right;
        }
    }
    return false; // Return false if value is not found. //
}

bool BST::BSTInsert(int x)
{
    Node * ptr = root; // Start from the root of the tree. //
    Node * prev = nullptr; // Keep track of the previous node. //

    Node * newNode = new Node(x); // Create a new node with the given value. //

    // If the tree is empty, the new node becomes the root. //
    if (!root) {
        root = newNode;
        return true;
    }

    // Traverse the tree to find the appropriate position to insert the new node. //
    while (ptr) {
        if (ptr->value == x) { return false; } // Return false if value already exists. //
        else {
            prev = ptr;
            ptr = x < ptr->value ? ptr->left : ptr->right; // Move down the tree. //
        }
    }

    // Insert the new node as a child of the previous node. //
    (x < prev->value ? prev->left : prev->right) = newNode;
    return true; // Return true to indicate successful insertion. //
}

bool BST::BSTRemove(int x)
{
    Node * ptr = root; // Start from the root of the tree. //
    Node * parent = nullptr; // Keep track of the parent node. //

    // Traverse the tree until ptr becomes nullptr. //
    while (ptr)
    {
        // Check if the value of the current node (ptr) matches the value to remove (x). //
        if (ptr->value == x)
        {
            // Case 1: Node has no children. //
            if (!ptr->left && !ptr->right)
            {
                if (!parent)
                {
                    root = nullptr; // Set root to nullptr if ptr is root. //
                }
                else
                {
                    // Update the appropriate child pointer of the parent node. //
                    (x > parent->value ? parent->right : parent->left) = nullptr;
                }
                delete ptr; // Delete the node. //
                return true; // Return true to indicate successful removal. //
            }
                // Case 2: Node has one child. //
            else if (!ptr->left || !ptr->right)
            {
                Node * child = ptr->left ? ptr->left : ptr->right; // Determine the child. //
                if (!parent)
                {
                    root = child; // Update root if ptr is root. //
                }
                else
                {
                    // Update appropriate child pointer of parent node. //
                    (x > parent->value ? parent->right : parent->left) = child;
                }
                delete ptr; // Delete the node. //
                return true; // Return true to indicate successful removal. //
            }
                // Case 3: Node has two children. //
            else
            {
                int tbr; // Value to be removed. //
                Node * successor = ptr->right; // Find successor in right subtree. //
                while (successor->left != nullptr)
                {
                    tbr = successor->value; // Track successor value. //
                    successor = successor->left; // Move to the leftmost node. //
                }
                BST::BSTRemove(tbr); // Remove successor node. //

                if (!parent)
                {
                    // Create new root with successor value and connect subtrees. //
                    root = new Node(tbr);
                    root->right = ptr->right;
                    root->left = ptr->left;
                    delete ptr; // Delete original node. //
                    return true; // Return true to indicate successful removal. //
                }
                else
                {
                    // Create new node with successor value and connect subtrees. //
                    Node * tmp = new Node(tbr);
                    tmp->right = ptr->right;
                    tmp->left = ptr->left;

                    // Update appropriate child pointer of parent node. //
                    (x > parent->value ? parent->right : parent->left) = tmp;
                    delete ptr; // Delete original node. //
                    return true; // Return true to indicate successful removal. //
                }
            }
        }
            // If the value is not found, traverse further down the tree. //
        else
        {
            parent = ptr;
            ptr = (x > ptr->value) ? ptr->right : ptr->left;
        }
    }
    return false; // Return false if value is not found in the tree. //
}

void BST::horizon_display()
{
    horizon_display(root, 0); // Start printing from the root with initial spacing of 0. //
}

void BST::horizon_display(Node * node, int spacing)
{
    if (node == nullptr) // Base case: if the current node is null, return. //
        return;

    spacing += 5; // Increase the spacing for each level. //

    horizon_display(node->right, spacing); // Print right subtree with increased spacing. //

    for (int i = 5; i < spacing; i++) // Print appropriate spaces before the node value. //
        cout << " ";

    cout << node->value << endl; // Print the current node value. //

    horizon_display(node->left, spacing); // Print left subtree with increased spacing. //
}

int main() {

    string programStart, treeFile, requestFile;

    cout << "Please input your string in the following format: ./program tree.txt request.txt:" << endl;
    cin >> programStart >> treeFile >> requestFile; // Taking user input. //

    // Create an instance of the BST. //
    BST Tree;

    fstream tFile, rFile;

    if (treeFile == "tree.txt") {
        tFile.open("tree.txt", ios::in); // Open a file to perform read operation using file object. //
        if (tFile.is_open()) {
            string valueStr;
            while (getline(tFile, valueStr, ',')) { // Read integers separated by commas. //
                // Convert the string to an integer and add it to the BST. //
                int value = stoi(valueStr);
                Tree.BSTInsert(value);
            }
            tFile.close(); // Close the file. //
        }
    }

    // Print the BST. //
    Tree.horizon_display();

    cout << endl;
    // Create a 2D vector with 2 rows and 10 columns initialized with zeros. //
    vector<vector<int>> freqTable(2, vector<int>(9, 0));

    // Fill the first row with values from 0 to 9. //
    for (int i = 0; i < 9; ++i) {
        freqTable[0][i] = i + 1;
    }

    char digit;

    if (requestFile == "request.txt") {
        rFile.open("request.txt", ios::in); // Open a file to perform read operation using file object. //
        if (rFile.is_open()) {
            while (rFile.get(digit)) {
                if (Tree.BSTSearch(digit - '0')) {
                    freqTable[1][(digit - '0') - 1]++;
                }
            }
        }
        rFile.close(); // Close the file. //
    }

    int steps = Tree.stepsCounter;
    cout << "It took " << steps << " for the tree.txt BST." << endl;
    cout << endl;

    cout << "Here is the following Frequency Table for the tree.txt BST. ";
    cout << "Row 1: Values, Row 2: Frequency of Values" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << setw(3) << freqTable[i][j] << " "; // Set the width to 3 characters. //
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (freqTable[1][i] < freqTable[1][j]) { // Sort frequencies in descending order. //
                // Swap frequencies. //
                int tempFreq = freqTable[1][i];
                freqTable[1][i] = freqTable[1][j];
                freqTable[1][j] = tempFreq;

                // Swap corresponding values. //
                int tempVal = freqTable[0][i];
                freqTable[0][i] = freqTable[0][j];
                freqTable[0][j] = tempVal;
            }
        }
    }

    cout << "Let's modify the table to show which values from highest to lowest frequency:" << endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << setw(3) << freqTable[i][j] << " "; // Set the width to 3 characters for nicer formatting. //
        }
        cout << endl;
    }
    cout << endl;

    cout << "Using this data, we can build a frequency-based BST." << endl;

    BST Frequency_Tree;

    for (int j = 0; j < freqTable[0].size(); ++j) {
        // Insert the value and its frequency into the frequency-based BST. //
        for (int k = 0; k < freqTable[1][j]; ++k) {
            Frequency_Tree.BSTInsert(freqTable[0][j]);
        }
    }

    Frequency_Tree.horizon_display();

    cout << endl;

    if (requestFile == "request.txt") {
        rFile.open("request.txt", ios::in); // Open a file to perform read operation using file object //
        if (rFile.is_open()) {
            while (rFile.get(digit)) {
                if (Frequency_Tree.BSTSearch(digit - '0')) {
                    freqTable[1][(digit - '0') - 1]++;
                }
            }
        }
        rFile.close(); // Close the file
    }

    steps = Frequency_Tree.stepsCounter;
    cout << "It took " << steps << " for the frequency-based BST." << endl;


    return 0;
}