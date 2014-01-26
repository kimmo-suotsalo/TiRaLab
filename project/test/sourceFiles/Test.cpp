/*
 * Main class for tests.
 *
 * Author: kimpe
 */

#include "../headerFiles/Test.h"
#include "../headerFiles/FileOperatorTest.h"

void Test::run() {
	std::cout << "Running the tests. \n" << std::endl;

	FileOperatorTest fileOperatorTest;
	fileOperatorTest.run();

	std::cout << "All tests passed." << std::endl;
}
