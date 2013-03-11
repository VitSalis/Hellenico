#include <cstdio>

using namespace std;

int main() {
	freopen( "cubes.in", "r", stdin );
	freopen( "cubes.out", "w", stdout );
	int N, K;
	long long int sum = 0;
	scanf( "%d%d", &N, &K );
	int heights[ N ];
	int i;
	for ( i = 0; i < K; ++i ) {
		heights[ i ] = i;
	}
	heights[ K ] = K;
	for ( i = K + 1; i <= N; ++i ) {
		heights[ i ] = heights[ i - K ] + i;
	}

	for ( i = 0; i <= N; ++i ) {
		if ( heights[ i ] > N ) {
			printf( "%d\n", i - 1 );
			break;
		}
		else if ( heights[ i ] == N ) {
			printf( "%d\n", i );
			break;
		}
	}
	
	return 0;
}
