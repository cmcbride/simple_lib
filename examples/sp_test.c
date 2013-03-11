
#include <stdlib.h>
#include <limits.h>

#include <simple_param.c>

int
main( int argc, char **argv )
{
    simple_param *sp;

    int i, ti, tai[4];
    unsigned int tu, tau[4];
    float tf, taf[3];
    double td, tad[3];
    char c, str[100];

    if( argc < 2 ) {
        fprintf( stderr, "Usage:  %s  PARAM_FILE\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    sp = sp_init( 10 );
    sp_add_char( sp, "char", &c, NULL );
    sp_add_sint( sp, "sint", &ti, NULL );
    sp_add_uint( sp, "uint", &tu, NULL );
    sp_add_float( sp, "float", &tf, NULL );
    sp_add_double( sp, "double", &td, NULL );

    sp_add_string( sp, "string", str, sizeof( str ), NULL );

    sp_add_array_sint( sp, "array_sint", tai, 4, NULL );
    sp_add_array_uint( sp, "array_uint", tau, 4, NULL );
    sp_add_array_float( sp, "array_float", taf, 3, NULL );
    sp_add_array_double( sp, "array_double", tad, 3, NULL );

    fprintf( stderr, "Parsing file: '%s'\n", argv[1] );
    sp_set_defaults( sp );
    sp_parse_file( sp, argv[1] );
    sp_check_required( sp );

    sp_kill( sp );

    fprintf( stdout, "RESULTS:\n" );
    fprintf( stdout, " char:   %c\n", c );
    fprintf( stdout, " sint:   %d\n", ti );
    fprintf( stdout, " uint:   %u\n", tu );
    fprintf( stdout, " float:  %g\n", tf );
    fprintf( stdout, " double: %g\n", td );
    fprintf( stdout, " string: '%s'\n", str );
    fprintf( stdout, " array_sint:  " );
    for( i = 0; i < 4; i++ )
        fprintf( stdout, " %d", tai[i] );
    fprintf( stdout, "\n" );
    fprintf( stdout, " array_uint:  " );
    for( i = 0; i < 4; i++ )
        fprintf( stdout, " %u", tau[i] );
    fprintf( stdout, "\n" );
    fprintf( stdout, " array_float: " );
    for( i = 0; i < 3; i++ )
        fprintf( stdout, " %g", taf[i] );
    fprintf( stdout, "\n" );
    fprintf( stdout, " array_double:" );
    for( i = 0; i < 3; i++ )
        fprintf( stdout, " %g", tad[i] );
    fprintf( stdout, "\n" );

    return EXIT_SUCCESS;
}
