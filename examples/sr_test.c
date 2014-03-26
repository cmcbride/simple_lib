
#include <stdlib.h>
#include <limits.h>

#include <simple_reader.c>

int
main( int argc, char **argv )
{
    simple_reader *sr;
    char *line;
    int llen, lmin = INT_MAX, lmax = -1;

    if( argc < 2 ) {
        fprintf( stderr, "Usage: \n  %s  FILE  [MAX_LINE_LENGTH]\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    sr = sr_alloc( argv[1] );

    if( argc >= 3 ) {
        size_t maxlinelen;
        sscanf( argv[2], "%zd", &maxlinelen );
        sr_set_line_maxlen( sr, maxlinelen );
    }

    while( sr_readline( sr ) ) {
        line = sr_line( sr );
        llen = sr_linelen( sr );
        fprintf( stdout, "%d: %s\n", sr_linenum( sr ), line );
        if( llen < lmin )
            lmin = llen;
        if( llen > lmax )
            lmax = llen;
    }

    fprintf( stderr, "Read %d lines from file: %s\n", sr_linenum( sr ), sr_filename( sr ) );
    fprintf( stderr, "Line Lengths: min = %d ; max = %d\n", lmin, lmax );

    sr_clean( sr );

    return EXIT_SUCCESS;
}
