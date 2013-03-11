#include <cstdio>
#include "hiddenlib.h"

using namespace std;

int main() {
	int end = getN();
	int beg = 0;
	if ( end == 1 ) {
		if ( ishidden( 1 ) ) {
			return 0;
		}
	}
	while ( 1 ) {
		int mid = ( beg + end ) / 2;
		if ( compare( beg, end ) == 1 ) {
			end = mid;
		}
		else if ( compare( end, beg ) == 1 ) {
			beg = mid + 1;
		}
		else if ( compare( end, beg ) == 0 ) {
			if ( ishidden( mid ) ) {
				break;
			}
			if ( ishidden( mid + 1 ) ) {
				break;
			}
			if ( ishidden( mid - 1 ) ) {
				break;
			}
		}
	}

	return 0;
}
