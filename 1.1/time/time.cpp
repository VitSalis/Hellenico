#include <cstdio>

using namespace std;

int main() {
	FILE *fin = fopen( "time.in", "r" );
	FILE *fout = fopen( "time.out", "w" );
	int h, m, s;
	fscanf( fin, "%d:%d:%d", &h, &m, &s );
	s = s * 2;
	m = m * 2;
	h = h * 2;

	if ( s >= 60 ) {
		++m;
		s -= 60;
	}
	if ( m >= 60 ) {
		++h;
		m -= 60;
	}

	int hour[ 2 ];
	hour[ 0 ] = h / 10;
	hour[ 1 ] = h % 10;
	int min[ 2 ];
	min[ 0 ] = m / 10;
	min[ 1 ] = m % 10;
	int sec[ 2 ];
	sec[ 0 ] = s / 10;
	sec[ 1 ] = s % 10;

	fprintf( fout, "%d%d:%d%d:%d%d\n", hour[ 0 ], hour[ 1 ], min[ 0 ], min[ 1 ], sec[ 0 ], sec[ 1 ] );

	return 0;
}
