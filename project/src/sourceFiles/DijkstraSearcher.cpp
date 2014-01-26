/*
 * Class for searching shortest paths.
 *
 * Implements Dijkstra's algorithm.
 *
 * Author: kimpe
 */

#include "../headerFiles/DijkstraSearcher.h"
#include "../headerFiles/NodeComparator.h"

DijkstraSearcher::DijkstraSearcher(int *mapSize, int **mapData) :
	arraySize(mapSize), dataArray(mapData), numberOfNodes(mapSize[0] * mapSize[1]) {
		distance = new int[getNumberOfNodes()];
		path = new int[getNumberOfNodes()];
}

int DijkstraSearcher::getNumberOfNodes() {
	return numberOfNodes;
}

void DijkstraSearcher::initializeSingleSource() {
	for (int nodeNumber = 0; nodeNumber < getNumberOfNodes(); nodeNumber++) {
		distance[nodeNumber] = infinity;
		path[nodeNumber] = null;
	}
	distance[0] = 0; // define node number 0 as startPosition
}

void DijkstraSearcher::testHeap() {
	heapDummy.push( Node(1, 7) );
	heapDummy.push( Node(2, 4) );
	heapDummy.push( Node(3, 5) );
	Node top = heapDummy.top();
	std::cout << "Top node is " << top.getId() << " with value "
			  << top.getDistance() << ".\n" << std::endl;
}
