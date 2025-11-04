//
// Created by Mateo Contreras
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    // Insert index at end of heap, restore order using upheap()
    void push(int idx, int weightArr[]) {
        // Insert index at the end of heap
        data[size] = idx;
        // Add one to size of heap
        size++;
        // Call upheap to restore order
        upheap(size - 1, weightArr);
    }

    // Remove and return the smallest index, replace root with last element, then call downheap()
    int pop(int weightArr[]) {
        // If heap empty
        if (size == 0) {
            return -1;
        }

        int rootIdx = data[0];
        // Replace root with last element
        data[0] = data[size - 1];
        // Remove one from size of heap
        size--;
        // Call downheap to restore order
        downheap(0, weightArr);

        return rootIdx;
    }

    // Swap child upward while smaller than parent
    void upheap(int pos, int weightArr[]) {
        // While the position in heap is not at the root (below root)
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            // Swap upward if child is smaller than its parent
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else { // If not, then done
                break;
            }
        }
    }

    // Swap parent downward while larger than any child
    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            // Find the smallest between parent and its children
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            // If parent isn't smallest, swap and continue
            if (smallest != pos) {
                swap(data[pos], data[smallest]);
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif