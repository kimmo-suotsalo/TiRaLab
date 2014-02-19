/*
 * Main program for testing and running the application.
 *
 * Comment out the line "#define NDEBUG" to run the tests.
 *
 * Author: kimpe
 */

#define NDEBUG

#include "../headerFiles/Application.h"
#include "../../test/headerFiles/Test.h"

int main(int argc, char **argv) {

	#ifdef NDEBUG
		if (argc == 8) {
			Application shortestPathFinder(argv);
			shortestPathFinder.run();
			shortestPathFinder.visualize();
		} else {
			std::cerr << "\nUsage: runApplication -algorithm -echoMode mapFileName"
					  << "startX startY endX endY\n" << std::endl;
			exit(1);
		}
	#endif

	#ifndef NDEBUG
		Test masterTest;
		masterTest.run();
	#endif

}
