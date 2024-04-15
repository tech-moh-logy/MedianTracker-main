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


#include <iostream>
#include <vector>

// Define a node structure for the AVL tree
struct Node {
    int val, height;
    Node *left, *right;

    // Constructor to initialize node with a value
    Node(int val) : val{val}, left{nullptr}, right{nullptr}, height{1} {}
};

// Define the AVL tree structure
struct AVLtree {
public:
    // Constructor to initialize an empty AVL tree
    AVLtree() : root{nullptr}, node_count{0} {}

    // Get the size of the AVL tree
    int getSize() {
        return node_count;
    }

    // Get the maximum value in the AVL tree
    int getMax() {
        Node *node = root;

        while (node->right != nullptr) {
            node = node->right;
        }

        return node->val;
    }

    // Insert a value into the AVL tree
    void insert(int num) {
        node_count++;
        root = insertNode(root, num);
    }

    // Remove and return the minimum value from the AVL tree
    int popMinimum() {
        if (root == nullptr) {
            return -1;
        }

        node_count--;
        Node *node = root;

        while (node->left != nullptr) {
            node = node->left;
        }
        int num = node->val;
        root = deleteNode(root, node->val);

        return num;
    }

    // Remove and return the maximum value from the AVL tree
    int popMaximum() {
        if (root == nullptr) {
            return -1;
        }

        node_count--;
        Node *node = root;

        while (node->right != nullptr) {
            node = node->right;
        }
        int num = node->val;
        root = deleteNode(root, node->val);

        return num;
    }

private:
    Node* root;
    int node_count;  

    // Get the height of a node in the AVL tree
    int getHeight(Node* node) {
        if (node == nullptr)  {
            return 0;
        }
        
        return node->height;
    }

    // Find the node with the minimum value in a subtree
    Node* minimumNode(Node* node) {
        Node *ptr = node;

        while (ptr->left != nullptr) {
            ptr = ptr->left;
        }

        return ptr;
    }  

    // Calculate the balance factor of a node
    int balance_factor (Node* node) {
        if (node == nullptr) {
            return 0;
        }
        
        return getHeight(node->left) - getHeight(node->right);
    }    

    // Rotate the subtree rooted at 'x' to the left
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Rotate the subtree rooted at 'y' to the right
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    } 

    // Insert a node with a given value into the AVL tree
    Node* insertNode(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val <= node->val) {
            node->left = insertNode(node->left, val);
        }
        else if (val > node->val) {
            node->right = insertNode(node->right, val);
        }

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = balance_factor(node);

        // Rebalance the tree if necessary
        if (balance > 1) {
            if (val <= node->left->val) {
                return rightRotate(node);
            }
            else if (val > node->left->val) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balance < -1) {
            if (val > node->right->val) {
                return leftRotate(node);
            }
            else if (val <= node->right->val) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    // Delete a node with a given value from the AVL tree
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }

        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        }
        else {
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp;
                if (node->left != nullptr) {
                    temp = node->left;
                }
                else {
                    temp = node->right;
                }

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }

                delete temp;
            }
            else {
                Node* temp = minimumNode(node->right);
                node->val = temp->val;
                node->right = deleteNode(node->right, temp->val);
            }
        }

        if (node == nullptr) {
            return node;
        }

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = balance_factor(node);

        // Rebalance the tree if necessary
        if (balance > 1) {
            if (balance_factor(node->left) >= 0) {
                return rightRotate(node);
            }
            else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balance < -1) {
            if (balance_factor(node->right) <= 0) {
                return leftRotate(node);
            }
            else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }
};
