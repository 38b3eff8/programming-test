main.o: main.c node.o linklist.o
	gcc main.c linklist.o node.o -o main.o

linklist.o: linklist.h linklist.c
	gcc -c linklist.c -o linklist.o

node.o: node.h node.c
	gcc -c node.c -o node.o

clean:
	rm *.o
