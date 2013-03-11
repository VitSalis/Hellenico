#include <cstdio>
#include <algorithm>

using namespace std;

int length( char* s ) {
    int count = 0;
    for ( int i = 0; s[ i ] != 0; ++i, ++count );
    return count;
}

int fmax( int a, int b, int c, int d ) {
    if ( a >= b && a >= c && a >= d ) {
        return b + c + d;
    }
    if ( b >= a && b >= c && b >= d ) {
        return a + c + d;
    }
    if ( c >= a && c >= b && c >= d ) {
        return a + b + d;
    }
    if ( d >= a && d >= b && d >= c ) {
        return a + b + c;
    }
}

int find( int num, char A, char C, char G, char T, char* s, int beg ) {
    int i;
    int a, c, g, t;
    int len = length( s );
    a = c = g = t = 0;
    for ( i = beg; i < len; i += num ) {
        if ( s[ i ] == A ) {
            ++a;
        }
        else if ( s[ i ] == C ) {
            ++c;
        }
        else if ( s[ i ] == G ) {
            ++g;
        }
        else if ( s[ i ] == T ) {
            ++t;
        }
    }
    return fmax( a, g, c, t );
}

int main() {
    freopen( "dna.in", "r", stdin );
    freopen( "dna.out", "w", stdout );
    int N, K;
    scanf( "%d%d", &N, &K );
    char s[ N ];
    scanf( "%s", s );
    int i, j;
    int count = 0, m = 100000000;
    char a = 'A';
    char c = 'C';
    char g = 'G';
    char t = 'T';
    int beg;
    for ( i = 1; i <= K; ++i ) {
        count = 0;
        beg = 0;
        for ( j = 1; j <= i; ++j ) {
            count += find( i, a, c, g, t, s, beg ); 
            ++beg;
        }
        if ( count < m ) {
            m = count;
        }
    }
    printf( "%d\n", m );

    return 0;
}
