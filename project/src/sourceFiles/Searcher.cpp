/*
 * Class for searching shortest paths.
 *
 * Implements Dijkstra's algorithm and A*.
 *
 * Author: kimpe
 */

#include "../headerFiles/Searcher.h"

Searcher::Searcher(int *mapSize, int **mapData) :
	numberOfVisitedNodes(0),
	arraySize(mapSize),
	dataArray(mapData),
	numberOfNodes( mapSize[0] * mapSize[1] ),
	heap(numberOfNodes) {
		distance = new int[numberOfNodes];
		path = new int[numberOfNodes];
		isDealtWith = new bool[numberOfNodes];
}

void Searcher::initializeSingleSource() {
	for (int nodeNumber = 0; nodeNumber < numberOfNodes; nodeNumber++) {
		distance[nodeNumber] = infinity;
		path[nodeNumber] = null;
		isDealtWith[nodeNumber] = false;
	}
	distance[startNode] = 0;
}

void Searcher::heapInsertAll() {
	for (int row = 0; row < arraySize[0]; row++) {
		for (int col = 0; col < arraySize[1]; col++) {
			int *heapNode = new int[2];
			int location[2] = {row, col};
			heapNode[0] = locationToNode(location);
			heapNode[1] = distance[ heapNode[0] ];
			heapNode[2] = heuristic(location);
			heap.insert(heapNode);
		}
	}
}

int Searcher::heuristic(int* currentLocation) {
	if (algorithm == "Dijkstra's algorithm") return 0;
	int* endLocation = nodeToLocation(endNode);
	return abs( endLocation[0] - currentLocation[0] ) + abs( endLocation[1] - currentLocation[1] );
}

void Searcher::search() {
	while ( !heap.isEmpty() ) {
		int* heapMin = heap.delMin();
		int u = heapMin[0];
		if (u == endNode) break;

		int* location = nodeToLocation(u);
		int row = location[0];
		int col = location[1];
		if (echoMode == "on") displayTopNode(u, location, row, col);

		numberOfVisitedNodes++;
		isDealtWith[u] = true;

		if (0 < row) dealWithNeighbor(u, row - 1, col);
		if (row < arraySize[0] - 1) dealWithNeighbor(u, row + 1, col);
		if (0 < col) dealWithNeighbor(u, row, col - 1);
		if (col < arraySize[1] - 1) dealWithNeighbor(u, row, col + 1);
	}
}

void Searcher::dealWithNeighbor(int u, int row, int col) {
	int location[] = {row, col};
	int v = locationToNode(location);
	if (!isDealtWith[v]) {
		if (echoMode == "on") displayNeighbor(v, location, row, col);
		relax(u, v);
	}
}

void Searcher::relax(int u, int v) {
	int* location = nodeToLocation(v);
	int row = location[0];
	int col = location[1];
	int w = dataArray[row][col];
	int newDistance = infinity;
	if (distance[u] < newDistance && 0 < w) newDistance = distance[u] + w;

	if (distance[v] > newDistance) {
		distance[v] = newDistance;
		if (echoMode == "on") displayUpdate(v, location, row, col, newDistance);
		path[v] = u;
	}

	heap.decKey( v, distance[v], heuristic(location) );
}

int Searcher::locationToNode(int* location) {
	return location[0] * arraySize[1] + location[1];
}

int* Searcher::nodeToLocation(int nodeId) {
	int *location = new int[2];
	location[0] = std::floor(nodeId / arraySize[1]);
	location[1] = nodeId % arraySize[1];
	return location;
}

void Searcher::displayTopNode(int u, int* location, int row, int col) {
	std::cout << "(T) Top node is " << u << " located at (" << row << ", "
					  << col << ") with value ";
	int inf = infinity;
	if (distance[u] < inf) std::cout << distance[u] + heuristic(location);
	else std::cout << "'infinity'";
	std::cout << ".\n" << std::endl;
}

void Searcher::displayNeighbor(int v, int* location, int row, int col) {
	std::cout << "(N) Dealing with neighbor " << v << " located at (" << row << ", "
			  << col << ") with value ";
	int inf = infinity;
	if (distance[v] < inf) std::cout << distance[v] + heuristic(location);
	else std::cout << "'infinity'";
	std::cout << ".\n" << std::endl;
}

void Searcher::displayUpdate(int v, int* location, int row, int col, int newDistance) {
	std::cout << "(U) Updating node " << v << ": value ";
	int inf = infinity;
	if (distance[v] < inf) std::cout << distance[v] + heuristic(location);
	else std::cout << "'infinity'";
	std::cout << " changed to " << newDistance + heuristic(location) << ".\n" << std::endl;
}

std::string Searcher::getAlgorithm() {
	return algorithm;
}

int* Searcher::getPath() {
	return path;
}

int* Searcher::getDistance() {
	return distance;
}

int Searcher::getNumberOfVisitedNodes() {
	return numberOfVisitedNodes;
}
void Searcher::setAlgorithm(std::string algorithmType) {
	algorithm = algorithmType;
}

void Searcher::setEchoMode(std::string mode) {
	echoMode = mode;
}

void Searcher::setStartNode(int* location) {
	startNode = locationToNode(location);
}

void Searcher::setEndNode(int* location) {
	endNode = locationToNode(location);
}
