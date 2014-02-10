/*
 * Path finding application.
 *
 * Uses a file operator to get the map from a file. Then finds the shortest
 * path between start position and end position using Dijkstra's algorithm.
 *
 * Author: kimpe
 */

#include "../headerFiles/Application.h"

Application::Application() :
	fileOperator("data/map.txt"),
 	dijkstraSearcher( fileOperator.getSize(), fileOperator.getDataArray() ),
 	startLocation(new int[2]),
 	endLocation(new int[2]) { }

void Application::run() {
	std::cout << "Running the application. \n" << std::endl;

	startLocation[0] = 0;
	startLocation[1] = 3;
	endLocation[0] = 7;
	endLocation[1] = 4;

	dijkstraSearcher.initializeSingleSource(startLocation);
	dijkstraSearcher.heapInsertAll();
	dijkstraSearcher.search();

	std::cout << "Run complete." << std::endl;
}

void Application::visualize() {
	int* mapSize = fileOperator.getSize();
	int** mapData = fileOperator.getDataArray();
	drawMap(mapSize, mapData, true);
	markShortestPath(mapSize, mapData);
	drawMap(mapSize, mapData, false);
}

void Application::drawMap(int* mapSize, int** mapData, bool isOriginal) {
	if (isOriginal) std::cout << "\nOriginal map: \n"<< std::endl;
	else std::cout << "\nShortest path: \n"<< std::endl;

	for (int row = 0; row < mapSize[0]; row++) {
		for (int col = 0; col < mapSize[1]; col++) {
			if (mapData[row][col] < 0) std::cout << "* ";
			else std::cout << mapData[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void Application::markShortestPath(int* mapSize, int** mapData) {
	int* path = dijkstraSearcher.getPath();

	mapData[ endLocation[0] ][ endLocation[1] ] = -1;
	int startNode = dijkstraSearcher.locationToNode(startLocation);
	int node = dijkstraSearcher.locationToNode(endLocation);

	while (node != startNode) {
		node = path[node];
		int* location = dijkstraSearcher.nodeToLocation(node);
		mapData[ location[0] ][ location[1] ] = -1;
	}
}
