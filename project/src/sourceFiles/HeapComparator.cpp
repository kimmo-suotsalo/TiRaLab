/*
 * Class for comparing two heap nodes by their keys.
 *
 * Author: kimpe
 */

#include "../headerFiles/HeapComparator.h"

bool HeapComparator::operator() (int* a, int* b) {
	return ( a[1] > b[1] );
}
