/*
 * Path finding application.
 *
 * Uses a file operator to get the map from a file. Then finds the shortest
 * path between start position and end position using Dijkstra's algorithm.
 *
 * Author: kimpe
 */

#include "../headerFiles/Application.h"

Application::Application(char** argv) :
	mapFileName(argv[1]),
	fileOperator("data/" + mapFileName),
 	dijkstraSearcher( fileOperator.getSize(), fileOperator.getDataArray() ),
 	startLocation(new int[2]),
 	endLocation(new int[2]),
 	pathLength(new int[2]) {
		startLocation[0] = std::atoi(argv[2]);
		startLocation[1] = std::atoi(argv[3]);
		endLocation[0] = std::atoi(argv[4]);
		endLocation[1] = std::atoi(argv[5]);
}

void Application::run() {
	std::cout << "\nRunning the application. \n" << std::endl;
	dijkstraSearcher.initializeSingleSource(startLocation);
	dijkstraSearcher.heapInsertAll();
	dijkstraSearcher.search();
	std::cout << "Run complete." << std::endl;
}

void Application::visualize() {
	int* mapSize = fileOperator.getSize();
	int** mapData = fileOperator.getDataArray();
	drawMap(mapSize, mapData, false);
	determineShortestPath(mapSize, mapData);
	drawMap(mapSize, mapData, true);
	report();
}

void Application::drawMap(int* mapSize, int** mapData, bool containsPath) {
	if (containsPath) std::cout << "\nShortest path: \n"<< std::endl;
	else std::cout << "\nOriginal map: \n"<< std::endl;

	for (int row = 0; row < mapSize[0]; row++) {
		for (int col = 0; col < mapSize[1]; col++) {
			if (mapData[row][col] == -1) std::cout << "* ";
			else std::cout << mapData[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void Application::determineShortestPath(int* mapSize, int** mapData) {
	int* path = dijkstraSearcher.getPath();

	mapData[ endLocation[0] ][ endLocation[1] ] = -1;
	int startNode = dijkstraSearcher.locationToNode(startLocation);
	int node = dijkstraSearcher.locationToNode(endLocation);

	pathLength[0] = dijkstraSearcher.getDistance()[node];
	pathLength[1] = 0;

	while (node != startNode) {
		pathLength[1]++;
		node = path[node];
		int* location = dijkstraSearcher.nodeToLocation(node);
		mapData[ location[0] ][ location[1] ] = -1;
	}
}

void Application::report() {
	std::cout << "\nPath length is " << pathLength[0] << "\nwith "
			  << pathLength[1] << " steps.\n" << std::endl;
}
