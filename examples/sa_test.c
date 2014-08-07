
#include <stdlib.h>
#include <limits.h>

#include <simple_array.c>

int
main( int argc, char **argv )
{
    simple_array *sa;
    size_t i, len1, len2;
    int *d;

    if( argc < 2 ) {
        fprintf( stderr, "Usage: \n  %s LEN1 LEN2\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    len1 = atoi( argv[1] );
    len2 = atoi( argv[2] );

    sa = sa_alloc( len1, sizeof( int ) );
    fprintf( stdout, "Initial Allocation of %zd values (%zd bytes, sized %zd bytes for each)\n",
             len1, sa_data_memsize( sa ), sa_elsize( sa ) );

    d = ( int * ) sa_data( sa );
    for( i = 0; i < len1; i++ )
        d[i] = i;

    fprintf( stdout, "Re-sizing to at least %zd values (%zd bytes)\n", len2, len2 * sizeof( int ) );

    sa_ensure_length( sa, len2 );
    fprintf( stdout, "DONE! Should now hold %zd values (%zd bytes)\n",
             sa_elcount( sa ), sa_data_memsize( sa ) );
    d = ( int * ) sa_data( sa );

    fprintf( stdout, "Checking data... (only errors reported)\n" );

    for( i = 0; i < len1; i++ ) {
        if( d[i] != i ) {
            fprintf( stdout, "WRONG! d[%zd] = %zd\n", i, d[i] );
        }
    }
    for( i = len1; i < len2; i++ ) {
        if( d[i] != 0 ) {
            fprintf( stdout, "WRONG! d[%zd] = %zd\n", i, d[i] );
        }
    }

    sa_clean( sa );

    return EXIT_SUCCESS;
}
