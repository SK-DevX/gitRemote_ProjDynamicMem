# -*- Makefile -*-

# target: dependancies
#	action

CC=gcc
CFLAGS=-o
OBJS=DynamicMemMultiplyBy5.o
SOURCE=DynamicMemMultiplyBy5.c

Output: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) Output

DynamicMemMultiplyBy5.o: $(SOURCE)
	$(CC) -c $(SOURCE)

clean:
	rm -f *.o Output

	
