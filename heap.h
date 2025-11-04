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

        int rootIndex = data[0];
        // Replace root with last element
        data[0] = data[size - 1];
        // Remove one from size of heap
        size--;
        // Call downheap to restore order
        downheap(0, weightArr);

        return rootIndex;
    }

    // Swap child upward while smaller than parent
    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    // Move an element down until heap property is restored
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif