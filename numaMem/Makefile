CC=gcc
CFLAGS=-L/usr/lib/x86_64-linux-gnu -lnuma

alloc_on_particular_numa: alloc_on_particular_numa.c
	$(CC) -o alloc_on_particular_numa alloc_on_particular_numa.c $(CFLAGS)

.PHONY: clean

clean:
	rm -f alloc_on_particular_numafind
