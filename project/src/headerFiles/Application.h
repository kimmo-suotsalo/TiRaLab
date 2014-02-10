/*
 * Application header file.
 *
 * Author: kimpe
 */

#include "../headerFiles/FileOperator.h"
#include "../headerFiles/DijkstraSearcher.h"

#ifndef APPLICATION_H_
#define APPLICATION_H_

class Application {

public:

	/* Constructs a new application. */
	Application();

	/* Runs the application. */
	void run();

	/* Visualizes the original map and search results. */
	void visualize();

private:

	/* A file operator to read the map data from a file. */
	FileOperator fileOperator;

	/* An object to perform the actual search. */
	DijkstraSearcher dijkstraSearcher;

	/* Start location for the search in the form of (row, column). */
	int* startLocation;

	/* End location for the search in the form of (row, column). */
	int* endLocation;

	/* Draws the original map or a modified map with the shortest path.
	 * Parameters: map size, map data, is this the original map. */
	void drawMap(int*, int**, bool);

	/* Marks the shortest path on the map array.
	 * Parameters: map size, map data. */
	void markShortestPath(int*, int**);
};

#endif /* APPLICATION_H_ */
