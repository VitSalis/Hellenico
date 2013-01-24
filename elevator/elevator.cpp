#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen( "elevator.in", "r", stdin );
	freopen( "elevator.out", "w", stdout );
	int n;
	scanf( "%d", &n );
	int array[ n ];
	int i = 0;
	for ( i = 0; i < n; ++i ) {
		scanf( "%d", array + i );
	}
	sort( array, array + n );
	i = 0;
	int max = 0, count = 0;
	if ( n % 2 != 0 ) {
		--n;
		++count;
		if ( array[ n - 1 ] > max ) {
			max = array[ n ];
		}
	}
	while ( n > i ) {
		if ( array[ n - 1 ] + array[ i ] > max ) {
			max = array[ n - 1 ] + array[ i ];
		}
		--n;
		++i;
		++count;
	}
	printf( "%d %d\n", count, max );

	return 0;
}
