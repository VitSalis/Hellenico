#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen( "crocodiles.in", "r", stdin );
    freopen( "crocodiles.out", "w", stdout );
    int N;
    scanf( "%d", &N );
    int birth[ N ], death[ N ];
    int min = 1000001, maxi = -1000001, i, count = 0, k, l, m = 0;
    for ( i = 0; i < N; ++i ) {
        scanf( "%d%d", birth + i, death + i );
        if ( birth[ i ] < min ) {
            min = birth[ i ];
        }
        if ( death[ i ] > maxi ) {
            maxi = death[ i ];
        }
    }
    sort( birth, birth + N );
    sort( death, death + N );
    for ( i = min, k = 0, l = 0; i <= maxi; ++i ) {
        while ( k < N && i == birth[ k ] ) {
            ++count;
            ++k;
        }
        while ( l < N && i == death[ l ] ) {
            --count;
            ++l;
        }
        if ( count > m ) {
            m = count;
        }
    }
    printf( "%d\n", m );
    return 0;
}
