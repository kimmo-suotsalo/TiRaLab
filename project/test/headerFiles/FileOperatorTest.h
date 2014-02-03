/*
 * File operator test header file.
 *
 * Author: kimpe
 */

#include <cassert>
#include <iostream>
#include "../../src/headerFiles/FileOperator.h"

#ifndef FILEOPERATORTEST_H_
#define FILEOPERATORTEST_H_

class FileOperatorTest {

public:
	FileOperatorTest();
	void run();
private:
	int *sizeOfDataArray;
	int **dataArray;
	void testArraySize();
	void testArrayData();
};

#endif /* FILEOPERATORTEST_H_ */
