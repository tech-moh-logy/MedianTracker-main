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


// using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "myVector.cpp"
#include "myList.cpp"
#include "myHeap.cpp"
#include "myAVLtree.cpp"

int main() {
    std::ifstream inputFile("test1.txt");
    std::vector<int> instructions;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string operation;
        iss >> operation;
        if (operation == "insert") {
            int value;
            while (iss >> value) {
                instructions.push_back(value);
            }
        } else if (operation == "pop") {
            instructions.push_back(-1); // Push -1 for "pop median" operation
        }
    }

    // Pass instructions to each median tracking method
    //vectorMedian(&instructions);
    listMedian(&instructions);
    //heapMedian(&instructions);
    //treeMedian(&instructions);

    return 0;
}




// #include <iostream>
// #include <fstream>
// #include <vector>
// #include "myVector.hpp"
// #include "myList.hpp"
// #include "myHeap.hpp"
// #include "myAVLtree.hpp"

// using namespace std;

// int main() {
//     ifstream inputFile("testInput.txt");
//     vector<string> instructions;
//     // the logic: vector<int> variable_name

//     string line;

//     while (getline(inputFile, line)) {
//         instructions.push_back(line);
//     }

//     // Pass instructions to each median tracking method
//     vectorMedian(&instructions);
//     listMedian(&instructions);
//     heapMedian(&instructions);
//     treeMedian(&instructions);

//     return 0;
// }
