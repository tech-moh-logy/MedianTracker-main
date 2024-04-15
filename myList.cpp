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



#include "myList.hpp"
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

void listMedian(const std::vector<int>* instructions) {
    std::list<int> numList;  // List to store the current set of numbers
    std::vector<int> medians;  // Vector to store the medians after each -1 instruction

    // Loop through each instruction in the vector
    for (std::vector<int>::const_iterator it = instructions->begin(); it != instructions->end(); ++it) {
        int inst = *it;
        // Check if the instruction is to insert a number
        if (inst != -1) {
            // Insert the number in sorted order in the list
            std::list<int>::iterator listIter = std::lower_bound(numList.begin(), numList.end(), inst);
            numList.insert(listIter, inst);
        }
        else {  // If the instruction is -1, compute and remove the median
            if (!numList.empty()) {
                std::list<int>::iterator listIter = numList.begin();
                // Advance the iterator to the middle of the list for the median
                std::advance(listIter, numList.size() / 2);
                // If the list size is even, step back to get the lower middle as median
                if (numList.size() % 2 == 0 && listIter != numList.begin()) {
                    std::advance(listIter, -1);
                }

                // Add the median to the medians vector
                medians.push_back(*listIter);
                // Remove the median element from the list
                numList.erase(listIter);
            }
        }
    }

    // After all instructions have been processed, print out the medians
    for (std::vector<int>::const_iterator it = medians.begin(); it != medians.end(); ++it) {
        int med = *it;
        std::cout << med << " ";
    }
    // End the output line
    std::cout << std::endl;
}


// #include "myList.hpp"
// #include <list>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// void insertIntoList(std::list<int>& numbers, int value) {
//     // Insert value into list at the correct sorted position
//     auto it = std::lower_bound(numbers.begin(), numbers.end(), value);
//     numbers.insert(it, value);
// }

// // int popMedianFromList(std::list<int>& numbers) {
// //     // If list is empty, return -1
// //     if (numbers.empty()) {
// //         return -1;
// //     }

// //     // Find the median
// //     auto mid = std::next(numbers.begin(), numbers.size() / 2);
// //     int median = *mid;
// //     if (numbers.size() % 2 == 0) {
// //         // For even-sized list, median is the element at size/2 - 1
// //         median = *std::prev(mid);
// //     }

// //     // Erase the median from the list
// //     numbers.erase(mid);

// //     return median;
// // }

// int popMedianFromList(std::list<int>& numbers) {
//     // If list is empty, return -1
//     if (numbers.empty()) {
//         return -1;
//     }

//     // Find the median
//     auto mid = std::next(numbers.begin(), numbers.size() / 2);
//     int median = *mid;
//     if (numbers.size() % 2 == 0) {
//         // For even-sized list, median is the element before mid
//         median = *std::prev(mid);
//     }

//     // Erase the median from the list
//     numbers.erase(mid);

//     return median;
// }

// void listMedian(const std::vector<int>* instructions) {
//     // List to store the numbers
//     std::list<int> numbers;

//     // Iterate over each instruction
//     for (const int& instruction : *instructions) {
//         if (instruction == -1) { // Assuming -1 indicates "pop median"
//             // If list is not empty, pop median and print it
//             int median = popMedianFromList(numbers);
//             if (median != -1) {
//                 std::cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, insert X into list at the correct sorted position
//             insertIntoList(numbers, instruction);
//         }
//     }

//     // Print a newline after all medians are printed
//     std::cout << std::endl;
// }


// #include "myList.hpp"
// #include <list>
// #include <string>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// void listMedian(const std::vector<int>* instructions) {
//     // List to store the numbers
//     std::list<int> numbers;

//     // Iterate over each instruction
//     for (const int& instruction : *instructions) {
//         if (instruction == -1) { // Assuming -1 indicates "pop median"
//             // If list is not empty, calculate median
//             if (!numbers.empty()) {
//                 // Find the median
//                 auto mid = std::next(numbers.begin(), numbers.size() / 2);
//                 int median = *mid;
//                 if (numbers.size() % 2 == 0) {
//                     // For even-sized list, median is the average of the two middle elements
//                     median = (*std::prev(mid) + *mid) / 2;
//                 }

//                 // Print the median
//                 std::cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, insert X into list at the correct sorted position
//             auto it = std::lower_bound(numbers.begin(), numbers.end(), instruction);
//             numbers.insert(it, instruction);
//         }
//     }

//     // Print a newline after all medians are printed
//     std::cout << std::endl;
// }





// #include "myList.hpp"
// #include <list>
// #include <string>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// // should be taking a vector of integers
// // Custom comparator to compare strings representing integers
// bool compareStrings(const string &s1, const string &s2) {
//     return stoi(s1) < stoi(s2);
// }

// // THIS SHOULD BE "int"
// void listMedian(const vector<string>* instructions) {
//     // List to store the numbers
//     list<int> numbers;

//     // Iterator to keep track of the current position in the list
//     list<int>::iterator it;

//     // Iterate over each instruction
//     for (const string& instruction : *instructions) {
//         if (instruction == "pop median") {
//             // If instruction is pop median and list is not empty, calculate median
//             if (!numbers.empty()) {
//                 // Sort the list to find the median
//                 numbers.sort();

//                 // Move the iterator to the middle position
//                 it = numbers.begin();
//                 advance(it, numbers.size() / 2);

//                 // Find the median
//                 int median;
//                 if (numbers.size() % 2 == 0) {
//                     // For even-sized list, median is the average of the two middle elements
//                     int mid1 = *prev(it);
//                     int mid2 = *it;
//                     median = (mid1 + mid2) / 2;
//                 } else {
//                     // For odd-sized list, median is the middle element
//                     median = *it;
//                 }

//                 // Print the median
//                 cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, extract the number X and insert into list
//             int num = stoi(instruction.substr(7)); // Extract X from "insert X"
//             numbers.push_back(num);
//         }
//     }

//     // Print a newline after all medians are printed
//     cout << endl;
// }
