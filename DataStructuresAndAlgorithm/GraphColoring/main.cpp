// ???

#include <iostream>

#define MAX_SIZE 32

bool isSafe( int node, int color[], bool graph[MAX_SIZE][MAX_SIZE], int n, int col ) {
    for ( int k = 0; k < n; k++ ) {
        if ( k != node && graph[k][node] == 1 && color[k] == col ) {
            return false;
        }
    }
    return true;
}
bool solve( int node, int color[], int m, int N, bool graph[MAX_SIZE][MAX_SIZE] ) {
    if ( node == N ) {
        return true;
    }

    for ( int i = 1; i <= m; i++ ) {
        if ( isSafe( node, color, graph, N, i ) ) {
            color[node] = i;
            if ( solve( node + 1, color, m, N, graph ) ) return true;
            color[node] = 0;
        }

    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring( bool graph[MAX_SIZE][MAX_SIZE], int m, int N ) {
    int color[MAX_SIZE] = { 0 };
    if ( solve( 0, color, m, N, graph ) )
        return true;
    return false;
}

int main() {

    int N = 4;
    int m = 3;

    bool graph[MAX_SIZE][MAX_SIZE] = {
      (0, 1),
      (1, 2),
      (2, 3),
      (3, 0),
      (0, 2)
    };

    std::cout << graphColoring( graph, m, N );

    system( "pause" );
    return 0;
}