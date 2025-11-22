#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

// A wise person once said: "To understand the heap, become the heap."
// Let's start by building its home.

class MaxHeap {
private:
    // The tree is stored here. It's just a dynamic array!
    std::vector<int> heap;

    // --- The Magic Formulas in Action ---
    // Given an index i, these helpers find its family.


    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }
public:
    // Default constructor for an empty heap
    MaxHeap() = default;

    // Constructor to build a heap from an existing vector (efficient O(N) method)
    MaxHeap(const std::vector<int>& elements) {
        // 1. Copy the elements. The heap property is not yet satisfied.
        heap = elements;

        // 2. Find the index of the last non-leaf node.
        int lastNonLeafNode = (heap.size() / 2) - 1;

        // 3. Iterate backwards from the last non-leaf node to the root.
        for (int i = lastNonLeafNode; i >= 0; i--) {
            heapifyDown(i); // Sink each node to its correct position.
        }
    }

    // Is the heap empty?
    bool isEmpty() const {
        return heap.empty();
    }

    // How many elements are in the heap?
    int getSize() const {
        return heap.size();
    }

    void insert(int element) {
        // 1. Add the new element to the end to keep the tree complete.
        heap.push_back(element);
        // 2. Fix the heap property by bubbling the new element up.
        heapifyUp(heap.size() - 1);
    }

    // Moves an element up the heap to its correct position.
    void heapifyUp(int index) {
        // A child at 'index' challenges its parent as long as it's not the root
        // and it's greater than its parent.
        while (index > 0 && heap[index] > heap[parent(index)]) {
            // If child is greater, swap with parent.
            std::swap(heap[index], heap[parent(index)]);
            // Move up to the parent's index to continue the check.
            index = parent(index);
        }
    }

    // Moves an element down the heap to its correct position.
    void heapifyDown(int index) {
        int heapSize = heap.size();
        // Loop as long as the node at 'index' is not a leaf.
        // A node is not a leaf if its left child is within the heap bounds.
        while (leftChild(index) < heapSize) {
            int largestChildIndex = leftChild(index);
            int rightChildIndex = rightChild(index);

            // Check if a right child exists and if it's larger than the left child.
            if (rightChildIndex < heapSize && heap[rightChildIndex] > heap[largestChildIndex]) {
                largestChildIndex = rightChildIndex;
            }

            // Now, largestChildIndex holds the index of the bigger of the two children.
            // If the parent is already bigger than its biggest child, the heap property is satisfied.
            if (heap[index] >= heap[largestChildIndex]) {
                break; // We are done.
            }

            // Otherwise, swap the parent with its largest child.
            std::swap(heap[index], heap[largestChildIndex]);

            // And continue the process from the child's position.
            index = largestChildIndex;
        }
    }

    // Removes and returns the maximum element.
    int extractMax() {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty!");
        }
        int maxElement = heap[0]; // 1. Save the max element.

        // 2. Move the last element to the root and shrink the heap.
        heap[0] = heap.back();
        heap.pop_back();

        // 3. Fix the heap property by sinking the new root down.
        heapifyDown(0);

        return maxElement;
    }

    // Get the maximum element (it's always at the top!)
    int getMax() const {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty!");
        }
        return heap[0];
    }
};