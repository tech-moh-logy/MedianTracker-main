// Developer: Mohammed

// Project Name: Median Tracker

// Overview: The project aims to implement an Abstract Data Type (ADT) for tracking medians in various data structures. Four different implementations are provided:

// 1. Vector-based: Uses a sorted vector to insert elements and pop medians.
// 2. Linked list-based: Utilizes a sorted linked list to insert elements and pop medians.
// 3. Heap-based: Maintains a max heap for elements less than or equal to the median and a min heap for elements greater than the median.
// 4. AVL tree-based: Implements two AVL trees, one for elements less than or equal to the median and the other for elements greater than the median.

// The project involves creating separate files for each implementation, including `myVector.cpp`, `myList.cpp`, `myHeap.cpp`, and `myAVLtree.cpp`. Each file contains functions to insert elements and pop medians according to the provided instructions.

// Additionally, a `main.cpp` file is provided to read input instructions from a file, convert them into an integer format, and pass them to each median tracking method. The performance of each implementation is measured and compared, and the results are presented in a report.

// Overall, the project focuses on understanding and implementing different approaches to efficiently track medians in various data structures.



#include "myHeap.hpp"
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void heapMedian(const std::vector<int>* instructions) {
    // Priority queues for small and large numbers
    priority_queue<int> small; // Max heap for elements less than or equal to the median
    priority_queue<int, vector<int>, greater<int> > large; // Min heap for elements greater than the median

    // Iterate over each instruction
    for (const int& instruction : *instructions) {
        if (instruction == -1) { // If instruction is pop median
            // If both heaps are not empty, calculate median
            if (!small.empty() || !large.empty()) {
                // Retrieve median
                int median;
                if (small.size() > large.size()) {
                    median = small.top();
                    small.pop();
                } else if (small.size() < large.size()) {
                    median = large.top();
                    large.pop();
                } else {
                    median = small.top();
                    small.pop();
                }

                // Print the median
                cout << median << " ";
            }
        } else { // If instruction is insert X
            int num = instruction;
            if (small.empty() || num <= small.top()) {
                small.push(num);
            } else {
                large.push(num);
            }

            // Balance heaps
            if (small.size() < large.size()) {
                small.push(large.top());
                large.pop();
            } else if (small.size() > large.size() + 1) {
                large.push(small.top());
                small.pop();
            }
        }
    }

    // Print a newline after all medians are printed
    cout << endl;
}

