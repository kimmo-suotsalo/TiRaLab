/*
 * Node comparator header file.
 *
 * Author: kimpe
 */

#include "../headerFiles/Node.h"

#ifndef NODECOMPARATOR_H_
#define NODECOMPARATOR_H_

class NodeComparator {

public:

	/* Compares two nodes by their distances.
	 * Parameters: node a, node b.
	 * Returns: true if a's distance is greater than b's distance, otherwise false.
	 */
	bool operator() (Node, Node);

};

#endif /* NODECOMPARATOR_H_ */
