// Project 1: Linked List with Move-to-Front and Transpose Repositioning Approaches

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Class representing an item stored in the linked list
class Item
{
private:
    int value;
public:
    Item(int x = 0) { value = x; }
    int getValue() { return value; }
    void setValue(int x) { value = x; }
};

// Node class holds an Item, pointer to next node, and a counter used in repositioning logic
class Node
{
private:
    Item data;
    Node * next;
    int counter;
public:
    Node(const Item & it) {
        data = it;
        next = nullptr;
        counter = 0;
    }
    Item getData() { return data; }
    void setNext(Node * ptr) { next = ptr; }
    Node * getNext() { return next; }
    void incCounter() { counter++; }
    int getCounter() { return counter; }
    void resetCounter() { counter = 0; }
};

// LinkedList class manages nodes and supports move-to-front and transpose repositioning
class LinkedList
{
private:
    Node * head;
    Node * tail;
    int threshold;  // Threshold to decide when to reposition nodes

public:
    LinkedList() { head = nullptr; tail = nullptr; threshold = 1; }

    // Add new item at the end of the list
    void push_back(Item & x)
    {
        if(tail != nullptr)
        {
            tail->setNext(new Node(x));
            tail = tail->getNext();
        }
        else
        {
            auto ptr = new Node(x);
            head = ptr;
            tail = ptr;
        }
    }

    // Convenience overload to add int directly
    void push_back(int x)
    {
        push_back(*(new Item(x)));
    }

    // Remove front node and return its data, false if list empty
    bool pop_front(Item & val)
    {
        if(!head)
        {
            val = NULL;
            tail = nullptr;
            return false;
        }

        auto ptr = head;
        val = head->getData();
        head = head->getNext();
        delete ptr;
        return true;
    }

    // Check if list is empty
    bool empty()
    {
        return head == nullptr;
    }

    // Print all item values in the list
    void print()
    {
        auto ptr = head;
        while(ptr)
        {
            cout << "Item: " << (ptr->getData()).getValue() << endl;
            ptr = ptr->getNext();
        }
    }

    int MTFCounter = 0;

    // Move-To-Front repositioning approach
    int move_to_front(int x)
    {
        auto ptr = head;
        auto prev = head;

        while (ptr) {
            MTFCounter++;  // Count each node visited

            if ((ptr->getData()).getValue() == x) {
                ptr->incCounter();

                if(ptr->getCounter() == threshold)
                {
                    // Remove node from current position and move it to front
                    prev->setNext(ptr->getNext());

                    if(ptr != head)
                    {
                        ptr->setNext(head);
                        head = ptr;
                    }
                    head->resetCounter();
                }
                return MTFCounter;
            }
            prev = ptr;
            ptr = ptr->getNext();
        }
        return MTFCounter;
    }

    int TCounter = 0;
    int gateway = 0;

    // Transpose repositioning approach
    int transpose(int x)
    {
        auto ptr = head;
        auto prev = head;
        Node * prevprev = nullptr;

        while (ptr) {
            TCounter++;  // Count each node visited
            auto tempPtr = ptr->getNext();

            if ((ptr->getData()).getValue() == x) {
                ptr->incCounter();

                if (head == ptr) {
                    // Node is already at front, no transpose needed
                    return TCounter;
                }
                else if (prev == head) {
                    // Node is second in list
                    if(ptr->getCounter() == threshold)
                    {
                        // Move node to front and reset counter
                        prev->setNext(ptr->getNext());
                        if(ptr != head)
                        {
                            ptr->setNext(head);
                            head = ptr;
                        }
                        head->resetCounter();
                    }
                    return TCounter;
                }
                else if (prevprev == head && gateway < 1) {
                    // Special case for swapping nodes near front
                    ptr->setNext(prev);
                    prev->setNext(tempPtr);
                    head->setNext(ptr);

                    gateway++;
                    return TCounter;
                }
                else {
                    // Swap current node with previous node
                    ptr->setNext(prev);
                    prev->setNext(tempPtr);
                    prevprev->setNext(ptr);
                    return TCounter;
                }
            }

            // Advance pointers to next nodes
            prevprev = prev;
            prev = ptr;
            ptr = ptr->getNext();
        }
        return TCounter;
    }

    // Destructor to free all nodes on list deletion
    ~LinkedList()
    {
        while (!empty())
        {
            Item x;
            pop_front(x);
        }
    }
};

int main() {
    string programStart, inputFile, listFile;
    char repApproach;

    cout << "Please input your string in the following format (0 for Move to Front Approach, 1 for Transpose Approach):\n";
    cout << "./program <repositioning approach> <input filename> <linked list file>:\n";

    cin >> programStart >> repApproach >> inputFile >> listFile; // Get user input

    auto list = new LinkedList();

    fstream dFile, rFile, vFile;

    // Open and read data.txt to initialize linked list
    dFile.open("data.txt", ios::in);
    if (dFile.is_open()) {
        int value;
        while (dFile >> value) {
            list->push_back(value);
        }
        dFile.close();
    }

    int stepsCounter = 0;
    char digit;

    // Perform repositioning based on chosen approach and input file
    if (repApproach == '0') { // Move-to-front approach
        vFile.open(inputFile, ios::in);
        if (vFile.is_open()) {
            while (vFile.get(digit)) {
                stepsCounter = list->move_to_front(digit - '0');
            }
            vFile.close();
        }
    }
    else if (repApproach == '1') { // Transpose approach
        vFile.open(inputFile, ios::in);
        if (vFile.is_open()) {
            while (vFile.get(digit)) {
                stepsCounter = list->transpose(digit - '0');
            }
            vFile.close();
        }
    }

    // Output the final linked list after repositioning
    cout << "Sorted Linked List:" << endl;
    list->print();

    delete list;  // Clean up allocated memory

    cout << endl << "This took " << stepsCounter << " steps." << endl;

    return 0;
}
