/* The intention is a simple ascii / text file reader interface */

#include "check_fopen.c"

struct {
    char * filename;
    FILE * fp;
    size_t line_num;
    size_t buf_size;
    size_t col_min;
    char * buf;
} simple_reader;

/* constructors */
simple_reader *
sr_init(char * filename)
{
    simple_reader sr;

    sr.filename = filename;
    sr.fp = check_fopen(filename, "r");

    sr.line_num = 0;

    sr.buf_size = 1024;
    sr.col_min = 0;

    return &sr;
}

/* configuration and setting */
// sr_cols_min( simple_reader * sr, size_t n); // ensure at least n columns in line parsing.  Meaningless if not parsed
// sr_cols_max( simple_reader * sr, size_t n); // ensure at most n columns.  Error out if more.
// void sr_buf_size(simple_reader * sr, size_t n);     // buffer initialized to this many values.

/* line-by-line reading, minimal allocations */
char * line;
sr_readline(sr);    // NULL on EOF

/* so useage of while(inputfile_readline(infile)) { ... } */

char * line
sr_line(sr);        // output current buffered line

char ** words;
sr_parseline(sr);   // parses current buffered line based on col sep
		    // and parses ncols

/* destructors */
sr_free(infile);    // cleanup


