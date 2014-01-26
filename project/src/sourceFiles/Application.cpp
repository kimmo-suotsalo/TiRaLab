/*
 * Path finding application.
 *
 * Uses a file operator to get the map from a file. (Then finds
 * the shortest path between start position and end position using
 * Dijkstra's algorithm and A*.)
 *
 * Author: kimpe
 */

#include "../headerFiles/Application.h"
#include "../headerFiles/DijkstraSearcher.h"
#include "../headerFiles/FileOperator.h"

Application::Application() {
	std::cout << "Running the application. \n" << std::endl;
}

void Application::run() {

	FileOperator fileOperator("data/map.txt");
	DijkstraSearcher dijkstraSearcher( fileOperator.getSize(), fileOperator.getDataArray() );
	dijkstraSearcher.initializeSingleSource();
	dijkstraSearcher.testHeap();

	std::cout << "Map array: \n"<< std::endl;
	for (int row = 0; row < fileOperator.getSize()[0]; row++) {
		for (int col = 0; col < fileOperator.getSize()[1]; col++) {
			std::cout << fileOperator.getDataArray()[row][col] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\nRun complete." << std::endl;
}
