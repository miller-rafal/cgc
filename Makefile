CC=gcc

CFLAGS=-std=c99 -Wall -Wextra

make: queue.o stack.o vector.o
	$(CC) $(CFLAGS) main.c src/cgc.h src/queue/queue.o src/stack/stack.o src/vector/vector.o -o cgc

queue.o: src/queue/queue.h src/queue/queue.c
	$(CC) -c $(CFLAGS) src/queue/queue.c -o src/queue/queue.o

stack.o: src/stack/stack.h src/stack/stack.c
	$(CC) -c $(CFLAGS) src/stack/stack.c -o src/stack/stack.o

vector.o: src/vector/vector.h src/vector/vector.c
	$(CC) -c $(CFLAGS) src/vector/vector.c -o src/vector/vector.o

test: test-queue test-stack test-vector
	test/test-queue/test-queue
	test/test-stack/test-stack
	test/test-vector/test-vector

test-queue: src/queue/queue.o test/test-queue/test-queue.c
	$(CC) $(CFLAGS) test/test-queue/test-queue.c src/queue/queue.o -o test/test-queue/test-queue

test-stack: src/stack/stack.o test/test-stack/test-stack.c
	$(CC) $(CFLAGS) test/test-stack/test-stack.c src/stack/stack.o -o test/test-stack/test-stack

test-vector: src/vector/vector.o test/test-vector/test-vector.c
	$(CC) $(CFLAGS) test/test-vector/test-vector.c src/vector/vector.o -o test/test-vector/test-vector

clean:
	rm -f cgc
	rm -f src/queue/queue.o
	rm -f src/stack/stack.o
	rm -f src/vector/vector.o
	rm -f test/test-queue/test-queue
	rm -f test/test-stack/test-stack
	rm -f test/test-vector/test-vector