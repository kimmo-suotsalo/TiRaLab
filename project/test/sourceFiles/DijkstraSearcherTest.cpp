/*
 * Dijkstra searcher test class
 *
 * Author: kimpe
 */

#include "../headerFiles/DijkstraSearcherTest.h"

void DijkstraSearcherTest::run() {

	int mapSize[] = {8, 13};
	int** mapData = new int*[ mapSize[0] ];

	int mapRow0[] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; mapData[0] = mapRow0;
	int mapRow1[] = {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}; mapData[1] = mapRow1;
	int mapRow2[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}; mapData[2] = mapRow2;
	int mapRow3[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0}; mapData[3] = mapRow3;
	int mapRow4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}; mapData[4] = mapRow4;
	int mapRow5[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0}; mapData[5] = mapRow5;
	int mapRow6[] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}; mapData[6] = mapRow6;
	int mapRow7[] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}; mapData[7] = mapRow7;

	DijkstraSearcher dijkstraSearcher = DijkstraSearcher(mapSize, mapData);
	testLocationToNodeReturnsCorrectNode(dijkstraSearcher);
	testNodeToLocationReturnsCorrectLocation(dijkstraSearcher);
	testInitializeSingleSourceSetsDistanceAndPathRight(dijkstraSearcher);
	testSearchLeadsToCorrectSolution(dijkstraSearcher);
}

void DijkstraSearcherTest::testLocationToNodeReturnsCorrectNode(DijkstraSearcher dijkstraSearcher) {
	int location0[] = {0, 0};  assert(dijkstraSearcher.locationToNode(location0) == 0);
	int location1[] = {2, 12}; assert(dijkstraSearcher.locationToNode(location1) == 38);
	int location2[] = {3, 0};  assert(dijkstraSearcher.locationToNode(location2) == 39);
	int location3[] = {4, 7};  assert(dijkstraSearcher.locationToNode(location3) == 59);
	int location4[] = {7, 12}; assert(dijkstraSearcher.locationToNode(location4) == 103);
}

void DijkstraSearcherTest::testNodeToLocationReturnsCorrectLocation(DijkstraSearcher dijkstraSearcher) {
	assert(dijkstraSearcher.nodeToLocation(0)[0] == 0   && dijkstraSearcher.nodeToLocation(0)[1] == 0);
	assert(dijkstraSearcher.nodeToLocation(15)[0] == 1  && dijkstraSearcher.nodeToLocation(15)[1] == 2);
	assert(dijkstraSearcher.nodeToLocation(42)[0] == 3  && dijkstraSearcher.nodeToLocation(42)[1] == 3);
	assert(dijkstraSearcher.nodeToLocation(71)[0] == 5  && dijkstraSearcher.nodeToLocation(71)[1] == 6);
	assert(dijkstraSearcher.nodeToLocation(101)[0] == 7 && dijkstraSearcher.nodeToLocation(101)[1] == 10);
}

void DijkstraSearcherTest::testInitializeSingleSourceSetsDistanceAndPathRight(DijkstraSearcher dijkstraSearcher) {
	int startLocation[] = {0, 3};
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
