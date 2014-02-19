/*
 * Graph search algorithm header file.
 *
 * Author: kimpe
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
#include "../headerFiles/Heap.h"

#ifndef SEARCHER_H_
#define SEARCHER_H_

#define infinity (std::numeric_limits<int>::max() / 100) * 99 ;
#define null -1;

class Searcher {

public:

	/* Constructs a new graph searcher.
	 * Parameters: map array size, map data array. */
	Searcher(int *, int **);

	/* Initializes distance, path and isDealtWith arrays. */
	void initializeSingleSource();

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

	/* Gets the algorithm used in the search.
	 * Returns: a string representation of the algorithm. */
	std::string getAlgorithm();

	/* Gets the path array.
	 * Returns: path array where a = path[b] iff node a precedes node b on the shortest path. */
	int* getPath();

	/* Gets the distance array.
	 * Returns: distance array where distance[c] equals node c's distance from the start. */
	int* getDistance();

	/* Gets the number of nodes visited by the algorithm during the search.
	 * Returns: number of visited nodes. */
	int getNumberOfVisitedNodes();

	/* Sets the algorithm to be used in the search.
	 * Parameter: string representation of the algorithm. */
	void setAlgorithm(std::string);

	/* Sets echo mode.
	 * Parameter: on/off. */
	void setEchoMode(std::string);

	/* Sets the start node for the search.
	 * Parameter: start node's location as an array [row, col]. */
	void setStartNode(int*);

	/* Sets the end node for the search.
	 * Parameter: end node's location as an array [row, col]. */
	void setEndNode(int*);

private:

	/* Number of nodes visited during the search. */
	int numberOfVisitedNodes;

	/* Algorithm to be used in the search. */
	std::string algorithm;

	/* Determines whether node information is displayed during the search. */
	std::string echoMode;

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

	/* An array of booleans whose element v tells whether node v has already been
	 *  dealt with. */
	bool *isDealtWith;

	/* Start node for the search. */
	int startNode;

	/* End node for the search. */
	int endNode;

	/* A min-heap to store the nodes in priority order. */
	Heap heap;

	/* Determines the expected distance to go in order to reach the end node. If Dijkstra's
	 * algorithm is used, this distance is irrelevant and a constant value is returned.
	 * Parameter: current node's location as an array [row, column].
	 * Returns: |x_current - x_end| + |y_current - y_end| if A* is used, otherwise 0. */
	int heuristic(int*);

	/* Deals with the node's neighbor.
	 * Parameters: current node, neighboring node's row, neighboring node's column. */
	void dealWithNeighbor(int, int, int);

	/* Updates the neighboring node's distance and its place in the heap.
	 * Parameters: current node, neighboring node. */
	void relax(int, int);

	/* Displays information about the top node u.
	 * Parameters: u, u's location, u's row, u's column. */
	void displayTopNode(int, int*, int, int);

	/* Displays information about neighbor node v.
	 * Parameters: v, v's location, v's row, v's column. */
	void displayNeighbor(int, int*, int, int);

	/* Displays information about node v's update.
	 * Parameters: v, v's location, v's row, v's column, v's new distance. */
	void displayUpdate(int, int*, int, int, int);
};

#endif /* SEARCHER_H_ */
