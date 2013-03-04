SIMPLE_LIB 
==========
A few "library"-like interfaces to simplify and clean up common functionality 
in C codes. Mostly they work on an object like basis, where you create a structure
and then pass that C structure to all appropriate functions. 


GENERAL USAGE
-------------
The easiest way to use these in your code is simply to include them. 

For example: 

    #include <simple_reader.c> 

And then make sure to include the directory where the source code lives 
in the compilation (-I for gcc).

You can simply copy the respective files to your source code directory, and 
then pass the current directory to the compiler.  For example: 

    % gcc -I. ... 


DEPENDENCIES
------------
These make use of the "check_utils", which are available 
at: 
    https://github.com/cmcbride/check_utils


SIMPLE_READER
-------------
An interface to simplify ASCII file reading, especially on a line-by-line basis. 
These functions are all prefixed with "sr_" for "simple_reader".

This reads a file line-by-line, storing eaach in an internal buffer minimally 
allocated.  If the line is too long for the buffer, an error is reported and the 
processes is halted. 

See source for more details. 


SIMPLE_ARRAY
------------
An interface to handle 1-D arrays of arbitrary type, and easily enable resizing. 
These functions are all prefixed with "sa_" for "simple_array". 

See source for more details. 

TODO
----
Better documentation.


AUTHOR
------
Cameron McBride
December 2012 
cameron.mcbride@gmail.com

