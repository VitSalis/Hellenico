#include <cstdio>

using namespace std;

int main() {
	FILE *fin = fopen ( "tickets.in", "r" );
	FILE *fout = fopen ( "tickets.out", "w" );
	int n = 0, A, B, C, D, money = 0, check;

	fscanf( fin, " %d %d %d %d %d ", &n, &A, &B, &C, &D );

	if ( n < A ) {
		money = 10 * n;
		check = 9 * A;
		if ( check < money ) {
			money = check;
		}
		check = 8 * B;
		if( check < money ) {
			money = check;
		}
		check = 7 * C;
		if ( check < money ) {
			money = check;
		}
		check = 5 * D;
		if ( check < money ) {
			money = check;
		}
	}
	if ( n >= A && n < B ) {
		money = 9 * n;
		check = 8 * B;

		if ( check < money ) {
			money = check;
		}
		check = 7 * C;
		if ( check < money ) {
			money = check;
		}
		check = 5 * D;
		if ( check < money ) {
			money = check;
		}
	}
	if ( n >= B && n < C ) {
		money = 8 * n;
		check = 7 * C;

		if ( check < money ) {
			money = check;
		}
		check = 5 * D;
		if ( check < money ) {
			money = check;
		}
	}
	if( n >= C && n < D ) {
		money = 7 * n;
		check = 5 * D;

		if ( check < money ) {
			money = check;
		}
	}
	if ( n > D ) {
		money = 5 * n;
	}

	fprintf( fout, "%d", money );

	return 0;
}

