/*
 * Main program for testing and running the application.
 *
 * Comment out the line "#define NBDEBUG" to run the tests.
 *
 * Author: kimpe
 */

#define NDEBUG

#include "../headerFiles/Application.h"
#include "../../test/headerFiles/Test.h"

int main() {

	#ifdef NDEBUG
		Application shortestPath;
		shortestPath.run();
		shortestPath.visualize();
	#endif

	#ifndef NDEBUG
		Test masterTest;
		masterTest.run();
	#endif

}
