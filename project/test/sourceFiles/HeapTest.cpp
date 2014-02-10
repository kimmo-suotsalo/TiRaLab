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
	int *heapNode = new int[2];
	heapNode[0] = 0; heapNode[1] = 8; heap.insert(heapNode);
	heapNode[0] = 1; heapNode[1] = 5; heap.insert(heapNode);
	heapNode[0] = 2; heapNode[1] = 17; heap.insert(heapNode);
	heapNode[0] = 3; heapNode[1] = 0; heap.insert(heapNode);
	heapNode[0] = 4; heapNode[1] = 1; heap.insert(heapNode);
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
	assert(heap.delMin()[0] == 3);
	assert(heap.delMin()[0] == 4);
	assert(heap.delMin()[0] == 1);
	assert(heap.delMin()[0] == 0);
	assert(heap.delMin()[0] == 2);
}

