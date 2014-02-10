/*
 * Dijkstra's graph search algorithm header file.
 *
 * Author: kimpe
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include "../headerFiles/Heap.h"

#ifndef DIJKSTRASEARCHER_H_
#define DIJKSTRASEARCHER_H_

//#define infinity std::numeric_limits<int>::max();
#define infinity 1000000;
#define null -1;

class DijkstraSearcher {

public:

	/* Constructs a new graph searcher.
	 * Parameters: map array size, map data array. */
	DijkstraSearcher(int *, int **);

	/* Initializes the distance and path arrays. */
	/* Parameter: start location on the map. */
	void initializeSingleSource(int*);

	/* Inserts all nodes into the heap. */
	void heapInsertAll();

	/* Searches all shortest paths from the start node. */
	void search();

	/* Maps a given location to a node.
	 * Parameter: location as an array [row, column].
	 * Returns: node id. */
	int locationToNode(int *);

	/* Maps a given node to a location.
	 * Parameter: node id.
	 * Returns: location as an array [row, column]. */
	int* nodeToLocation(int);

	/* Gets the path array.
	 * Returns: path array where a = path[b] iff node a precedes node b on the shortest path. */
	int* getPath();

	/* Gets the distance array.
	 * Returns: distance array where distance[c] equals node c's distance from the start. */
	int* getDistance();

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

	/* Starting node for the search. */
	int startNode;

	/* A min-heap to store the nodes in priority order. */
	Heap heap;

	/* Deals with the node's neighbor.
	 * Parameters: current node, neighboring node's row, neighboring node's column. */
	void dealWithNeighbor(int, int, int);

	/* Updates the neighboring node's distance and its place in the heap.
	 * Parameters: current node, neighboring node. */
	void relax(int, int);
};

#endif /* DIJKSTRASEARCHER_H_ */
