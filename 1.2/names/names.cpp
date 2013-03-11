#include <cstdio>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

void printString( string s ) {
	freopen( "names.out", "w", stdout );
	for ( int i = 0; i < s.length(); ++i ) {
		printf( "%c", s[ i ] );
	}
	printf( "\n" );
}

void change( string &s ) {
	char c = s[ s.length() - 1 ];
	for ( int i = s.length(); i > 0; --i ) {
		s[ i ] = s[ i - 1 ];
	}
	s[ 0 ] = c;
}

bool mycomp( char s1, char s2 ) {
	return tolower( s1 ) < tolower( s2 );
}

int main() {
	freopen( "names.in", "r", stdin );
	int N, i, j, k, l, found = 1;
	scanf( "%d", &N );
	string str[ N ];
	char s[ 21 ];

	for ( i = 0; i < N; ++i ) {
		scanf( "%s", s );
		str[ i ] = s;
	}

	for ( i = 0; i < N; ++i ) {
		for ( j = 0; j < str[ i ].length(); ++j ) {
			for ( k = 0; k < N; ++k ) {
				if ( found == 0 ) {
					break;
				}
				if ( found == 1 ) {
					if ( k + 1 == N ) {
						while ( j < str[ i ].length() ) {
							change( str[ i ] );
							++j;
						}
						printString( str[ i ] );
						return 0;
					}
				}
				found = 1;
				if ( k == i ) {
					continue;
				}
				for ( l = 0; l < str[ k ].length(); ++l ) {
					int len = str[ k ].length();
					int len2 = str[ i ].length();
					char s1[ 21 ];
					strcpy( s1, str[ k ].data() );
					char s2[ 21 ];
					strcpy( s2, str[ i ].data() );
					if ( lexicographical_compare( s1, s1 + len, s2, s2 + len2 ) ) {
						found = 0;
						break;
					}
					else {
						found = 1;
					}
					change( str[ k ] );
				}
				while ( l < str[ k ].length() ) {
					change( str[ k ] );
					++l;
				}
			}
			found = 1;
			change( str[ i ] );
		}
	}
}
