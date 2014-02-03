/*
 * Heap node comparator header file.
 *
 * Author: kimpe
 */

#ifndef HEAPCOMPARATOR_H_
#define HEAPCOMPARATOR_H_

class HeapComparator {

public:

	/* Compares two heap nodes by their keys (i.e. distances).
	 * Parameters: heap node a, heap node b.
	 * Returns: true if a's key is greater than b's key, otherwise false. */
	bool operator() (int*, int*);

};

#endif /* HEAPCOMPARATOR_H_ */
