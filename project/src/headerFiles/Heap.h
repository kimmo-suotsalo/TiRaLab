/*
 * Heap header file.
 *
 * Author: kimpe
 */

#include <cmath>
#include <sstream>
#include <string>

#ifndef HEAP_H_
#define HEAP_H_

class Heap {

public:

	/* Constructs a new heap.
	 * Parameter: length of array to store the heap nodes. */
	Heap(int);

	/* Inserts a node to the heap.
	 * Parameter: node's key. */
	void insert(int);

	/* Gets the index of a node's parent in the array.
	 * Parameter: node's index.
	 * Returns: parent's index. */
	int getParent(int);

	/* Gets the index of a node's left child in the array.
	 * Parameter: node's index.
	 * Returns: child's index. */
	int getLeft(int);

	/* Gets the index of a node's right child in the array.
	 * Parameter: node's index.
	 * Returns: child's index. */
	int getRight(int);

	/* Deletes the node u with the smallest key.
	 * Returns: node u. */
	int delMin();

	/* Fixes the heap in case it is broken at node v.
	 * Parameter: node v's key. */
	void heapify(int);

	/* Decreases a node's key.
	 * Parameters: node's index in the array, new key value. */
	void decKey(int, int);

	/* Determines whether there are any nodes in the heap.
	 * Returns: true if the heap is empty, false otherwise. */
	bool isEmpty();

	/* Gets the heap's size.
	 * Returns: Index of the heap's last element in the array. */
	int getHeapSize();

	/* Offers a simple way to visualize the heap's contents.
	 * Returns: a string representation of the heap. */
	std::string toString();

	/* Destructs the heap. */
	virtual ~Heap();

private:

	/* An array to store the heap nodes. */
	int *array;

	/* Length of the array. */
	int arrayLength;

	/* Index of the heap's last element in the array. */
	int heapSize;

	/* Swaps the contents of two integer variables.
	 * Parameters: variable a, variable b. */
	void swap(int &, int &);
};

#endif /* HEAP_H_ */
