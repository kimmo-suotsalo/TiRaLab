/*
 * Class for comparing two nodes by their distances.
 *
 * Author: kimpe
 */

#include "../headerFiles/Node.h"
#include "../headerFiles/NodeComparator.h"

bool NodeComparator::operator() (Node a, Node b) {
	return ( a.getDistance() > b.getDistance() );
}
