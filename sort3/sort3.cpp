#include <cstdio>

using namespace std;

void swap( int i, int j, int array[] ) {
    int temp = array[ i ];
    array[ i ] = array[ j ];
    array[ j ] = temp;
}

int find( int beg, int end, int num, int array[] ) {
    for ( int i = beg; i < end; ++i ) {
        if ( array[ i ] == num ) {
            return i;
        }
    }
    return -1;
}

int main() {
    freopen( "sort3.in", "r", stdin );
    freopen( "sort3.out", "w", stdout );
    int i, N;
    int one, two, three;
    one = two = three = 0;
    scanf( "%d", &N );
    int array[ N ];
    for ( i = 0; i < N; ++i ) {
        scanf( "%d", array + i );
        if ( array[ i ] == 1 ) {
            ++one;
        }
        if ( array[ i ] == 2 ) {
            ++two;
        }
        if ( array[ i ] == 3 ) {
            ++three;
        }
    }
    int pos, count = 0;
    for ( i = 0; i < one; ++i ) {
        if ( array[ i ] == 2 ) {
            pos = find( one, one + two, 1, array );
            if ( pos != -1 ) {
                swap( i, pos, array );
                ++count;
            }
        }
        else if ( array[ i ] == 3 ) {
            pos = find( one + two, N, 1, array ); 
            if ( pos != -1 ) {
                swap( i, pos, array );
                ++count;
            }
        }
        if ( array[ i ] != 1 && pos == -1 ) {
            pos = find( one, N, 1, array );
            swap( i, pos, array );
            ++count;
        }
        pos = 0;
    }
    for ( i = one; i < one + two; ++i ) {
        if ( array[ i ] == 3 ) {
            pos = find( one + two, N, 2, array );
            if ( pos != -1 ) {
                swap( i, pos, array );
                ++count;
            }
        }
        pos = 0;
    }
    printf( "%d\n", count );
    return 0;
}
