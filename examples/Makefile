CC=gcc

CFLAGS= -Wall -Winline -I.. -I$(HOME)/code/check_utils/
CLINK= 

default: sr_test

sr_test: sr_test.c 
	$(CC) $(CFLAGS) -o $@ $^ $(CLINK)

indent:
	gnuindent *.c *.h

clean:
	rm -f *.o sr_test

bak-clean:
	rm -f *.bak *~ 

