/*
 * File operator test class.
 *
 * Author: kimpe
 */

#include "../headerFiles/FileOperatorTest.h"
#include "../../src/headerFiles/FileOperator.h"

FileOperatorTest::FileOperatorTest() {
	FileOperator fileOperator("data/map.txt");
	sizeOfDataArray = fileOperator.getSize();
	dataArray = fileOperator.getDataArray();
}

void FileOperatorTest::run() {
	testArraySize();
	testArrayData();
}

void FileOperatorTest::testArraySize() {
	assert(sizeOfDataArray[0] == 8);
	assert(sizeOfDataArray[1] == 13);
}

void FileOperatorTest::testArrayData() {
	for (int row = 0; row < sizeOfDataArray[0]; row++) {
		for (int col = 0; col < sizeOfDataArray[1]; col++) {
			if (0 <= col && col <= 2) assert(dataArray[row][col] == 0);
			else if (row == 1) {
				if (3 <= col && col <= 7) assert(dataArray[row][col] == 1);
			}
			else if (row == 5) {
				if (4 <= col && col <= 10) assert(dataArray[row][col] == 1);
			}
			else if (11 <= col && col <= 12) assert(dataArray[row][col] == 0);
		}
	}
}
