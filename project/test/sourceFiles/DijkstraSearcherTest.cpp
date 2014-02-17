/*
 * Dijkstra searcher test class
 *
 * Author: kimpe
 */

#include "../headerFiles/DijkstraSearcherTest.h"

DijkstraSearcherTest::DijkstraSearcherTest() :
	mapSize(new int[2]),
	mapData(new int*[8]) {
		mapSize[0] = 8;
		mapSize[1] = 13;
		for (int row = 0; row < 8; row++) mapData[row] = new int[13];
	}

void DijkstraSearcherTest::run() {
	generateMapData();
	DijkstraSearcher dijkstraSearcher = DijkstraSearcher(mapSize, mapData);

	testLocationToNodeReturnsCorrectNode(dijkstraSearcher);
	testNodeToLocationReturnsCorrectLocation(dijkstraSearcher);
	testInitializeSingleSourceSetsDistanceAndPathRight(dijkstraSearcher);
	testSearchLeadsToCorrectSolution(dijkstraSearcher);
}

void DijkstraSearcherTest::generateMapData() {
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

void DijkstraSearcherTest::testLocationToNodeReturnsCorrectNode(DijkstraSearcher dijkstraSearcher) {
	int* location = new int[2];
	location[0] = 0; location[1] = 0;  assert(dijkstraSearcher.locationToNode(location) == 0);
	location[0] = 2; location[1] = 12; assert(dijkstraSearcher.locationToNode(location) == 38);
	location[0] = 3; location[1] = 0;  assert(dijkstraSearcher.locationToNode(location) == 39);
	location[0] = 4; location[1] = 7;  assert(dijkstraSearcher.locationToNode(location) == 59);
	location[0] = 7; location[1] = 12; assert(dijkstraSearcher.locationToNode(location) == 103);
}

void DijkstraSearcherTest::testNodeToLocationReturnsCorrectLocation(DijkstraSearcher dijkstraSearcher) {
	assert(dijkstraSearcher.nodeToLocation(0)[0] == 0   && dijkstraSearcher.nodeToLocation(0)[1] == 0);
	assert(dijkstraSearcher.nodeToLocation(15)[0] == 1  && dijkstraSearcher.nodeToLocation(15)[1] == 2);
	assert(dijkstraSearcher.nodeToLocation(42)[0] == 3  && dijkstraSearcher.nodeToLocation(42)[1] == 3);
	assert(dijkstraSearcher.nodeToLocation(71)[0] == 5  && dijkstraSearcher.nodeToLocation(71)[1] == 6);
	assert(dijkstraSearcher.nodeToLocation(101)[0] == 7 && dijkstraSearcher.nodeToLocation(101)[1] == 10);
}

void DijkstraSearcherTest::testInitializeSingleSourceSetsDistanceAndPathRight(DijkstraSearcher dijkstraSearcher) {
	int startLocation[2] = {0, 3};
	dijkstraSearcher.initializeSingleSource(startLocation);
	int* path = dijkstraSearcher.getPath();
	int* distance = dijkstraSearcher.getDistance();
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 13; col++) {
			int location[] = {row, col};
			int node = dijkstraSearcher.locationToNode(location);
			assert(path[node] == -1);
			if (row == startLocation[0] && col == startLocation[1]) assert(distance[node] == 0);
			else assert(distance[node] == 1000000);
		}
	}
}

void DijkstraSearcherTest::testSearchLeadsToCorrectSolution(DijkstraSearcher dijkstraSearcher) {
	dijkstraSearcher.heapInsertAll();
	dijkstraSearcher.search();
	int* path = dijkstraSearcher.getPath();
	int* distance = dijkstraSearcher.getDistance();
	assert(path[16] == 3  && distance[16] == 1);
	assert(path[20] == 19 && distance[20] == 5);
	assert(path[62] == 49 && distance[62] == 11);
	assert(path[69] == 70 && distance[69] == 18);
	assert(path[95] == 82 && distance[95] == 20);
}
