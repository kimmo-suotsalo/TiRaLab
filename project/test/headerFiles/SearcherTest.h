/*
 * Dijkstra searcher test header file.
 *
 * Author: kimpe
 */

#include "../../src/headerFiles/Searcher.h"
#include <cassert>

#ifndef DIJKSTRASEARCHERTEST_H_
#define SEARCHERTEST_H_

class SearcherTest {

public:
	SearcherTest();
	void run();
private:
	int* mapSize;
	int** mapData;
	int* startLocation;
	int* endLocation;
	void generateMapData();
	void testSearchLeadsToCorrectSolution(Searcher, std::string);
	void testLocationToNodeReturnsCorrectNode(Searcher);
	void testNodeToLocationReturnsCorrectLocation(Searcher);
	void testInitializeSingleSourceSetsDistanceAndPathRight(Searcher);
};


#endif /* DIJKSTRASEARCHERTEST_H_ */
