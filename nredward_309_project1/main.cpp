//This is for Project 1.//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Item
{
private:
    int value;
public:

    Item(int x = 0) {
        value = x;
    }
    int getValue() {
        return value;
    }
    void setValue(int x) {
        value = x;
    }
};

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
    Item getData() {
        return data;
    }
    void setNext(Node * ptr) {
        next = ptr;
    }
    Node * getNext() {
        return next;
    }
    void incCounter() {
        counter++;
    }
    int getCounter() {
        return counter;
    }
    void resetCounter() {
        counter = 0;
    }

};

class LinkedList
{
private:
    Node * head;
    Node * tail;
    int threshold;

public:
    LinkedList(){head = nullptr; tail = nullptr; threshold = 1;}

    void push_back(Item & x)
    {
        if(tail!=nullptr)
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

    void push_back(int x)
    {
        push_back(*(new Item(x)));
    }

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

    bool empty()
    {

        if (!head)
            return true;
        else
            return false;

    }
    void print()
    {
        auto ptr = head;
        while(ptr)
        {
            cout<<"Item: "<<(ptr->getData()).getValue()<<endl;
            ptr = ptr->getNext();
        }

    }

    int MTFCounter = 0;
    int move_to_front(int x) //For move-to-front approach
    {
        auto ptr = head;
        auto prev = head;

        while (ptr) {
            MTFCounter++;
            if ((ptr->getData()).getValue() == x) {
                ptr->incCounter();

                if(ptr->getCounter() == threshold)
                {
                    // move to the front, and reset counter
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
    int transpose(int x) //For transpose approach
    {
        auto ptr = head;
        auto prev = head;
        Node * prevprev = nullptr;

        while (ptr) {
            TCounter++;
            auto tempPtr = ptr->getNext();

            if ((ptr->getData()).getValue() == x) {
                ptr->incCounter();

                if (head == ptr) {
                    //Do nothing: at start of list.//
                    return TCounter;
                }

                else if (prev == head) {

                    if(ptr->getCounter() == threshold)
                    {
                        // move to the front, and reset counter
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

                    ptr->setNext(prev);
                    prev->setNext(tempPtr);
                    head->setNext(ptr);

                    gateway++;

                    return TCounter;
                }

                else {

                    ptr->setNext(prev);
                    prev->setNext(tempPtr);
                    prevprev->setNext(ptr);

                    return TCounter;
                }
            }

            // Move pointers regardless of the condition
            prevprev = prev;
            prev = ptr;
            ptr = ptr->getNext();
        }
        return TCounter;
    }

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

    cin >> programStart >> repApproach >> inputFile >> listFile; //Taking user input.

    auto list = new LinkedList();

    fstream dFile, rFile, vFile;

    dFile.open("data.txt", ios::in); //open a file to perform read operation using file object
    if (dFile.is_open()) {
        int value;
        while (dFile >> value) { // Read integers from the file
            list->push_back(value); // Add each integer to the linked list
        }
        dFile.close(); // Close the file
    }

    int stepsCounter = 0;
    char digit;

    int cycles = 0;

    if (repApproach == '0') {

        if (inputFile == "validation1.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->move_to_front(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "validation2.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->move_to_front(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "request_1.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->move_to_front(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "request_2.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->move_to_front(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "request_3.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->move_to_front(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }
    }

    if (repApproach == '1') {
        if (inputFile == "validation1.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->transpose(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "validation2.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->transpose(digit - '0') - 1;// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "request_1.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->transpose(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "request_2.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->transpose(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }

        if (inputFile == "request_3.txt") {
            vFile.open(inputFile, ios::in); // Open the file for reading
            if (vFile.is_open()) {
                while (vFile.get(digit)) { // Read each character (digit) from the file
                    stepsCounter = list->transpose(digit - '0');// Search for the value in the linked list
                }
            }
            vFile.close(); // Close the file
        }
    }

    // Print the sorted linked list
    cout << "Sorted Linked List:" << endl;
    list->print();

    delete list; // Free the allocated memory

    cout << endl;
    cout << "This took " << stepsCounter << " steps." << endl;

    return 0;
}