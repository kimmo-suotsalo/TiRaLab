/*
 * Application header file.
 *
 * Author: kimpe
 */

#include <string>
#include "../headerFiles/FileOperator.h"
#include "../headerFiles/Searcher.h"

#ifndef APPLICATION_H_
#define APPLICATION_H_

class Application {

public:

	/* Constructs a new application.
	 * Parameter: command line arguments. */
	Application(char**);

	/* Runs the application. */
	void run();

	/* Visualizes the original map and search results. */
	void visualize();

private:

	/* Name of the map file in the 'data' directory. */
	std::string mapFileName;

	/* A file operator to read the map data from a file. */
	FileOperator fileOperator;

	/* An object to perform the actual search. */
	Searcher searcher;

	/* Start location for the search in the form of (row, column). */
	int* startLocation;

	/* End location for the search in the form of (row, column). */
	int* endLocation;

	/* Length of the shortest path in the form of (distance, number of steps). */
	int* pathLength;

	/* Draws the original map or a modified map with the shortest path.
	 * Parameters: map size, map data, is this the original map. */
	void drawMap(int*, int**, bool);

	/* Marks the shortest path on the map array and computes its length.
	 * Parameters: map size, map data. */
	void determineShortestPath(int*, int**);

	/* Reports the length of the shortest path in distance and number of steps. */
	void report();
};

#endif /* APPLICATION_H_ */
