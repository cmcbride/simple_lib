This is a quick description for what will be an INPUT_FILE utility (which might graduate into a full library like interface). 

Make an interface: 

possible names: simple_reader.h

/* constructors */
simple_reader *sr; 
infile = sr_init(char * filename);

/* configuration and setting */
sr_cols_min(sr, size_t n); // ensure at least n columns in line parsing.  Meaningless if not parsed
sr_cols_max(sr, size_t n); // ensure at most n columns.  Error out if more. 
sr_buf_size(size_t n);     // buffer initialized to this many values. 

/* line-by-line reading, minimal allocations */
char * line; 
sr_readline(sr);    // NULL on EOF

/* so useage of while(inputfile_readline(infile)) { ... } 

char * line 
sr_line(sr);        // output current buffered line

char ** words;
sr_parseline(sr);   // parses current buffered line based on col sep
		    // and parses ncols

/* destructors */
sr_free(infile);    // cleanup


/**************************/
DATA_READER 

data_reader = 
dr_init(infile, ncol_want);

/* defaults to first NCOLS, all of type double - change with: */
dr_set(dr, ncol_index, ncol_type);

size_t nitems 
dr_readfile(dr);

void * 
dr_get(dr, ncol_index); 

void 
dr_clean(dr); // destroys DR structure, but keeps parsed arrays.

void 
dr_kill(dr);  // destroys DR structure AND any allocated data.  It's a full clean. 
