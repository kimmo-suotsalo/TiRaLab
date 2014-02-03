/*
 * Heap class.
 *
 * Implements a min-heap.
 *
 * Author: kimpe
 */

#include "../headerFiles/Heap.h"

Heap::Heap(int arrayLength) :
	array(new int[arrayLength]), arrayLength(arrayLength), heapSize(-1) {
	for (int i = 0; i < arrayLength; i++) array[i] = -1;
}

void Heap::insert(int k) {
	int i = ++heapSize;
	while (0 < i && k < array[getParent(i)]) {
		array[i] = array[getParent(i)];
		i = getParent(i);
	}
	array[i] = k;
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

int Heap::delMin() {
	int min = array[0];
	array[0] = array[heapSize--];
	heapify(0);
	return min;
}

void Heap::heapify(int i) {
	int left = getLeft(i);
	int right = getRight(i);
	int smallest;
	if (right <= heapSize) {
		if (array[left] < array[right]) smallest = left;
		else smallest = right;
		if (array[smallest] < array[i]) {
			swap(array[i], array[smallest]);
			heapify(smallest);
		}
	} else if (left == heapSize && array[left] < array[i]) swap(array[i], array[left]);
}

void Heap::decKey(int i, int newKey) {
	if (newKey < array[i]) {
		array[i] = newKey;
		while (0 < i && array[i] < array[getParent(i)]) {
			swap(array[i], array[getParent(i)]);
			i = getParent(i);
		}
	}
}

void Heap::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
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
		outputStream << array[i] << "|";
	}
	return outputStream.str();
}

Heap::~Heap() {
	;
}
