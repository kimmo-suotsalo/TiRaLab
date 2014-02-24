/*
 * Dijkstra searcher test class
 *
 * Author: kimpe
 */

#include "../headerFiles/SearcherTest.h"

SearcherTest::SearcherTest() :
	mapSize(new int[2]), mapData(new int*[8]),
	startLocation(new int[2]), endLocation(new int[2]) {
		mapSize[0] = 8;
		mapSize[1] = 13;
		for (int row = 0; row < 8; row++) mapData[row] = new int[13];
		generateMapData();
		startLocation[0] = 0;
		startLocation[1] = 3;
		endLocation[0] = 7;
		endLocation[1] = 4;
	}

void SearcherTest::run() {
	Searcher searcher = Searcher(mapSize, mapData);
	std::string algorithm = "Dijkstra's algorithm";
	for (int i = 0; i < 2; i++) {
		if (i == 1) searcher = Searcher(mapSize, mapData);
		searcher.setStartNode(startLocation);
		searcher.setEndNode(endLocation);
		if (i == 1) algorithm = "A*";
		testSearchLeadsToCorrectSolution(searcher, algorithm);
	}
	testLocationToNodeReturnsCorrectNode(searcher);
	testNodeToLocationReturnsCorrectLocation(searcher);
	testInitializeSingleSourceSetsDistanceAndPathRight(searcher);
}

void SearcherTest::generateMapData() {

	int dataArray[8][13] = { {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0} };

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 13; col++) {
			mapData[row][col] = dataArray[row][col];
		}
	}
}

void SearcherTest::testSearchLeadsToCorrectSolution(Searcher searcher, std::string algorithm) {
	searcher.setAlgorithm(algorithm);
	searcher.initializeSingleSource();
	searcher.heapInsertAll();
	searcher.search();
	int* path = searcher.getPath();
	int* distance = searcher.getDistance();
	assert(path[16] == 3  && distance[16] == 1);
	assert(path[20] == 19 && distance[20] == 5);
	assert(path[62] == 49 && distance[62] == 11);
	assert(path[69] == 70 && distance[69] == 18);
	assert(path[95] == 82 && distance[95] == 20);
}

void SearcherTest::testLocationToNodeReturnsCorrectNode(Searcher searcher) {
	int* location = new int[2];
	location[0] = 0; location[1] = 0;  assert(searcher.locationToNode(location) == 0);
	location[0] = 2; location[1] = 12; assert(searcher.locationToNode(location) == 38);
	location[0] = 3; location[1] = 0;  assert(searcher.locationToNode(location) == 39);
	location[0] = 4; location[1] = 7;  assert(searcher.locationToNode(location) == 59);
	location[0] = 7; location[1] = 12; assert(searcher.locationToNode(location) == 103);
}

void SearcherTest::testNodeToLocationReturnsCorrectLocation(Searcher searcher) {
	assert(searcher.nodeToLocation(0)[0] == 0   && searcher.nodeToLocation(0)[1] == 0);
	assert(searcher.nodeToLocation(15)[0] == 1  && searcher.nodeToLocation(15)[1] == 2);
	assert(searcher.nodeToLocation(42)[0] == 3  && searcher.nodeToLocation(42)[1] == 3);
	assert(searcher.nodeToLocation(71)[0] == 5  && searcher.nodeToLocation(71)[1] == 6);
	assert(searcher.nodeToLocation(101)[0] == 7 && searcher.nodeToLocation(101)[1] == 10);
}

void SearcherTest::testInitializeSingleSourceSetsDistanceAndPathRight(Searcher searcher) {
	searcher.initializeSingleSource();
	int* path = searcher.getPath();
	int* distance = searcher.getDistance();
	int inf = infinity;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 13; col++) {
			int location[2] = {row, col};
			int node = searcher.locationToNode(location);
			assert(path[node] == -1);
			if (row == startLocation[0] && col == startLocation[1]) assert(distance[node] == 0);
			else assert(distance[node] == inf);
		}
	}
}
