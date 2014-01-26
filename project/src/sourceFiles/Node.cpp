/*
 * Graph node class.
 *
 * A node corresponds to a single element in the map data array and has at most
 * four neighbors.
 *
 * Author: kimpe
 */

#include "../headerFiles/Node.h"

Node::Node(int nodeId, int nodeDistance) : id(nodeId), distance(nodeDistance) { }

Node::Node(int nodeId) : id(nodeId) {
	distance = infinity;
}

int Node::getId() {
	return id;
}

int Node::getDistance() {
	return distance;
}
