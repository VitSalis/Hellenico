#include <cstdio>

using namespace std;

int main() {
	FILE *fin = fopen( "cake.in", "r" );
	FILE *fout = fopen( "cake.out", "w" );
	int N, x;
	fscanf( fin, "%d%d", &N, &x );
	int i = 1;
	int count = 0;

	while ( i * x <= N ) {
		N -= i * x;
		i *= 2;
		++count;
	}
	fprintf( fout, "%d\n", count );

	return 0;
}
