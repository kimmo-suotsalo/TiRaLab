/*
 * File operator class.
 *
 * Implements functions for opening and closing a file and
 * getting the map data array and its size.
 *
 * Author: kimpe
 */

#include "../headerFiles/FileOperator.h"

FileOperator::FileOperator(std::string fileName) {
	std::fstream dataStream;
	openStream(dataStream, fileName);
	sizeOfDataArray = readSize(dataStream);
	dataArray = readDataArray( dataStream, getSize() );
	closeStream(dataStream, fileName);
}

int* FileOperator::getSize() {
	return sizeOfDataArray;
}

int** FileOperator::getDataArray() {
	return dataArray;
}

void FileOperator::openStream(std::fstream &inputStream, std::string dataFileName) {
	inputStream.open( dataFileName.data() );
	if ( !inputStream.is_open() ) {
		std::cerr << "File " << dataFileName << " could not be opened." << std::endl;
		exit(1);
	}
}

int* FileOperator::readSize(std::fstream &inputStream) {
	int *size = new int[2];
	inputStream >> size[0];
	inputStream >> size[1];
	return size;
}

int** FileOperator::readDataArray(std::fstream &inputStream, int *size) {
	int nRows = size[0];
	int nCols = size[1];
	int **dataArray = new int*[nRows];
	std::string inputLine;
	int row = 0;
	while (inputStream >> inputLine) {
		dataArray[row] = new int[nCols];
		for (int col = 0; col < nCols; col++) {
			std::istringstream( inputLine.substr(col, 1) ) >> dataArray[row][col];
		}
		row++;
	}
	return dataArray;
}

void FileOperator::closeStream(std::fstream &inputStream, std::string dataFileName) {
	inputStream.close();
	if ( inputStream.is_open() ) {
		std::cerr << "File " << dataFileName << " could not be closed." << std::endl;
		exit(1);
	}
}
