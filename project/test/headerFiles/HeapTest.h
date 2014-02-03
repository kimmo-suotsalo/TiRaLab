/*
 * Heap test header file.
 *
 * Author: kimpe
 */

#include "../../src/headerFiles/Heap.h"

#ifndef HEAPTEST_H_
#define HEAPTEST_H_

#include <cassert>

class HeapTest {

public:
	HeapTest();
	void run();
private:
	Heap heap;
	void testHeapIsEmptyWhenInitialized();
	void insertSomeNodes();
	void testHeapSizeCorrespondsTheNumberOfNodes();
	void testGetParentReturnsCorrectIndex();
	void testGetLeftReturnsCorrectIndex();
	void testGetRightReturnsCorrectIndex();
	void testDelMinReturnsCorrectNodes();
};

#endif /* HEAPTEST_H_ */
