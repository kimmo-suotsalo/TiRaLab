/*
 * File operator test header file.
 *
 * Author: kimpe
 */

#ifndef FILEOPERATORTEST_H_
#define FILEOPERATORTEST_H_

#include <cassert>
#include <iostream>

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
