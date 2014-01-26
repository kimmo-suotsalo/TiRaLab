/*
 * Node header file.
 *
 * Author: kimpe
 */

#include <limits>

#ifndef NODE_H_
#define NODE_H_

#define infinity std::numeric_limits<int>::max();

class Node {

public:

	/* Constructs a new node.
	 * Parameters: node id, shortest known distance from the start */
	Node(int, int);

	/* Constructs a new node while setting its distance to infinity. */
	Node(int);

	/* Returns the node id. */
	int getId();

	/* Returns the node distance. */
	int getDistance();

private:

	/* A non-negative integer that identifies the node. */
	int id;

	/* A non-negative integer that represents the minimum distance from
	 * the current node to the start. */
	int distance;
};

#endif /* NODE_H_ */
