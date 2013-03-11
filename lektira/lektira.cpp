#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void trans( char* dest, char* source, int a, int b, int len ) {
    int i, k = 0;
    for ( i = a; i >= 0; --i ) {
        dest[ k++ ] = source[ i ];
    }
    for ( i = b; i > a; --i ) {
        dest[ k++ ] = source[ i ];
    }
    for ( i = len - 1; i > b; --i ) {
        dest[ k++ ] = source[ i ];
    }
    dest[ k ] = '\0';
}

void copy( char* dest, char* source ) {
    int i;
    for ( i = 0; source[ i - 1 ] != '\0'; ++i ) {
        dest[ i ] = source[ i ];
    }
}

int main() {
    freopen( "lektira.in", "r", stdin );
    freopen( "lektira.out", "w", stdout );
    char s[ 51 ], sol[ 51 ], rev[ 51 ];
    int i, j, len = 0;
    scanf( "%s", s );
    for ( i = 0; s[ i ] != '\0'; ++i ) {
        sol[ i ] = 'z';
        ++len;
    }
    for ( i = 0; s[ i + 2 ] != '\0'; ++i ) {
        for ( j = i + 1; s[ j + 1 ] != '\0'; ++j ) {
            trans( rev, s, i, j, len );
            if ( lexicographical_compare( rev, rev + len, sol, sol + len ) ) {
                copy( sol, rev );
            }
        }
    }
    printf( "%s\n", sol );
    return 0;
}
