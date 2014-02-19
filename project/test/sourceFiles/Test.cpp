/*
 * Main class for tests.
 *
 * Author: kimpe
 */

#include "../headerFiles/Test.h"

void Test::run() {
	std::cout << "Running the tests. \n" << std::endl;

	FileOperatorTest fileOperatorTest;
	fileOperatorTest.run();

	HeapTest heapTest;
	heapTest.run();

	SearcherTest searcherTest;
	searcherTest.run();

	std::cout << "All tests passed." << std::endl;
}
