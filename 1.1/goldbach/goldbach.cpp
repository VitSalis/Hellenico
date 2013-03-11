#include <cstdio>

using namespace std;

int A[ 1000000 ];

int main() {
	FILE *fin = fopen( "goldbach.in", "r" );
	FILE *fout = fopen( "goldbach.out", "w" );
	int num;
	fscanf( fin, "%d", &num );
	int i, pos = 0, j;
	bool prime[ 1000001 ];
	for ( i = 0; i < 1000001; ++i ) {
		prime[ i ] = true;
	}
	for ( i = 2; i <= num; ++i ) {
		for ( j = 2 * i; j <= num; j += i ) {
			if ( j % i == 0 ) {
				prime[ j ] = false;
			}
		}
	}
	for ( i = 2, j = 0; i <= num; ++i ) {
		if ( prime[ i ] ) {
			A[ j ] = i;
			++j;
		}
	}
	printf( "%d\n", A[ 0 ] );

	for ( i = 0; i < j; ++i ) {
		if ( prime[ num - A[ i ] ] ) {
			fprintf( fout, "%d %d", A[ i ], num - A[ i ] );
			return 0;
		} 
	}
	return 0;
}
