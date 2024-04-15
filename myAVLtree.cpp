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


#include "myAVLtree.hpp"

// Function to calculate the median of a sequence of instructions using AVL trees
void treeMedian(const std::vector<int>* instructions) {
    AVLtree smallTree, largeTree; // Create AVL trees to store elements smaller and larger than the current median
    std::vector<int> medianList; // Store medians

    // Iterate through the instructions
    for (std::vector<int>::const_iterator it = instructions->begin(); it != instructions->end(); ++it) {
        int val = *it; // Get the current instruction value
        if (val != -1) { // If the value is not a termination signal (-1)
            // Decide where to insert the value based on the current median
            if (smallTree.getSize() == 0 || smallTree.getMax() > val) { // If the value is smaller than the current median
                smallTree.insert(val); // Insert into the smaller elements tree
            } else {
                largeTree.insert(val); // Insert into the larger elements tree
            }
        } else { // If the value is a termination signal (-1)
            medianList.push_back(smallTree.popMaximum()); // Get the current median and add it to the median list
        }

        // Balance the sizes of the two trees to ensure that the difference in sizes is at most 1
        if (smallTree.getSize() > largeTree.getSize() + 1) { // If the smaller elements tree has more than one element than the larger elements tree
            largeTree.insert(smallTree.popMaximum()); // Move the maximum element from the smaller elements tree to the larger elements tree
        } else if (largeTree.getSize() > smallTree.getSize()) { // If the larger elements tree has more elements than the smaller elements tree
            smallTree.insert(largeTree.popMinimum()); // Move the minimum element from the larger elements tree to the smaller elements tree
        }
    }

    // Print the median list
    for (std::vector<int>::const_iterator it = medianList.begin(); it != medianList.end(); ++it) {
        int median = *it;
        std::cout << median << " ";
    }

    std::cout << std::endl;
}
