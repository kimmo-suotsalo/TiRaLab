/*
 * Main class for tests.
 *
 * Author: kimpe
 */

#include "../headerFiles/Test.h"
#include "../headerFiles/FileOperatorTest.h"
#include "../headerFiles/HeapTest.h"

void Test::run() {
	std::cout << "Running the tests. \n" << std::endl;

	FileOperatorTest fileOperatorTest;
	fileOperatorTest.run();

	HeapTest heapTest;
	heapTest.run();

	std::cout << "All tests passed." << std::endl;
}
