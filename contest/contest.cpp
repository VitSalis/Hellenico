#include <cstdio>
#include <vector>

using namespace std;

struct edge {
    int v;
    int w;
};

int m = 0;

void dfs( vector< edge > graph[], bool visited[], int dp[], int s ) {
    int i;
    bool pushed = false;
    visited[ s ] = true;
    for ( i = 0; i < graph[ s ].size(); ++i ) {
        edge p = graph[ s ][ i ];
        if ( !visited[ p.v ] ) {
            dp[ p.v ] = dp[ s ] + p.w;
            dfs( graph, visited, dp, p.v );
            pushed = true;
        }
    }
    if ( !pushed ) {
        if ( dp[ s ] > m ) {
            m = dp[ s ];
        }
    }
}

int main() {
    freopen( "contest.in", "r", stdin );
    freopen( "contest.out", "w", stdout );
    int N, i;
    scanf( "%d", &N );
    int u, v, w;
    vector< edge > graph[ N + 1 ];
    bool visited[ N + 1 ];
    int dp[ N + 1 ];

    for ( i = 0; i <= N; ++i ) {
        visited[ i ] = false;
        dp[ i ] = 0;
    }

    for ( i = 0; i < N - 1; ++i ) {
        scanf( "%d%d%d", &u, &v, &w );
        graph[ u ].push_back( ( edge ) { v, w } );
    }
    dfs( graph, visited, dp, 1 );
    printf( "%d\n", m );
    return 0;
}
