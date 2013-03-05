#include <cstdio>
#include <algorithm>

using namespace std;

struct obj {
    float m;
    float w;
};

bool operator <( obj a, obj b ) {
    float aa, bb;
    aa = a.m / a.w;
    bb = b.m / b.w;
    return aa > bb;
}

int main() {
    freopen( "stones.in", "r", stdin );
    freopen( "stones.out", "w", stdout );
    int N, S, i;
    scanf( "%d%d", &N, &S );
    obj stones[ N ];
    for ( i = 0; i < N; ++i ) {
        scanf( "%f%f", &stones[ i ].w, &stones[ i ].m );
    }
    sort( stones, stones + N );
    float sum = 0;
    for ( i = 0; i < N; ++i ) {
        if ( S >= stones[ i ].w ) {
            sum += stones[ i ].m;
            S -= stones[ i ].w;
        }
        else {
            sum += ( S ) * ( stones[ i ].m / stones[ i ].w );
            break;
        }
    }
    printf( "%0.3f\n", sum );
    return 0;
}
