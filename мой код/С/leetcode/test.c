#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 4



int main( void )
{

    int **x = malloc( M * sizeof( int * ) );
    for ( int i = 0; i < M; i++ )   
        x[i] = malloc( N * sizeof( int ) );



    for ( int i = 0; i < M; i++ )
    {
        for ( int j = 0; j < N; j++ ) x[i][j] = i * N + j + 1;
    }


    for ( int i = 0; i < M; i++ )
    {
        for ( int j = 0; j < N; j++ ) printf( "%d ", x[i][j] );
        printf( "\n" );
    }

}    