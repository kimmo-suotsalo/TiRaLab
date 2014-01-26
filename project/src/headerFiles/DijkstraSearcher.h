/*
 * Dijkstra's graph search algorithm header file.
 *
 * Author: kimpe
 */

#include <cstdio>
#include <iostream>
#include <limits>
#include <queue>
#include "../headerFiles/Node.h"
#include "../headerFiles/NodeComparator.h"

#ifndef DIJKSTRASEARCHER_H_
#define DIJKSTRASEARCHER_H_

#define infinity std::numeric_limits<int>::max();
#define null -1;

class DijkstraSearcher {

public:

	/* Constructs a new graph searcher.
	 * Parameters: map array size, map data array. */
	DijkstraSearcher(int *, int **);

	/* Initializes the distance and path arrays. */
	void initializeSingleSource();

	/* Initializes the distance and path arrays. */
	void testHeap();

	/* Returns the data array's size (i.e. number of rows and columns). */
	int *getArraySize();

	/* Returns number of nodes in the graph. */
	int getNumberOfNodes();

	/* Returns the shortest path found.
	 * Parameter: end position to be reached. */
	int *getShortestPath(int *endPosition);

private:

	/* An ordered pair of integers that determines the number of rows and columns in
	 * the data array. */
	int *arraySize;

	/* An array of integers that contains the map data. */
	int **dataArray;

	/* Number of nodes in the graph. */
	int numberOfNodes;

	/* An array of integers whose element v equals the up-to-date minimum distance from
	 * node v to the start. */
	int *distance;

	/* An array of integers whose element v equals the number of the previous node
	 * as seen from node v. */
	int *path;

	/* A priority queue for simulating a min-heap. */
	std::priority_queue<Node, std::vector<Node>, NodeComparator > heapDummy;
};

#endif /* DIJKSTRASEARCHER_H_ */
