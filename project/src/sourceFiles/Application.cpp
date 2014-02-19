/*
 * Path finding application.
 *
 * Uses a file operator to get the map from a file. Then finds the shortest
 * path between start position and end position using Dijkstra's algorithm or A*.
 *
 * Author: kimpe
 */

#include "../headerFiles/Application.h"

Application::Application(char** argv) :
	mapFileName(argv[3]), fileOperator("data/" + mapFileName), searcher( fileOperator.getSize(),
	fileOperator.getDataArray() ), startLocation(new int[2]), endLocation(new int[2]), pathLength(new int[2]) {
		startLocation[0] = std::atoi(argv[4]);
		startLocation[1] = std::atoi(argv[5]);
		endLocation[0] = std::atoi(argv[6]);
		endLocation[1] = std::atoi(argv[7]);
		if (argv[1][1] == 'd') searcher.setAlgorithm("Dijkstra's algorithm");
		else if (argv[1][1] == 'a') searcher.setAlgorithm("A*");
		if (argv[2][2] == 'n') searcher.setEchoMode("on");
		else if (argv[2][2] == 'f') searcher.setEchoMode("off");
		searcher.setStartNode(startLocation);
		searcher.setEndNode(endLocation);
}

void Application::run() {
	std::cout << "\nRunning the search using " << searcher.getAlgorithm()
			  << ". \n" << std::endl;
	searcher.initializeSingleSource();
	searcher.heapInsertAll();
	searcher.search();
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
	int* path = searcher.getPath();

	mapData[ endLocation[0] ][ endLocation[1] ] = -1;
	int startNode = searcher.locationToNode(startLocation);
	int node = searcher.locationToNode(endLocation);

	pathLength[0] = searcher.getDistance()[node];
	pathLength[1] = 0;

	while (node != startNode) {
		pathLength[1]++;
		node = path[node];
		int* location = searcher.nodeToLocation(node);
		mapData[ location[0] ][ location[1] ] = -1;
	}
}

void Application::report() {
	std::cout << "\nPath length is " << pathLength[0] << "\nwith "
			  << pathLength[1] << " steps.\n" << std::endl;
	std::cout << "Number of visited nodes is " << searcher.getNumberOfVisitedNodes()
			  << ".\n" << std::endl;
}
