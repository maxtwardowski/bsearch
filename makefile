all: bsearch

bsearch: bsearch.o
	gcc -g $^ -o $@ -lm -std="c99"

.c.o:
	gcc -g -std=c99 -c -D_REENTRANT $<

bsearch.o: bsearch.c

.PHONY: clean

clean:
	-rm bsearch bsearch.o

run:
	./bsearch
