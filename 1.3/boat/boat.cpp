#include <cstdio>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

void printString( string s ) {
	for ( int i = 0; i < s.length(); ++i ) {
		printf( "%c", s[ i ] );
	}
	printf( "\n" );
}

int main() {
	freopen( "boat.in", "r", stdin );
	freopen( "boat.out", "w", stdout );
	int N, in, out, end = -1, i, j;
	scanf( "%d", &N );
	string str[ 1000000 ];
	char s[ 43 ];
	for ( i = 0; i < N; ++i ) {
		scanf( "%d%d", &out, &in );
		for ( j = end - out + 1; j <= end - out + in; ++j ) {
			scanf( "%s", s );
			str[ j ] = s;
		}
		end = j - 1;
	}
	for ( i = 0; i <= end; ++i ) {
		int pos = i;
		for ( j = pos + 1; j <= end; ++j ) {
			int len = str[ j ].length();
			int len2 = str[ pos ].length();
			char s1[ 43 ];
			strcpy( s1, str[ j ].data() );
			char s2[ 43 ];
			strcpy( s2, str[ pos ].data() );
			if ( lexicographical_compare( s1, s1 + len, s2, s2 + len2 ) ) {
				pos = j;
			}
		}
		str[ i ].swap( str[ pos ] );
	}
	for ( i = 0; i <= end; ++i ) {
		printString( str[ i ] );
	}
	return 0;
}
