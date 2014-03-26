CC=cc

CFLAGS= -Wall -Winline -I.. -I$(HOME)/code/check_utils/
CLINK= 

default: sr_test sp_test

sr_test: sr_test.c 
	$(CC) $(CFLAGS) -o $@ $^ $(CLINK)

sp_test: sp_test.c 
	$(CC) $(CFLAGS) -o $@ $^ $(CLINK)

indent:
	gnuindent *.c *.h

clean:
	rm -f *.o sr_test sp_test

bak-clean:
	rm -f *.bak *~ 

