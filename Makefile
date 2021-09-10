cc = cc
CFLAGS = -Wall

pgr: main.o
	$(cc) $(CFLAGS) -o pgr main.o -lncurses -g -O0
	
main.o: main.c
	$(cc) $(CFLAGS) -c main.c


clean:
	rm -f *.o pgr
