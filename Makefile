CC=gcc

CFLAGS=-std=c99 -Wall -Wextra

make: queue.o stack.o
	$(CC) $(CFLAGS) main.c src/cgc.h src/queue/queue.o src/stack/stack.o -o cgc

queue.o: src/queue/queue.h src/queue/queue.c
	$(CC) -c $(CFLAGS) src/queue/queue.c -o src/queue/queue.o

stack.o: src/stack/stack.h src/stack/stack.c
	$(CC) -c $(CFLAGS) src/stack/stack.c -o src/stack/stack.o

test: test-queue test-stack
	test/test-queue/test-queue
	test/test-stack/test-stack

test-queue: src/queue/queue.o test/test-queue/test-queue.c
	$(CC) $(CFLAGS) test/test-queue/test-queue.c src/queue/queue.o -o test/test-queue/test-queue

test-stack: src/stack/stack.o test/test-stack/test-stack.c
	$(CC) $(CFLAGS) test/test-stack/test-stack.c src/stack/stack.o -o test/test-stack/test-stack

clean:
	rm -f cgc
	rm -f src/queue/queue.o
	rm -f src/stack/stack.o
	rm -f test/test-queue/test-queue
	rm -f test/test-stack/test-stack