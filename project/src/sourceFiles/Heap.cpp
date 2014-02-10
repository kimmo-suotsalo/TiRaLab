/*
 * Heap class.
 *
 * Implements a min-heap.
 *
 * Author: kimpe
 */

#include "../headerFiles/Heap.h"
#include <iostream>

Heap::Heap(int arrayLength) :
	array(new int*[arrayLength]), arrayLength(arrayLength), heapSize(-1) {
	for (int i = 0; i < arrayLength; i++) array[i] = new int[2];
}

void Heap::insert(int* heapNode) {
	int ind = ++heapSize;
	while (0 < ind && heapNode[1] < array[getParent(ind)][1]) {
		array[ind][0] = array[getParent(ind)][0];
		array[ind][1] = array[getParent(ind)][1];
		ind = getParent(ind);
	}
	array[ind][0] = heapNode[0];
	array[ind][1] = heapNode[1];
}

int Heap::getParent(int i) {
	return (int)std::floor( (i - 1) / 2);
}

int Heap::getLeft(int i) {
	return 2 * i + 1;
}

int Heap::getRight(int i) {
	return 2 * i + 2;
}

int* Heap::delMin() {
	int* min = array[0];
	array[0] = array[heapSize--];
	heapify(0);
	return min;
}

void Heap::heapify(int i) {
	int left = getLeft(i);
	int right = getRight(i);
	int smallest;
	if (right <= heapSize) {
		if (array[left][1] < array[right][1]) smallest = left;
		else smallest = right;
		if (array[smallest][1] < array[i][1]) {
			swap(array[i], array[smallest]);
			heapify(smallest);
		}
	} else if (left == heapSize && array[left][1] < array[i][1]) swap(array[i], array[left]);
}

void Heap::decKey(int i, int newKey) {
	if (newKey < array[i][1]) {
		array[i][1] = newKey;
		while (0 < i && array[i][1] < array[getParent(i)][1]) {
			swap(array[i], array[getParent(i)]);
			i = getParent(i);
		}
	}
}

void Heap::swap(int* a, int* b) {
	int* temp = new int[2];
	temp[0] = a[0];
	temp[1] = a[1];
	a[0] = b[0];
	a[1] = b[1];
	b[0] = temp[0];
	b[1] = temp[1];
}

bool Heap::isEmpty() {
	return heapSize < 0;
}

int Heap::getHeapSize() {
	return heapSize;
}

std::string Heap::toString() {
	std::stringstream outputStream;
	outputStream << "|";
	for (int i = 0; i < arrayLength; i++) {
		outputStream << array[i][0] << "|";
	}
	return outputStream.str();
}

Heap::~Heap() {
	;
}
