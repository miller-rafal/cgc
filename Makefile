CC=gcc

CFLAGS=-std=c99 -Wall -Wextra

make: queue.o stack.o list.o
	$(CC) $(CFLAGS) main.c src/cgc.h src/queue/queue.o src/stack/stack.o src/list/list.o -o cgc

queue.o: src/queue/queue.h src/queue/queue.c
	$(CC) -c $(CFLAGS) src/queue/queue.c -o src/queue/queue.o

stack.o: src/stack/stack.h src/stack/stack.c
	$(CC) -c $(CFLAGS) src/stack/stack.c -o src/stack/stack.o

list.o: src/list/list.h src/list/list.c
	$(CC) -c $(CFLAGS) src/list/list.c -o src/list/list.o

clean:
	rm cgc
	rm src/queue/queue.o
	rm src/stack/stack.o
	rm src/list/list.o