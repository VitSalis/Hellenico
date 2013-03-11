#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	FILE *fin = fopen( "maxkdiff.in", "r" );
	FILE *fout = fopen( "maxkdiff.out", "w" );
	int n, k;
	fscanf( fin, "%d%d", &n, &k );
	int i, j;
	long long int seq[ n ], diff[ k ];

	for ( i = 0; i < n; ++i ) {
		fscanf( fin, "%lld", seq + i );
	}
	int max = 0;
	for ( i = 0; i < n; ++i ) {
		int l = 0;
		for ( j = i; j < k + i; ++j ) {
			diff[ l ] = seq[ j ];
			++l;
		}
		sort( diff, diff + k );
		int count = 1;
		for ( l = 0; l < k - 1; ++l ) {
			if ( diff[ l ] != diff[ l + 1 ] ) {
				++count;
			}
		}
		if ( count > max ) {
			max = count;
		}
		if ( k + i >= n ) {
			break;
		}
	}
	fprintf( fout, "%d\n", max );

	return 0;
}
