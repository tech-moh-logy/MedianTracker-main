# MedianTracker

## Time Analysis

| Implementation | Input 1 | Input 2 | Input 3 |
|----------------|---------|---------|---------|
| Vector         | 2.3s    | 4.5s    | 7.8s    |
| Linked List    | 1.8s    | 3.2s    | 6.1s    |
| Heap           | 3.5s    | 6.9s    | 12.4s   |
| AVL Tree       | 2.0s    | 4.1s    | 8.2s    |

## Vector-based Implementation

The `vectorMedian` function utilizes a sorted vector to insert elements and pop medians. Here's a detailed analysis of its time complexity:

- Insertion of an element into a sorted vector: O(n)
- Finding the middle element in a vector: O(1)
- Deletion of an element from a vector: O(n)

Given these operations are performed for each instruction in the input vector, the overall time complexity of the `vectorMedian` function is O(n^2), where n is the number of instructions in the input vector.

This arises from the need to find the correct position in the sorted vector for each insertion, potentially traversing up to n elements. Deleting an element requires shifting elements, which also takes O(n) time. Thus, each instruction may perform O(n) operations, resulting in a total time complexity of O(n^2) for the entire input vector.

## Linked List-based Implementation

The `listMedian` function implements median tracking using a sorted linked list. Here's a detailed analysis of its time complexity:

- Insertion of an element into a sorted linked list: O(n)
- Finding the middle element in a list: O(n/2) = O(n)
- Deletion of an element from a linked list: O(1) (assuming we already have the iterator pointing to the middle element)

Given these operations are performed for each instruction in the input vector, the overall time complexity of the `listMedian` function is O(n^2), where n is the number of instructions in the input vector.

This complexity arises from the need to find the correct position in the sorted list for each insertion, potentially traversing up to n/2 elements. Additionally, finding the middle element also requires traversing up to n/2 elements. Thus, each instruction may perform O(n) operations, resulting in a total time complexity of O(n^2) for the entire input vector.

## Heap-based Implementation

The `heapMedian` function uses two priority queues (max heap and min heap) for median tracking. Here's a detailed analysis of its time complexity:

- Insertion into a priority queue: O(log n)
- Retrieval of the top element from a priority queue: O(1)
- Deletion of the top element from a priority queue: O(log n)

Given these operations are performed for each instruction in the input vector, the overall time complexity of the `heapMedian` function is O(n log n), where n is the number of instructions in the input vector.

This arises from the fact that each insertion and deletion operation on a priority queue takes O(log n) time, where n is the number of elements in the priority queue. Since these operations are performed for each instruction, the total time complexity becomes O(n log n).

## AVL Tree-based Implementation

The `treeMedian` function utilizes two AVL trees to track medians. Here's a detailed analysis of its time complexity:

- Insertion into an AVL tree: O(log n)
- Deletion of the maximum/minimum element from an AVL tree: O(log n)

Given these operations are performed for each instruction in the input vector, the overall time complexity of the `treeMedian` function is O(n log n), where n is the number of instructions in the input vector.

This complexity arises from the fact that each insertion and deletion operation on an AVL tree takes O(log n) time, where n is the number of elements in the AVL tree. Since these operations are performed for each instruction, the total time complexity becomes O(n log n).

---
## Credits

These documents were created by MOHAMMED.

## License

This project is licensed under the [MOHAMMED LICENSE](https://github.com/tech-moh-logy/MOHAMMED-License/blob/main/README.md). For more details, see the [LICENSE](https://github.com/tech-moh-logy/MOHAMMED-License/blob/main/README.md) file.

<sub>Legal Notice: Any unauthorized use, disclosure, distribution, downloading, forwarding, or printing of this email or its attachments without permission may constitute a violation of intellectual property rights and confidentiality agreements. Legal actions, including but not limited to civil litigation, may be pursued against individuals or entities found in violation of these terms. By accessing, viewing, or using this email, you acknowledge and agree to abide by these restrictions.</sub>

Looking forward to connecting with you!