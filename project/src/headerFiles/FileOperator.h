/*
 * File operator header file.
 *
 * Author: kimpe
 */

#ifndef FILEOPERATOR_H_
#define FILEOPERATOR_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FileOperator {

public:
	/* Constructs a new file operator. Reads the map size and data using private functions.
	 * Parameter: file name.
	 */
	FileOperator(std::string fileName);

	/* Returns the size of the map data array (i.e. number of rows and columns). */
	int *getSize();

	/* Returns the map data array. */
	int **getDataArray();

private:
	/* An ordered pair of integers that determines the number of rows and columns in
	 * the map data array. */
	int *sizeOfDataArray;

	/* An array of integers that contains the map data. */
	int **dataArray;

	/* Opens an input stream. If the stream cannot be opened, displays an error message.
	 * Parameters: input stream to be opened, file name.
	 */
	void openStream(std::fstream &, std::string);

	/* Reads the size of a data array.
	 * Parameters: input stream to read from.
	 * Returns: size of data array.
	 */
	int *readSize(std::fstream &);

	/* Reads a map data array.
	 * Parameters: input stream to read from, map array size.
	 * Returns: data array.
	 */
	int **readDataArray(std::fstream &, int *);

	/* Closes an input stream. If the stream cannot be closed, displays an error message.
	 * Parameters: input stream to be closed, file name.
	 */
	void closeStream(std::fstream &, std::string);
};

#endif /* FILEOPERATOR_H_ */
