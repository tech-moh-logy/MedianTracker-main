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
// #include "myVector.hpp"


#include "myVector.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

void vectorMedian(const std::vector<int>* instructions) {
    std::vector<int> dataList; // Vector to store the current set of numbers
    std::vector<int> medians;  // Vector to store the medians after each -1 instruction

    // Loop through each instruction in the vector
    for (std::vector<int>::const_iterator it = instructions->begin(); it != instructions->end(); ++it) {
        int inst = *it;
        // Check if the instruction is not -1 (meaning it's a number to be added)
        if (inst != -1) {
            // Find the position in the sorted list where the new element should be inserted
            std::vector<int>::iterator vecIter = std::lower_bound(dataList.begin(), dataList.end(), inst);
            // Insert the new element in the sorted position to keep 'dataList' sorted
            dataList.insert(vecIter, inst);
        }
        else {
            // If the instruction is -1, compute and remove the median
            if (!dataList.empty()) {
                // Calculate the index of the median
                size_t medianIndex = (dataList.size() - 1) / 2;
                // Add the median to the 'medians' vector
                medians.push_back(dataList[medianIndex]);
                // Remove the median from 'dataList' vector
                dataList.erase(dataList.begin() + medianIndex);
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

// #include "myVector.hpp"
// #include <algorithm>
// #include <iostream>
// #include <vector>

// void vectorInsert(std::vector<int>& numbers, int value) {
//     // Insert value into vector at the correct sorted position
//     auto it = std::lower_bound(numbers.begin(), numbers.end(), value);
//     numbers.insert(it, value);
// }

// int vectorPopMedian(std::vector<int>& numbers) {
//     if (numbers.empty()) {
//         return -1; // Indicating no median for an empty list
//     }

//     int median;
//     // Find the median
//     auto mid = std::next(numbers.begin(), numbers.size() / 2);
//     median = *mid;
//     if (numbers.size() % 2 == 0) {
//         // For even-sized list, median is the element at size/2 - 1
//         median = *(mid - 1);
//     }

//     // Erase the median from the vector
//     numbers.erase(mid);
//     return median;
// }

// void vectorMedian(const std::vector<int>* instructions) {
//     // Vector to store the numbers
//     std::vector<int> numbers;

//     // Iterate over each instruction
//     for (const int& instruction : *instructions) {
//         if (instruction == -1) { // Assuming -1 indicates "pop median"
//             // If vector is not empty, calculate and pop the median
//             if (!numbers.empty()) {
//                 // Pop and print the median
//                 int median = vectorPopMedian(numbers);
//                 std::cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, insert X into vector at the correct sorted position
//             vectorInsert(numbers, instruction);
//         }
//     }

//     // Print a newline after all medians are printed
//     std::cout << std::endl;
// }
// int vectorPopMedian(std::vector<int>& numbers) {
//     if (numbers.empty()) {
//         return -1; // Indicating no median for an empty list
//     }

//     // Sort the vector to ensure the median calculation is correct
//     std::sort(numbers.begin(), numbers.end());

//     // Find the median index
//     auto mid = numbers.begin() + numbers.size() / 2;
    
//     // Determine if the list has even or odd size
//     bool isEven = numbers.size() % 2 == 0;

//     // Calculate the median value
//     int median = *mid;

//     // Adjust the median value for even-sized lists
//     if (isEven) {
//         median += *std::prev(mid);
//         median /= 2;
//     }

//     return median;
// }

// void vectorMedian(const std::vector<int>& instructions) {
//     // Priority queues to store the lower half (max heap) and upper half (min heap) of elements
//     std::priority_queue<int> lower; // Max heap
//     std::priority_queue<int, std::vector<int>, std::greater<int>> upper; // Min heap    
//     // Iterate over each instruction
//     for (const int& instruction : instructions) {
//         if (instruction == -1) { // Pop median
//             if (lower.empty() && upper.empty()) {
//                 std::cout << "No median\n";
//             } else if (lower.size() == upper.size()) {
//                 std::cout << (lower.top() + upper.top()) / 2.0 << " ";
//             } else {
//                 std::cout << lower.top() << " ";
//             }
//         } else { // Insert
//             if (lower.empty() || instruction <= lower.top()) {
//                 lower.push(instruction);
//             } else {
//                 upper.push(instruction);
//             }

//             // Balance the heaps
//             if (lower.size() > upper.size() + 1) {
//                 upper.push(lower.top());
//                 lower.pop();
//             } else if (upper.size() > lower.size()) {
//                 lower.push(upper.top());
//                 upper.pop();
//             }
//         }
//     }

//     std::cout << std::endl;
// }




// #include "myVector.hpp"
// #include <vector>
// #include <string>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// void vectorMedian(const std::vector<int>* instructions) {
//     // Vector to store the numbers
//     vector<int> numbers;

//     // Iterate over each instruction
//     for (const int& instruction : *instructions) {
//         if (instruction == -1) { // Assuming -1 indicates "pop median"
//             // If instruction is pop median and vector is not empty, calculate median
//             if (!numbers.empty()) {
//                 // Find the median
//                 int median;
//                 if (numbers.size() % 2 == 0) {
//                     // For even-sized vector, median is the average of the two middle elements
//                     int mid1 = numbers[numbers.size() / 2 - 1];
//                     int mid2 = numbers[numbers.size() / 2];
//                     median = (mid1 + mid2) / 2;
//                 } else {
//                     // For odd-sized vector, median is the middle element
//                     median = numbers[numbers.size() / 2];
//                 }

//                 // Print the median
//                 cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, insert X into vector at the correct sorted position
//             auto it = lower_bound(numbers.begin(), numbers.end(), instruction);
//             numbers.insert(it, instruction);
//         }
//     }

//     // Print a newline after all medians are printed
//     cout << endl;
// }




// #include "myVector.hpp"
// #include <vector>
// #include <string>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// // Custom comparator to compare strings representing integers
// // string to integer = stoi
// bool compareStrings(const string &s1, const string &s2) {
//     return stoi(s1) < stoi(s2);
// }

// void vectorMedian(const vector<string>* instructions) {
//     // Vector to store the numbers
//     vector<int> numbers;

//     // Iterate over each instruction
//     for (const string& instruction : *instructions) {
//         if (instruction == "pop median") {
//             // If instruction is pop median and vector is not empty, calculate median
//             if (!numbers.empty()) {
//                 // Sort the vector to find the median
//                 sort(numbers.begin(), numbers.end());

//                 // Find the median
//                 int median;
//                 if (numbers.size() % 2 == 0) {
//                     // For even-sized vector, median is the average of the two middle elements
//                     int mid1 = numbers[numbers.size() / 2 - 1];
//                     int mid2 = numbers[numbers.size() / 2];
//                     median = (mid1 + mid2) / 2;
//                 } else {
//                     // For odd-sized vector, median is the middle element
//                     median = numbers[numbers.size() / 2];
//                 }

//                 // Print the median
//                 cout << median << " ";
//             }
//         } else {
//             // If instruction is insert X, extract the number X and insert into vector
//             // The substr() method extracts a part of a string. 
//             int num = stoi(instruction.substr(7)); // Extract X from "insert X"
//             numbers.push_back(num);
//         }
//     }

//     // Print a newline after all medians are printed
//     cout << endl;
// }
