#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen( "acropolis.in", "r", stdin );
	freopen( "acropolis.out", "w", stdout );
	int N;
	scanf( "%d", &N );
	int A[ N ];
	int one[ N ];
	int array[ N ];
	int i, l = 0, maxl = 0, curr;

	for ( i = 0; i < N; ++i ) {
		scanf( "%d", &curr );
		if ( curr == 1 ) {
			one[ l ] = i;
			++l;
		}
		else {
			A[ i - l ] = curr;
		}
	}
	sort( A, A + i - l );
	l = 0;
	for ( i = 0; i < N; ++i ) {
		if ( i == one[ l ] ) {
			array[ i ] = 1;
			++l;
		}
		else {
			array[ i ] = A[ i - l ];
		}
	}
	for ( i = 0; i < N; ++i ) {
		printf( "%d\n", array[ i ] );
	}

	return 0;
}
