CC=cc

CFLAGS= -Wall -Winline -I.. -I$(HOME)/code/check_utils/
CLINK= 

default: sa_test sp_test sr_test

sa_test: sa_test.c 
	$(CC) $(CFLAGS) -o $@ $^ $(CLINK)

sp_test: sp_test.c 
	$(CC) $(CFLAGS) -o $@ $^ $(CLINK)

sr_test: sr_test.c 
	$(CC) $(CFLAGS) -o $@ $^ $(CLINK)


indent:
	gnuindent *.c *.h

clean:
	rm -f *.o sa_test sp_test sr_test

bak-clean:
	rm -f *.bak *~ 

