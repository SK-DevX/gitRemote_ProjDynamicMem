# -*- Makefile -*-

# target: dependancies
#	action

#===========================================================================================

CC=gcc
CFLAGS=-o
OBJS=DynamicMemMultiplyBy5.o
SOURCE=DynamicMemMultiplyBy5.c DynamicMemMultiplyBy5.h
OUTPUT=Output
#===========================================================================================

TEST=tests
TEST_CFLAGS=-o
TEST_OBJS=myDynamicMemTest.o
TEST_SOURCE=tests/myDynamicMemTest.c tests/myDynamicMemTest.h
TEST_OUTPUT=testOutput
CRITERION=-lcriterion
#===========================================================================================

OUTPUT: $(OBJS) $(TEST_OBJS)
	$(CC) $(OBJS) $(TEST_OBJS) $(CFLAGS) OUTPUT $(CRITERION)
#Output: DynamicMemMultiplyBy5.o myDynamicMemTest.o
#	gcc DynamicMemMultiplyBy5.o myDynamicMemTest.o -o Output -lcriterion
#===========================================================================================

$(OBJS): $(SOURCE)
	$(CC) -c DynamicMemMultiplyBy5.c
#DynamicMemMultiplyBy5.o: DynamicMemMultiplyBy5.c DynamicMemMultiplyBy5.h
#	gcc -c DynamicMemMultiplyBy5.c DynamicMemMultiplyBy5.h
#===========================================================================================

$(TEST_OUTPUT): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(TEST_CFLAGS) TEST_OUTPUT $(CRITERION)
#testOutput: tests/myDynamicMemTest.o
#	gcc myDynamicMemTest.o -o testOutput -lcriterion
#===========================================================================================

$(TEST_OBJS): $(TEST_SOURCE)
	$(CC) -c tests/myDynamicMemTest.c
#myDynamicMemTest.o: myDynamicMemTest.c myDynamicMemTest.h
#	gcc -c tests/myDynamicMemTest.c tests/myDynamicMemTest.h
#===========================================================================================

clean:
	rm -f *.o *.gch OUTPUT TEST_OUTPUT
#===========================================================================================
	
