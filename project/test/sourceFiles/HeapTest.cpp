/*
 * Heap test class.
 *
 * Author: kimpe
 */

#include "../headerFiles/HeapTest.h"

HeapTest::HeapTest() : heap(10) { }

void HeapTest::run() {
	testHeapIsEmptyWhenInitialized();
	insertSomeNodes();
	testHeapSizeCorrespondsTheNumberOfNodes();
	testGetParentReturnsCorrectIndex();
	testGetLeftReturnsCorrectIndex();
	testGetRightReturnsCorrectIndex();
	testDelMinReturnsCorrectNodes();
}

void HeapTest::testHeapIsEmptyWhenInitialized() {
	assert( heap.isEmpty() );
}

void HeapTest::insertSomeNodes() {
	heap.insert(8);
	heap.insert(5);
	heap.insert(17);
	heap.insert(0);
	heap.insert(1);
}

void HeapTest::testHeapSizeCorrespondsTheNumberOfNodes() {
	int numberOfNodes = 5;
	assert( heap.getHeapSize() == numberOfNodes - 1);
}

void HeapTest::testGetParentReturnsCorrectIndex() {
	int ind = heap.getHeapSize();
	assert( heap.getParent(ind) == 1);
	ind = heap.getParent(ind);
	assert( heap.getParent(ind) == 0);
}

void HeapTest::testGetLeftReturnsCorrectIndex() {
	int ind = 0;
	assert( heap.getLeft(ind) == 1);
	ind = heap.getLeft(ind);
	assert( heap.getLeft(ind) == 3);
}

void HeapTest::testGetRightReturnsCorrectIndex() {
	int ind = 0;
	assert( heap.getRight(ind) == 2);
	ind = 1;
	assert( heap.getRight(ind) == 4);
}

void HeapTest::testDelMinReturnsCorrectNodes() {
	assert(heap.delMin() == 0);
	assert(heap.delMin() == 1);
	assert(heap.delMin() == 5);
	assert(heap.delMin() == 8);
	assert(heap.delMin() == 17);
}

