/*
 * Dijkstra searcher test header file.
 *
 * Author: kimpe
 */

#include "../../src/headerFiles/DijkstraSearcher.h"
#include <cassert>

#ifndef DIJKSTRASEARCHERTEST_H_
#define DIJKSTRASEARCHERTEST_H_

class DijkstraSearcherTest {

public:
	DijkstraSearcherTest();
	void run();
private:
	int* mapSize;
	int** mapData;
	void generateMapData();
	void testLocationToNodeReturnsCorrectNode(DijkstraSearcher);
	void testNodeToLocationReturnsCorrectLocation(DijkstraSearcher);
	void testInitializeSingleSourceSetsDistanceAndPathRight(DijkstraSearcher);
	void testSearchLeadsToCorrectSolution(DijkstraSearcher);
};


#endif /* DIJKSTRASEARCHERTEST_H_ */
